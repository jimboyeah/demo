#pragma comment(lib,"winmm.lib")
#include <windows.h>
#include <string>

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


LRESULT CALLBACK circle( HWND hWin, UINT iMsg, WPARAM wp, LPARAM lp ){
    HDC         hdc ;
    PAINTSTRUCT ps ;
    RECT        rect ;

    switch( iMsg ){
    case WM_CREATE:
        PlaySound( szSound, NULL, SND_FILENAME | SND_ASYNC );
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
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
