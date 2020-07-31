// demo.cpp : Defines the class behaviors for the application.

#include "stdafx.h"
#include "demo.h"
#include "AboutDialog.h"
#include "MainFrm.h"
#include <winuser.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifdef _UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") 
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoApp

BEGIN_MESSAGE_MAP(CDemoApp, CWinApp)
	//{{AFX_MSG_MAP(CDemoApp)
	ON_COMMAND(ID_VIEW_CHILD, OnViewCHILD)
    ON_COMMAND(ID_VIEW_POPUP, OnViewPOPUP)
    ON_COMMAND(ID_VIEW_OVERLAPPED, OnViewOVERLAPPED)
    ON_COMMAND(ID_VIEW_TEXTBOX, OnViewTEXTBOX)
    ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
    ON_COMMAND(ID_APP_OPEN, OnAppOpen)
    ON_COMMAND(ID_APP_SAVE, OnAppSave)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoApp construction

CDemoApp::CDemoApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDemoApp object

CDemoApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CDemoApp initialization

BOOL CDemoApp::InitInstance()
{
    printf("Test...\n");
    OutputDebugString((LPCTSTR)"OutputDebugString...\n");
    // AfxTrace("CDemoApp ...");

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

    // #ifdef _AFXDLL
    // 	Enable3dControls();			// Call this when using MFC in a shared DLL
    // #else
    // 	Enable3dControlsStatic();	// Call this when linking to MFC statically
    // #endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));


	// To create the main window, this code creates a new frame window
	// object and then sets it as the application's main window object.

	CMainFrame* pFrame = new CMainFrame;
	m_pMainWnd = pFrame;

    

	// create and load the frame with its resources

	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);


	pFrame->SetWindowText((LPCTSTR)"CodeBlocks & MFC demo");

    
	// The one and only window has been initialized, so show and update it.
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CDemoApp message handlers


// App command to run the dialog
void CDemoApp::OnViewCHILD()
{
    CAboutDlg::BoxStyle style = CAboutDlg::IDD_CHILD;
	CAboutDlg aboutDlg(&style);
	aboutDlg.DoModal();
}

// App command to run the dialog
void CDemoApp::OnViewPOPUP()
{
    CAboutDlg::BoxStyle style = CAboutDlg::IDD_POPUP;
    CAboutDlg aboutDlg(&style);
    aboutDlg.DoModal();
}
// App command to run the dialog
void CDemoApp::OnViewOVERLAPPED()
{
    CAboutDlg::BoxStyle style = CAboutDlg::IDD_OVERLAPPED;
    CAboutDlg *dlg = new CAboutDlg();
    BOOL ret = dlg->Create((ULONG_PTR)(style), m_pMainWnd);
    dlg->ShowWindow(SW_SHOW);
}
// App command to run the dialog
void CDemoApp::OnViewTEXTBOX()
{
    CAboutDlg::BoxStyle style = CAboutDlg::IDD_TEXTBOX;
    CAboutDlg *dlg = new CAboutDlg();
    BOOL ret = dlg->Create((ULONG_PTR)(style), m_pMainWnd);
    dlg->ShowWindow(SW_SHOW);
}
// App command to run the dialog
void CDemoApp::OnAppAbout()
{
    CAboutDlg aboutDlg;
    aboutDlg.DoModal();
}


void CDemoApp::OnAppOpen()
{
	CFileDialog box(TRUE, (LPCTSTR)"txt", NULL, OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, (LPCTSTR)"(*.txt;*.inf;*.md)|*.txt;*.inf;*.md||");
	if(box.DoModal() == IDOK)
	{
	    CMainFrame &mf = *((CMainFrame*)m_pMainWnd);
		CString szBuf, szName = box.GetPathName();
		//MessageBox(NULL, szName, "Open", MB_OK);
		CStdioFile f(szName, OFN_OVERWRITEPROMPT);
		f.ReadString(szBuf); // read a line
		f.Close();
		mf.SetContentText(szBuf);
        // CString al;
        // al.Format("34.6f-34.0f=%f",34.6f-34.0f) ; //0.599998
        //((CMainFrame *)m_pMainWnd)->SetContentText(al);
        printf("%hs <===\n", (LPCTSTR)szBuf);

        CFile cf;
        CFileException fe;
        if( 0!=cf.Open(szName, CFile::modeReadWrite, &fe) ){
            long l = (long)cf.GetLength();
            char *cpBuf = new char[l];
            cf.Read(cpBuf,l);
            mf.SetContentText(CString(cpBuf,l));
            // delete cpBuf; crash!
        }else MessageBeep(MB_ICONEXCLAMATION);
        filePath = szName;
	}
}

void CDemoApp::OnAppSave()
{
    CMainFrame &mf = *((CMainFrame*)m_pMainWnd);
    if(!filePath.GetLength()){
        CFileDialog box(FALSE, (LPCTSTR)"txt", NULL, OFN_OVERWRITEPROMPT, (LPCTSTR)"(*.txt;*.inf)|*.txt;*.inf||");
        if( IDOK!=box.DoModal()) return;
        filePath = box.GetPathName();
    }
    CFile cf;
    cf.Open(filePath, CFile::modeWrite | CFile::modeCreate | CFile::typeBinary);

    CString &txt = mf.SetContentText();
    /*
    CString cr = "\r\n";
    CString n ;
    int index = txt.Find(cr);
    while (index!= -1)
    {
       txt.Delete(index, cr.GetLength());
       index = txt.Find(cr, index);
    }

    txt += "\r\n";
    */
    LPCTSTR s = txt.GetBuffer(txt.GetLength());
    cf.Write(s, txt.GetLength());
    cf.Close();
    MessageBeep(MB_ICONINFORMATION);
    mf.SetMessageText("Saved to " + filePath);
}
/////////////////////////////////////////////////////////////////////////////
// CDemoApp message handlers
