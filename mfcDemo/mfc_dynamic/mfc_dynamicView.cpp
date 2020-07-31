
// mfc_dynamicView.cpp: CDynamicView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "mfc_dynamic.h"
#endif

#include "mfc_dynamicDoc.h"
#include "mfc_dynamicView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDynamicView

IMPLEMENT_DYNCREATE(CDynamicView, CView)

BEGIN_MESSAGE_MAP(CDynamicView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDynamicView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDynamicView 构造/析构

CDynamicView::CDynamicView() noexcept
{
	// TODO: 在此处添加构造代码

}

CDynamicView::~CDynamicView()
{
}

BOOL CDynamicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDynamicView 绘图

void CDynamicView::OnDraw(CDC* /*pDC*/)
{
	CDynamicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDynamicView 打印


void CDynamicView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDynamicView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDynamicView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDynamicView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CDynamicView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDynamicView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDynamicView 诊断

#ifdef _DEBUG
void CDynamicView::AssertValid() const
{
	CView::AssertValid();
}

void CDynamicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDynamicDoc* CDynamicView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDynamicDoc)));
	return (CDynamicDoc*)m_pDocument;
}
#endif //_DEBUG


// CDynamicView 消息处理程序
