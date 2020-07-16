// ChildView.h : interface of the CChildView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDVIEW_H__274FE673_1449_4542_8B70_2BFDC12D3F63__INCLUDED_)
#define AFX_CHILDVIEW_H__274FE673_1449_4542_8B70_2BFDC12D3F63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChildView window

class CChildView : public CEditView
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildView)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
    //virtual void PostNcDestroy();

    DECLARE_DYNCREATE(CChildView)
	//{{AFX_MSG(CChildView)
	afx_msg void OnPaint();
    afx_msg BOOL OnEditChange();
    afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDVIEW_H__274FE673_1449_4542_8B70_2BFDC12D3F63__INCLUDED_)
