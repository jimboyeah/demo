
// CntrItem.cpp: CmfcstaticCntrItem 类的实现
//

#include "pch.h"
#include "framework.h"
#include "mfc_static.h"

#include "mfc_staticDoc.h"
#include "mfc_staticView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmfcstaticCntrItem 实现

IMPLEMENT_SERIAL(CmfcstaticCntrItem, COleDocObjectItem, 0)

CmfcstaticCntrItem::CmfcstaticCntrItem(CmfcstaticDoc* pContainer)
	: COleDocObjectItem(pContainer)
{
	// TODO: 在此添加一次性构造代码
}

CmfcstaticCntrItem::~CmfcstaticCntrItem()
{
	// TODO: 在此处添加清理代码
}

void CmfcstaticCntrItem::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	COleDocObjectItem::OnChange(nCode, dwParam);

	// 在编辑某项时(就地编辑或完全打开进行编辑)，
	//  该项将就其自身状态的更改
	//  或其内容的可视外观状态的更改发送 OnChange 通知。

	// TODO: 通过调用 UpdateAllViews 使该项无效
	//  (包括适合您的应用程序的提示)

	GetDocument()->UpdateAllViews(nullptr);
		// 现在只更新所有视图/无提示
}

BOOL CmfcstaticCntrItem::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// 就地激活期间，CmfcstaticCntrItem::OnChangeItemPosition
	//  以更改就地窗口的位置。
	//  这通常是由于服务器
	//  文档中的数据更改而导致范围改变或是
	//  就地调整大小所引起的。
	//
	// 此处的默认设置调用基类，该基类将调用
	//  COleDocObjectItem::SetItemRects 以移动项
	//  移动到新的位置。

	if (!COleDocObjectItem::OnChangeItemPosition(rectPos))
		return FALSE;

	// TODO: 更新该项的矩形/范围可能存在的任何缓存

	return TRUE;
}

BOOL CmfcstaticCntrItem::OnShowControlBars(CFrameWnd* pFrameWnd, BOOL bShow)
{
	CMDIFrameWndEx* pMainFrame = DYNAMIC_DOWNCAST(CMDIFrameWndEx, pFrameWnd);

	if (pMainFrame != nullptr)
	{
		ASSERT_VALID(pMainFrame);
		return pMainFrame->OnShowPanes(bShow);
	}

	return FALSE;
}


void CmfcstaticCntrItem::OnActivate()
{
}

void CmfcstaticCntrItem::OnDeactivateUI(BOOL bUndoable)
{
	COleDocObjectItem::OnDeactivateUI(bUndoable);

	DWORD dwMisc = 0;
	m_lpObject->GetMiscStatus(GetDrawAspect(), &dwMisc);
	if (dwMisc & OLEMISC_INSIDEOUT)
		DoVerb(OLEIVERB_HIDE, nullptr);
}

void CmfcstaticCntrItem::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	// 首先调用基类以读取 COleDocObjectItem 数据。
	// 因为这样会设置从 [!output CONTAINER_ITEM_CLASS]::GetDocument 返回的 m_pDocument 指针，
	//  CmfcstaticCntrItem::GetDocument，最好调用
	//  基类 Serialize。
	COleDocObjectItem::Serialize(ar);

	// 现在存储/检索特定于 CmfcstaticCntrItem 的数据
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CmfcstaticCntrItem 诊断

#ifdef _DEBUG
void CmfcstaticCntrItem::AssertValid() const
{
	COleDocObjectItem::AssertValid();
}

void CmfcstaticCntrItem::Dump(CDumpContext& dc) const
{
	COleDocObjectItem::Dump(dc);
}
#endif

