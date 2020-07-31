// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "demo.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView


CChildView::CChildView()
{
    CFont font;
    font.CreateFont(16, 16, 0, 0, 400, FALSE, FALSE, FALSE, 
        CHINESEBIG5_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 
        DEFAULT_QUALITY, DEFAULT_PITCH | FF_MODERN, _T("微软雅黑"));
    SetFont(&font);
}

CChildView::~CChildView()
{
}

IMPLEMENT_DYNCREATE(CChildView,CEditView)

BEGIN_MESSAGE_MAP(CChildView,CEditView )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
    ON_WM_DESTROY()
    ON_CONTROL_REFLECT_EX(EN_CHANGE, OnEditChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
    BOOL bPreCreated = CEditView::PreCreateWindow(cs);
    cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

void CChildView::OnPaint()
{


	// CWnd::Default() is done to avoid CView::OnPaint
	Default();

	// Do not call CWnd::OnPaint() for painting messages
}

void CChildView::OnDestroy()
{
    ;
}

void CView::PostNcDestroy()
{
    ;
}

// Overwrite Default Methods
BOOL CChildView::OnEditChange()
{
    return TRUE;   // disabled routing
}

