#include "hooksrv.h"
 
#pragma data_seg("HookShared")
HHOOK hHook = NULL;
HWND hWnd = NULL;
EXPORT int hookCode = 0xff;
EXPORT MOUSEHOOKSTRUCT SharedMSG = {0};
#pragma data_seg()
#pragma comment(linker, "/SECTION:HookShared,RWS")
 
HINSTANCE hMod;
 
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  fdwreason, LPVOID lpReserved )
{
    char buf[MAXBYTE];
    stringstream ss;
    ss << fdwreason << " Exit Hook" << endl;
    ss.getline( buf, MAXBYTE );
    //MessageBox(hWnd, buf, "TIP", NULL);

    if(fdwreason==DLL_PROCESS_DETACH){
        //MessageBox(hWnd, "EXIT DLL HOOK", "TIP", NULL);
        SendMessage( hWnd, WM_HOOKDESTORY, NULL, NULL);
    }
    hMod = (HINSTANCE)hModule;
    return TRUE;
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
        MessageBox( NULL, (LPCTSTR)lpMsgBuf, "Hook Serer Error", MB_OK | MB_ICONINFORMATION );
}

LRESULT WINAPI HookProc(int code, WPARAM wParam, LPARAM lParam){
    hookCode = code;
    PMOUSEHOOKSTRUCT pm = (PMOUSEHOOKSTRUCT)lParam;
    SharedMSG = *(PMOUSEHOOKSTRUCT)lParam;

    stringstream ss;
    char buf[MAXBYTE];
    ss << " Test(" << SharedMSG.pt.x << "," << SharedMSG.pt.y << ")" << endl;
    ss.getline( buf, MAXBYTE );
    SetWindowText(hWnd, buf);

    lParam = (LPARAM)&SharedMSG; // Test address if pass by argument
    SendMessage( hWnd, WM_HOOK, wParam, lParam );
    return CallNextHookEx(hHook, code, wParam, lParam);
}
 
HHOOK HookStart(int hookID, HWND hWindow, DWORD dwThreadId ){
    hWnd = hWindow;
    HOOKPROC cb = reinterpret_cast<HOOKPROC>( HookProc ); // for VS97
    hHook = SetWindowsHookEx( hookID, cb, hMod, dwThreadId);
    if( !hHook ) ShowErrorInfo( GetLastError() );
    return hHook;
}
 
BOOL HookDown(HHOOK idHook){
    hWnd = NULL;
    return UnhookWindowsHookEx(hHook);
}