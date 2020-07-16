#if !defined(AFX_OPTIONSDIALOG_H__1D320AA2_E7B3_11D7_8ECB_CA2C320FC576__INCLUDED_)
#define AFX_OPTIONSDIALOG_H__1D320AA2_E7B3_11D7_8ECB_CA2C320FC576__INCLUDED_

#include "resource.h"
#include <afxcmn.h>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OptionsDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// OptionsDialog dialog

class OptionsDialog : public CDialog
{
// Construction
public:
	OptionsDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(OptionsDialog)
	enum { IDD = IDD_OPTIONS_DIALOG };
	CButton	m_repeat_playback;
	CEdit	m_no_of_repetitions;
	CSliderCtrl	m_playback_slider;
	CButton	m_add_to_recorded_time;
	CEdit	m_time_interval;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(OptionsDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(OptionsDialog)
	afx_msg void OnOK_Click();
	virtual BOOL OnInitDialog();
	afx_msg void OnUserDefinedSpeed_Click();
	afx_msg void OnNormalSpeed_Click();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnRepeatPlayback_Click();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIONSDIALOG_H__1D320AA2_E7B3_11D7_8ECB_CA2C320FC576__INCLUDED_)
