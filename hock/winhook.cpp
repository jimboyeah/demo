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

LRESULT CALLBACK FilterFunc( int nCode, WORD wp, DWORD lp) {
    stringstream ss;
    char text[MAXBYTE];
    ss << szTitle << " -  " << ++COUNT << std::hex << " MSG:" << nCode
         << std::hex << " wp:0x" << wp << " lp:0x" << lp << "\n";
    ss.getline( text, MAXBYTE);
    SetWindowText( hWin, text );
	return CallNextHookEx( MyHook, nCode, wp, lp); 
}

HHOOK HookStart(int idHook, HINSTANCE hd, DWORD td){
    HOOKPROC hkp = reinterpret_cast<HOOKPROC>( FilterFunc );
    HHOOK hk = SetWindowsHookEx( idHook, hkp, hd, td );
    if(hk==NULL){
        UINT Error = GetLastError();
        ShowErrorInfo(Error);
    }
    return hk;
}

void HookDown(HHOOK hook){
    UnhookWindowsHookEx(hook);
}

LRESULT CALLBACK circle( HWND hWin, UINT iMsg, WPARAM wp, LPARAM lp ){
    HDC         hdc ;
    PAINTSTRUCT ps ;
    RECT        rect ;

    switch( iMsg ){
    case WM_CREATE:
        PlaySound( szSound, NULL, SND_FILENAME | SND_ASYNC );
        MyHook = HookStart( WH_KEYBOARD,NULL,GetCurrentThreadId() );
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        HookDown( MyHook );
        return 0;
    case WM_PAINT:
        hdc = BeginPaint( hWin, &ps);
        GetClientRect( hWin, &rect );
        string text =  "Appication API HOOK";
        DrawText( hdc, text.c_str(), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER );
        EndPaint( hWin, &ps);
        return 0;
    }

    return DefWindowProc( hWin, iMsg, wp, lp);
}
