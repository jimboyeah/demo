#if !defined(AFX_ABOUTDIALOG_H__4419E261_CFBB_11D7_8ECA_BE8B59CCA873__INCLUDED_)
#define AFX_ABOUTDIALOG_H__4419E261_CFBB_11D7_8ECA_BE8B59CCA873__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AboutDialog.h : header file
//
#include "resource.h"

/////////////////////////////////////////////////////////////////////////////
// AboutDialog dialog

class AboutDialog : public CDialog
{
// Construction
public:
	AboutDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(AboutDialog)
	enum { IDD = IDD_ABOUT_DIALOG };
	CString	m_websites_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AboutDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AboutDialog)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ABOUTDIALOG_H__4419E261_CFBB_11D7_8ECA_BE8B59CCA873__INCLUDED_)
