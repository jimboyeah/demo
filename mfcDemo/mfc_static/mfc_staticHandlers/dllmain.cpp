// dllmain.cpp: DllMain 的实现。

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "mfcstaticHandlers_i.h"
#include "dllmain.h"
#include "xdlldata.h"

CmfcstaticHandlersModule _AtlModule;

class CmfcstaticHandlersApp : public CWinApp
{
public:

// 重写
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CmfcstaticHandlersApp, CWinApp)
END_MESSAGE_MAP()

CmfcstaticHandlersApp theApp;

BOOL CmfcstaticHandlersApp::InitInstance()
{
	if (!PrxDllMain(m_hInstance, DLL_PROCESS_ATTACH, nullptr))
		return FALSE;
	return CWinApp::InitInstance();
}

int CmfcstaticHandlersApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
