// demo.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "demo.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoApp

BEGIN_MESSAGE_MAP(CDemoApp, CWinApp)
	//{{AFX_MSG_MAP(CDemoApp)
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

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

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


	pFrame->SetWindowText("CodeBlocks & MFC demo");

    
	// The one and only window has been initialized, so show and update it.
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CDemoApp message handlers





/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CDemoApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

void CDemoApp::OnAppOpen()
{
	CFileDialog box(TRUE, "txt", NULL, OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, "(*.txt;*.inf)|*.txt;*.inf||");
	if(box.DoModal() == IDOK)
	{
	    CMainFrame &mf = *((CMainFrame*)m_pMainWnd);
		CString szBuf, szName = box.GetPathName();
		//MessageBox(NULL, szName, "Open", MB_OK);
		CStdioFile f(szName, OFN_OVERWRITEPROMPT);
		f.ReadString(szBuf);
		f.Close();
		delete &f;
		mf.SetContentText(szBuf);
        CString al;
        al.Format("34.6f-34.0f=%f",34.6f-34.0f) ; //0.599998
        //((CMainFrame *)m_pMainWnd)->SetContentText(al);

        CFile cf;
        CFileException fe;
        if( 0!=cf.Open(szName, CFile::modeReadWrite, &fe) ){
            int l = cf.GetLength();
            char *cpBuf = new char[l];
            cf.Read(cpBuf,l);
            mf.SetContentText(CString(cpBuf,l));
            delete cpBuf;
        }else MessageBeep(MB_ICONEXCLAMATION);
        filePath = szName;
	}

}

void CDemoApp::OnAppSave()
{
    CMainFrame &mf = *((CMainFrame*)m_pMainWnd);
    if(!filePath.GetLength()){
        CFileDialog box(FALSE, "txt", NULL, OFN_OVERWRITEPROMPT, "(*.txt;*.inf)|*.txt;*.inf||");
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
    mf.SetMessageText("File saved.");
}
/////////////////////////////////////////////////////////////////////////////
// CDemoApp message handlers
