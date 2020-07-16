#if !defined(AFX_WINMACRODIALOG2_H__E02D3C42_E7A5_11D7_8ECB_CA2C320FC576__INCLUDED_)
#define AFX_WINMACRODIALOG2_H__E02D3C42_E7A5_11D7_8ECB_CA2C320FC576__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WinMacroDialog2.h : header file
//
#include "resource.h"

#include <fstream>
#include "resource.h"
#include <afxcmn.h>
/////////////////////////////////////////////////////////////////////////////
// WinMacroDialog2 dialog

class WinMacroDialog2 : public CDialog
{

	CStatusBarCtrl statusbar;
	

	void ShowFileDialog(CEdit *textbox);
   BOOL CheckFileName(CEdit *filename_field, std::fstream *stream, int mode,CString error_mesg);
	
// Construction
public:
	WinMacroDialog2(CWnd* pParent = NULL);   // standard constructor
	
	void StopRecording();
	void StartPlayback();
	void FinishedPlayback();
// Dialog Data
	//{{AFX_DATA(WinMacroDialog2)
	enum { IDD = IDD_WINMACRO2 };
	CButton	m_options_button;
	CButton	m_browse_button;
	CEdit	m_filename;
	CButton	m_playback_button;
	CButton	m_record_button;
	//}}AFX_DATA

	CString m_initialPath;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(WinMacroDialog2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(WinMacroDialog2)
	virtual BOOL OnInitDialog();
	afx_msg void OnRecord_Click();
	afx_msg void OnPlayback_Click();
	afx_msg void OnBrowse_Click();
	afx_msg void OnAbout_Click();
	afx_msg void OnOptions_Click();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINMACRODIALOG2_H__E02D3C42_E7A5_11D7_8ECB_CA2C320FC576__INCLUDED_)
