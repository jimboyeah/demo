// AboutDialog.cpp : implementation file
//


#include <afxwin.h>
#include <afxdlgs.h>
#include "AboutDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AboutDialog dialog


AboutDialog::AboutDialog(CWnd* pParent /*=NULL*/)
	: CDialog(AboutDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(AboutDialog)
	m_websites_list = _T("");
	//}}AFX_DATA_INIT
}


void AboutDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AboutDialog)
	DDX_Text(pDX, IDC_WEBSITES_LIST, m_websites_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AboutDialog, CDialog)
	//{{AFX_MSG_MAP(AboutDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AboutDialog message handlers

BOOL AboutDialog::OnInitDialog() 
{
	
	m_websites_list="Visit http://thegenius.sourceforge.net \r\n ";
	m_websites_list+="http://winbots.sourceforge.net \r\n ";
	m_websites_list+="http://www25.brinkster.com/sadhusenthil \r\n ";
	m_websites_list+="http://esquel.dev.java.net \r\n ";
	m_websites_list+="to know more about my projects.";
	// TODO: Add extra initialization here
	CDialog::OnInitDialog();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
