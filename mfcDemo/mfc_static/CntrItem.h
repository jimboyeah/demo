
// CntrItem.h: CmfcstaticCntrItem 类的接口
//

#pragma once

class CmfcstaticDoc;
class CmfcstaticView;

class CmfcstaticCntrItem : public COleDocObjectItem
{
	DECLARE_SERIAL(CmfcstaticCntrItem)

// 构造函数
public:
	CmfcstaticCntrItem(CmfcstaticDoc* pContainer = nullptr);
		// 注意: 允许 pContainer 为 NULL 以启用 IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE 要求类具有带零
		//  参数的构造函数。  OLE 项通常是用
		//  非 null 文档指针

// 特性
public:
	CmfcstaticDoc* GetDocument()
		{ return reinterpret_cast<CmfcstaticDoc*>(COleDocObjectItem::GetDocument()); }
	CmfcstaticView* GetActiveView()
		{ return reinterpret_cast<CmfcstaticView*>(COleDocObjectItem::GetActiveView()); }

public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();

protected:
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	virtual BOOL OnShowControlBars(CFrameWnd* pFrameWnd, BOOL bShow);

// 实现
public:
	~CmfcstaticCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

