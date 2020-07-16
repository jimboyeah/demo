// demo.h : main header file for the DEMO application
//

#if !defined(AFX_DEMO_H__9A1D9E34_AED4_4FC8_BF64_AC7081822164__INCLUDED_)
#define AFX_DEMO_H__9A1D9E34_AED4_4FC8_BF64_AC7081822164__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDemoApp:
// See demo.cpp for the implementation of this class
//

class CDemoApp : public CWinApp
{
public:
	CDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CDemoApp)
	afx_msg void OnAppAbout();
    afx_msg void OnAppOpen();
    afx_msg void OnAppSave();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    CString filePath;
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMO_H__9A1D9E34_AED4_4FC8_BF64_AC7081822164__INCLUDED_)
