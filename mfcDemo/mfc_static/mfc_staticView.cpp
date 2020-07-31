
// mfc_staticView.cpp: CmfcstaticView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "mfc_static.h"
#endif

#include "mfc_staticDoc.h"
#include "CntrItem.h"
#include "resource.h"
#include "mfc_staticView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmfcstaticView

IMPLEMENT_DYNCREATE(CmfcstaticView, CView)

BEGIN_MESSAGE_MAP(CmfcstaticView, CView)
	ON_WM_DESTROY()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, &CmfcstaticView::OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, &CmfcstaticView::OnCancelEditCntr)
	ON_COMMAND(ID_FILE_PRINT, &CmfcstaticView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CmfcstaticView::OnFilePrintPreview)
	ON_UPDATE_COMMAND_UI(ID_FILE_PRINT_PREVIEW, &OnFilePrintPreviewUIUpdate)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CmfcstaticView 构造/析构

CmfcstaticView::CmfcstaticView() noexcept
{
	m_pSelection = nullptr;
	// TODO: 在此处添加构造代码

}

CmfcstaticView::~CmfcstaticView()
{
}

BOOL CmfcstaticView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CmfcstaticView 绘图

void CmfcstaticView::OnDraw(CDC* /*pDC*/)
{
	CmfcstaticDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CmfcstaticView::OnInitialUpdate()
{
	CView::OnInitialUpdate();


	// TODO: 写入最终选择模式代码之后移除此代码
	m_pSelection = nullptr;    // 初始化所选内容

}


// CmfcstaticView 打印

void CmfcstaticView::OnFilePrintPreviewUIUpdate(CCmdUI* pCmdUI)
{
	if (!pCmdUI)
		return;

	if (m_pSelection != nullptr)
	{
		DWORD dwStatus = 0;
		if (SUCCEEDED(m_pSelection->QueryCommand(OLECMDID_PRINTPREVIEW, &dwStatus)) &&
			dwStatus & OLECMDF_ENABLED)
		{
				pCmdUI->Enable(TRUE);
				return;
		}
	}
	pCmdUI->Enable(FALSE);
}

void CmfcstaticView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CmfcstaticView::OnPreparePrinting(CPrintInfo* pInfo)
{
	if (!CView::DoPreparePrinting(pInfo))
		return FALSE;

	if (!COleDocObjectItem::OnPreparePrinting(this, pInfo))
		return FALSE;

	return TRUE;
}

void CmfcstaticView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CmfcstaticView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CmfcstaticView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: 在此处添加自定义打印代码
	if(pInfo->m_bDocObject)
		COleDocObjectItem::OnPrint(this, pInfo, TRUE);
	else
		CView::OnPrint(pDC, pInfo);
}

void CmfcstaticView::OnDestroy()
{
	// 析构时停用此项；这在
	// 使用拆分器视图时非常重要 
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != nullptr && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == nullptr);
   }
   CView::OnDestroy();
}



// OLE 客户端支持和命令

BOOL CmfcstaticView::IsSelected(const CObject* pDocItem) const
{
	//下面的实现是足够的，如果所选内容包括
	// CmfcstaticCntrItem 对象，则以下实现就足够了。若要处理其他选择机制，
	//  则应替换此处的实现

	// TODO: 实现对所选 OLE 客户端项进行测试的函数

	return pDocItem == m_pSelection;
}

void CmfcstaticView::OnInsertObject()
{
	// 调用标准的“插入对象”对话框以获得有关
	//  对于新的 CmfcstaticCntrItem 对象
	COleInsertDialog dlg;
	if (dlg.DoModal(COleInsertDialog::DocObjectsOnly) != IDOK)
		return;

	BeginWaitCursor();

	CmfcstaticCntrItem* pItem = nullptr;
	TRY
	{
		// 创建与此文档相连接的新项
		CmfcstaticDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new CmfcstaticCntrItem(pDoc);
		ASSERT_VALID(pItem);

		// 通过对话框数据初始化该项
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // 任何异常都将导致该结果
		ASSERT_VALID(pItem);

		pItem->DoVerb(OLEIVERB_SHOW, this);

		ASSERT_VALID(pItem);
		// 作为任意用户界面设计，这会将所选内容
		//  设置为插入的最后一项

		// TODO: 重新实现所选内容，使其适合于您的应用程序
		m_pSelection = pItem;   // 将所选内容设置为插入的最后一项
		pDoc->UpdateAllViews(nullptr);
	}
	CATCH(CException, e)
	{
		if (pItem != nullptr)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH

	EndWaitCursor();
}

// 以下命令处理程序提供了标准键盘
//  用户界面以取消就地编辑会话。  此处，
//  容器(而不是服务器)将导致停用
void CmfcstaticView::OnCancelEditCntr()
{
	// 关闭此视图中的任何就地活动项。
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != nullptr)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == nullptr);
}

// 在就地编辑一个对象时，容器需要对 OnSetFocus 和 OnSize 
//  进行特殊处理
void CmfcstaticView::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != nullptr &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// 如果该项处于同一视图中，则需要将焦点设置到该项
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != nullptr)
		{
			pWnd->SetFocus();   // 不要调用基类
			return;
		}
	}

	CView::OnSetFocus(pOldWnd);
}

void CmfcstaticView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != nullptr)
		pActiveItem->SetItemRects();
}

void CmfcstaticView::OnFilePrint()
{
	//默认情况下，要求活动文档使用 IOleCommandTarget 打印自身。
	//如果不需要此行为，
	//请移除对 COleDocObjectItem::DoDefaultPrinting 调用。
	//如果由于某种原因调用失败，则将尝试使用 IPrint 接口打印
	//该文档对象。
	CPrintInfo printInfo;
	ASSERT(printInfo.m_pPD != nullptr);
	if (S_OK == COleDocObjectItem::DoDefaultPrinting(this, &printInfo))
		return;

	CView::OnFilePrint();

}


void CmfcstaticView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CmfcstaticView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CmfcstaticView 诊断

#ifdef _DEBUG
void CmfcstaticView::AssertValid() const
{
	CView::AssertValid();
}

void CmfcstaticView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmfcstaticDoc* CmfcstaticView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmfcstaticDoc)));
	return (CmfcstaticDoc*)m_pDocument;
}
#endif //_DEBUG


// CmfcstaticView 消息处理程序
