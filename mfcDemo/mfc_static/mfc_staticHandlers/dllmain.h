// dllmain.h: 模块类的声明。

class CmfcstaticHandlersModule : public ATL::CAtlDllModuleT<CmfcstaticHandlersModule>
{
public :
	DECLARE_LIBID(LIBID_mfcstaticHandlersLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MFCSTATICHANDLERS, "{530df073-848b-4603-bdbe-e78642ec63eb}")
};

extern class CmfcstaticHandlersModule _AtlModule;
