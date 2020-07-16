// WinMacroDialog2.cpp : implementation file

// This file contains code for the UI
// The dialog itself, action handlers.etc

#include <afxwin.h>
#include <afxdlgs.h>
#include <afxtempl.h>
#include <ios>
#include "hooks.h"

#include "resource.h"
#include "WinMacroDialog2.h"
#include "AboutDialog.h"
#include "OptionsDialog.h"

extern HINSTANCE hinstance;
extern HHOOK hook_handle;

extern std::fstream *output;
extern std::fstream *input;
extern DWORD start_time;

extern CList <EVENTMSG,EVENTMSG> *message_list;

HWND thiswindow_hwnd;
BOOL playing_back;
WinMacroDialog2 * dialog_ptr;

BOOL recording;

char signature[]="SADHU";
int signature_length=sizeof(signature);

using namespace std;

/////////////////////////////////////////////////////////////////////////////
// WinMacroDialog2 dialog


WinMacroDialog2::WinMacroDialog2(CWnd* pParent /*=NULL*/)
	: CDialog(WinMacroDialog2::IDD, pParent)
{
	//Setup bool variable to indicate that when start recording is pressed, it indicates
	//system is recording.
	recording=FALSE;

	dialog_ptr=this;

}


void WinMacroDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(WinMacroDialog2)
	DDX_Control(pDX, IDC_OPTIONS, m_options_button);
	DDX_Control(pDX, IDC_BROWSE, m_browse_button);
	DDX_Control(pDX, IDC_FILENAME, m_filename);
	DDX_Control(pDX, IDC_PLAYBACK, m_playback_button);
	DDX_Control(pDX, IDC_RECORD, m_record_button);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(WinMacroDialog2, CDialog)
	//{{AFX_MSG_MAP(WinMacroDialog2)
	ON_BN_CLICKED(IDC_RECORD, OnRecord_Click)
	ON_BN_CLICKED(IDC_PLAYBACK, OnPlayback_Click)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse_Click)
	ON_BN_CLICKED(IDC_ABOUT, OnAbout_Click)
	ON_BN_CLICKED(IDC_OPTIONS, OnOptions_Click)
	//}}AFX_MSG_MAP
	
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// WinMacroDialog2 message handlers

BOOL WinMacroDialog2::OnInitDialog() 
{
	//Perform basic initialization in this function

	CDialog::OnInitDialog();
	
	//Load application icon
	HICON icon= LoadIcon(hinstance,MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(icon,TRUE);

	//Create Statusbar with only one panel
	statusbar.Create(WS_CHILD|WS_VISIBLE|CCS_BOTTOM,CRect(0,0,100,10),this,123);
	statusbar.SetSimple(FALSE);   
	int widtharray[1]={400};
	statusbar.SetParts(1,widtharray);

	statusbar.SetText("Ready to record",0,0);
	
	//Set the global HWND to current window. Doesn't seem to work now though :(
	thiswindow_hwnd=this->m_hWnd;

	if( m_initialPath.GetLength() > 0) {
		m_filename.SetWindowText( m_initialPath);
		StartPlayback();
		return TRUE;
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void WinMacroDialog2::OnRecord_Click() 
{
	CString record_filename;

	//This prevents recording to start again, when this button is clicked during playback either
	//accidentally or intentionally. If this were not here, recording would begin again at 
	//the end of playback, automatically. 
	//This is because the click on the button is also recorded to the file, even if it's on 
	//the disabled button. During playback, the "Record" button is enabled, 
	//so the click will register and WinMacro would start recording again.
	if (playing_back) return;
	
	//Get pointer to button, so that we can enable/disable the Start Recording button
	
	
	//Initialize start_time so that we can record delays between messages
	start_time=GetTickCount();
	
		
   output=new std::fstream();
	
	//If file to record is okay
	if (CheckFileName(&m_filename,output,ios::binary|ios::out,"Please enter a valid filename to record to."))
	{
		
		m_filename.GetWindowText(record_filename);
		
		//Disable everything 
		m_filename.EnableWindow(FALSE);
		m_browse_button.EnableWindow(FALSE);
		m_playback_button.EnableWindow(FALSE);
		m_options_button.EnableWindow(FALSE);
		
		//Disable button
		m_record_button.EnableWindow(FALSE);
		
		//Display the tip
		
		
		//Change status to recording
		statusbar.SetText("Recording to "+record_filename+". "+"Press Pause/Break to Stop Recording.",0,0);
		
		//Write out our signature first
		output->write(signature,sizeof(signature));
		
		//Finally install journal hook for recording
		hook_handle=SetWindowsHookEx(WH_JOURNALRECORD,JournalRecordProc,hinstance,0);
		
		//Change flag variable to indicate we are now recording	
		recording=!recording;

		// MODIFY BY JIMBO
		if( hook_handle==NULL){
			LPVOID lpMsgBuf;
			FormatMessage(
				FORMAT_MESSAGE_ALLOCATE_BUFFER |
				FORMAT_MESSAGE_FROM_SYSTEM |
				FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL,
				GetLastError(),
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
				(LPTSTR) &lpMsgBuf,
				0,
				NULL
			);
			MessageBox( (LPCTSTR)lpMsgBuf, "Hook Server Error", MB_OK | MB_ICONINFORMATION );
			StopRecording();
		}
	}
	
	

}

void WinMacroDialog2::ShowFileDialog (CEdit *textbox)
{
	/**************************
	Utility function that encapsulates showing the open file dialog box
	and filling the supplied CEdit with the selected filename
	***************************/

	CFileDialog file_dialog(TRUE,"winmacro.log");
	
	//If user has not pressed cancel
	if (file_dialog.DoModal()==IDOK)
	{
		textbox->SetWindowText(file_dialog.GetPathName());
	}
}

BOOL WinMacroDialog2::CheckFileName(CEdit *filename_field,fstream *stream, int mode,CString error_mesg)
{
	/*************************
	Utility function that checks whether filename_field contains a valid filename.
	If so, tries opening stream in mode passed as parameter.
	If any of these fail, the error_mesg supplied is displayed and the function
	returns false
	*************************/
	CString filename;
	filename_field->GetWindowText(filename);
	filename.TrimLeft(); filename.TrimRight();
	if (filename.IsEmpty())
	{
			MessageBox(error_mesg,"Error");
			return FALSE;
	}

		
	//If everything ok, open file 
	stream->open(filename,mode);
	if (stream->fail())
	{
		MessageBox(error_mesg,"Error");
		return FALSE;
	}
	
	return TRUE;
}
	

void WinMacroDialog2::OnPlayback_Click() 
{
	
	message_list=new CList <EVENTMSG,EVENTMSG>();
	//message_list=mlist;
	StartPlayback();
}


void WinMacroDialog2::StartPlayback()
{
//Initialize start_time to current tick count so that messages can be played back
	//with the same delays between them.
	start_time=GetTickCount();
	
	//Initialize the stream for reading messages
	input=new fstream();

	//If playback file specified is valid
   if (CheckFileName(&m_filename,input,ios::in|ios::binary,"Please enter a valid filename to playback."))
	{
		//Check if file has our signature
		char *file_signature=new char[sizeof(signature)];
		input->read(file_signature,sizeof(signature));
		
		if (strcmp(signature,file_signature))
		{
			AfxMessageBox("Invalid file format. Specified file is not a WinMacro recorded file!");
			return;
		}
		delete []file_signature;
		//Set flag variable to indicate we are playing back.  This is needed because a click to the "Stop Recording" button 
		//of this application is also stored when recording. When the file is played back, that button gets clicked again, but this 
		//time "Start Recording" gets clicked,(because it's playing back, not recording). This unfortunately causes recording to begin
		//again. Took lots of time to figure this out :)
		playing_back=TRUE;

		SetWindowText("WinMacro v1.2::Playing Back");
		ShowWindow(SW_MINIMIZE);
		
		//Install the hook to playback
		hook_handle=SetWindowsHookEx(WH_JOURNALPLAYBACK,JournalPlaybackProc,hinstance,0);
		
	}	
}

void WinMacroDialog2::StopRecording()
{
	
	
	//Remove the hook
	UnhookWindowsHookEx(hook_handle);
	
	//Enable button
	m_record_button.EnableWindow(TRUE);
	
	
	//Enable everything 
	m_filename.EnableWindow(TRUE);
	m_browse_button.EnableWindow(TRUE);
	m_playback_button.EnableWindow(TRUE);
	m_options_button.EnableWindow(TRUE);
	
	SetFocus();
	
	
	//Change status to finished recording
	statusbar.SetText("Finished recording",0,0);
	
	//Set bool variable back to original value to indicate recording is over
	recording=!recording;

	//Close output file
	output->close();
}

void WinMacroDialog2::OnBrowse_Click() 
{
		ShowFileDialog(&m_filename);	
}

void WinMacroDialog2::FinishedPlayback()
{
	statusbar.SetText("Ready to Record",0,0);
	SetWindowText("WinMacro v1.2");
	if( m_initialPath.GetLength() > 0) {
		delete message_list;
		exit( 0);
	}
	else
	{
		ShowWindow(SW_RESTORE);
	
		delete message_list;
	}
}
void WinMacroDialog2::OnAbout_Click() 
{
	//Show the about dialog. The simplest of all :)
	AboutDialog about_dialog;
	about_dialog.DoModal();
}

void WinMacroDialog2::OnOptions_Click() 
{
	OptionsDialog dialog;
	dialog.DoModal();
}
