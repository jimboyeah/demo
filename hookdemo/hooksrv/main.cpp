#include "main.h"

HHOOK hHook SHARED = NULL;
HWND hWnd SHARED = NULL;
EXPORT int hookCode SHARED = 0xff;
EXPORT POINT SharedPoint SHARED = {0,0};

EXPORT MOUSEHOOKSTRUCT SharedMSG SHARED = {{0,0},0};


//#pragma data_seg("DLLSharedSection")
//   int SharedData = 123;
//#pragma data_seg()

HINSTANCE hMod;

extern "C" BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  fdwreason, LPVOID lpReserved )
{
    hMod = (HINSTANCE)hModule;
    return TRUE;

    char buf[MAXBYTE];
    stringstream ss;
    ss << hModule << "@" << fdwreason << "#:";
    if(fdwreason==DLL_PROCESS_ATTACH){
        ss << "DLL_PROCESS_ATTACH" << endl;
    }else if(fdwreason==DLL_PROCESS_DETACH){
        ss << "DLL_PROCESS_DETACH" << endl;
    }else if(fdwreason==DLL_THREAD_ATTACH){
        ss << "DLL_THREAD_ATTACH" << endl;
    }else if(fdwreason==DLL_THREAD_DETACH){
        //MessageBox(hWnd, "EXIT DLL HOOK", "TIP", NULL);
        SendMessage( hWnd, WM_HOOKDESTORY, NULL, NULL);
        ss << "DLL_THREAD_DETACH" << endl;
    }
    ss.getline( buf, MAXBYTE );
    MessageBox(hWnd, buf, "Hocksrv TIP", NULL);
}

void ShowErrorInfo(int Error){
        LPVOID lpMsgBuf;
        FormatMessage(
            FORMAT_MESSAGE_ALLOCATE_BUFFER |
            FORMAT_MESSAGE_FROM_SYSTEM |
            FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL,
            Error,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
            (LPTSTR) &lpMsgBuf,
            0,
            NULL
        );
        MessageBox( NULL, (LPCTSTR)lpMsgBuf, "Hook Server Error", MB_OK | MB_ICONINFORMATION );
}

LRESULT WINAPI HookProc(int code, WPARAM wParam, LPARAM lParam){
    hookCode = code;
    PMOUSEHOOKSTRUCT pm = (PMOUSEHOOKSTRUCT)lParam;
    //memcpy( &SharedMSG, (const void*)lParam, sizeof(MOUSEHOOKSTRUCT) );
    //PMOUSEHOOKSTRUCT pmsg = (PMOUSEHOOKSTRUCT)&SharedMSG;
    //MOUSEHOOKSTRUCT msg = (MOUSEHOOKSTRUCT) *pmsg;
    //msg = *pm; // deep copy
    SharedMSG = *(PMOUSEHOOKSTRUCT)lParam;
    SharedPoint = pm->pt; // deep copy
    SendMessage( hWnd, WM_HOOK, wParam, lParam );
    return CallNextHookEx(hHook, code, wParam, lParam);
}

EXPORT HHOOK HookStart(int hookID, HWND hWindow, DWORD dwThreadId ){
    hWnd = hWindow;
    HOOKPROC cb = reinterpret_cast<HOOKPROC>( HookProc ); // for VS97
    hHook = SetWindowsHookEx( hookID, cb, hMod, dwThreadId);
    if( !hHook ) ShowErrorInfo( GetLastError() );
    return hHook;
}

EXPORT BOOL HookDown(HHOOK idHook){
    hWnd = NULL;
    return UnhookWindowsHookEx(idHook);
}
