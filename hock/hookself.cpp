#pragma comment(lib,"winmm.lib")
#include <windows.h>
#include <sstream>

using namespace std;

static TCHAR szTitle[] = TEXT("GUI App");
static TCHAR szSound[] = TEXT( "c:\\windows\\media\\Windows Logon Sound.wav" );

HWND hWin;
HINSTANCE hAPP;

LRESULT CALLBACK circle( HWND, UINT, WPARAM, LPARAM );

int WINAPI WinMain(HINSTANCE hApp, HINSTANCE hPre, LPSTR lpLine, int iCmd )
{
    MSG msg;
    WNDCLASS winClass;

    hAPP = hApp;

    winClass.style                  = CS_HREDRAW | CS_VREDRAW;
    winClass.lpfnWndProc  = circle;
    winClass.hInstance        = hApp;
    winClass.hIcon                = LoadIcon( NULL, IDI_APPLICATION );
    winClass.hCursor            = LoadCursor( NULL,IDC_CROSS );
    winClass.hbrBackground = (HBRUSH) GetStockObject( WHITE_BRUSH );
    winClass.lpszClassName = szTitle;
    winClass.lpszMenuName = NULL;
    winClass.cbClsExtra          = 0;
    winClass.cbWndExtra       = 0;

    if( !RegisterClass( &winClass ) ){
        MessageBox( NULL, TEXT("I need a Window!"), szTitle, MB_ICONERROR );
        return 0;
    }

    hWin = CreateWindow( 
                    szTitle, szTitle, //window class and caption
                   WS_OVERLAPPEDWINDOW,
                   CW_USEDEFAULT,  CW_USEDEFAULT, // position x, y 
                   CW_USEDEFAULT,  CW_USEDEFAULT, // size width, height
                   NULL, // parent windows handle
                   NULL, // menu handle
                   hApp,
                   NULL); //creation parameters
    
    ShowWindow( hWin, iCmd );
    UpdateWindow( hWin );

    while(GetMessage( &msg, NULL, 0, 0 ) ){
        TranslateMessage( &msg );
        DispatchMessage( &msg );
    }

    return msg.wParam;

}

#define EXPORT __declspec(dllexport)

#pragma data_seg("HookShared")
HHOOK hHook = NULL;
HWND hWnd = NULL;
#pragma data_seg()
#pragma comment(linker, "/SECTION:HookShared,RWS")
 HINSTANCE hMod;

EXPORT BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    hMod = (HINSTANCE)hModule;
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    MessageBox( NULL,"Module Load.", szTitle, MB_OK | MB_ICONINFORMATION );
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
        MessageBox( NULL, (LPCTSTR)lpMsgBuf, "Error", MB_OK | MB_ICONINFORMATION );
}

UINT COUNT;
HHOOK MyHook;
UINT TIMER_HOOK = 1;

LRESULT CALLBACK FilterFunc( int nCode, WORD wp, DWORD lp) {
    stringstream ss;
    char text[MAXBYTE];
    ss << szTitle << " -  " << ++COUNT << std::hex << " MSG:" << nCode
         << std::hex << " wp:0x" << wp << " lp:0x" << lp << "\n";
    ss.getline( text, MAXBYTE);
    SetWindowText( hWin, text );
	return CallNextHookEx( MyHook, nCode, wp, lp); 
}

EXPORT HHOOK HookStart(int hookID, HWND hWindow, DWORD dwThreadId){
    hWnd = hWindow;
    char * lib = "hookself.exe";
    char ori[MAXWORD];
    HOOKPROC cb = reinterpret_cast<HOOKPROC>( FilterFunc ); // for VS97
    GetModuleFileName( hAPP, ori, MAXWORD/sizeof(TCHAR) );
    CopyFile( ori, lib, FALSE ); // FALSE to overwrite
    hMod = LoadLibrary(lib);
    if( !hMod ){
        ShowErrorInfo( GetLastError() );
        return NULL;
    }
    stringstream ss;
    ss << hMod;
            MessageBox( NULL, ss.str().c_str(), "Error", MB_OK | MB_ICONINFORMATION );

    hHook = SetWindowsHookEx( hookID, cb, hMod, dwThreadId);
    if( !hHook ){
        ShowErrorInfo( GetLastError() );
        return NULL;
    }
    return hHook;
}
 
EXPORT BOOL HookDown(HHOOK idHook){
    hWnd = NULL;
    return UnhookWindowsHookEx(hHook);
}

void CALLBACK TimerProc( HWND hwin, UINT uMsg, UINT id, DWORD t){
    HWND hw = FindWindow( "WordPadClass", NULL);
    if(!hw) return;
    DWORD thread = GetWindowThreadProcessId( hw, NULL );
    MyHook = HookStart( WH_MOUSE, hWin, thread );
    if(MyHook){
        KillTimer( hWin, TIMER_HOOK );
        MessageBox( hwin, "Hooked for Wordpad.", szTitle, MB_ICONINFORMATION );
    }
}

LRESULT CALLBACK circle( HWND hWin, UINT iMsg, WPARAM wp, LPARAM lp ){
    HDC         hdc ;
    PAINTSTRUCT ps ;
    RECT        rect ;
    string text =  "Appication API HOOK Wating for a Wordpad.";
    TIMERPROC cb = reinterpret_cast<TIMERPROC>(TimerProc); // for VS97

    switch( iMsg ){
    case WM_CREATE:
        PlaySound( szSound, NULL, SND_FILENAME | SND_ASYNC );
        SetTimer( hWin, TIMER_HOOK,  1000, cb);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        HookDown( MyHook );
        return 0;
    case WM_PAINT:
        hdc = BeginPaint( hWin, &ps);
        GetClientRect( hWin, &rect );
        DrawText( hdc, text.c_str(), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER );
        EndPaint( hWin, &ps);
        return 0;
    }

    return DefWindowProc( hWin, iMsg, wp, lp);
}
