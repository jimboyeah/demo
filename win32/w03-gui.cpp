#pragma comment(lib,"winmm.lib")
#include <windows.h>
#include <sstream>

using namespace std;

static TCHAR szTitle[] = TEXT("GUI App");
static TCHAR szSound[] = TEXT( "c:\\windows\\media\\Windows Logon Sound.wav" );

LRESULT CALLBACK circle( HWND, UINT, WPARAM, LPARAM );

int WINAPI WinMain(HINSTANCE hApp, HINSTANCE hPre, LPSTR lpLine, int iCmd )
{
    HWND hWin;
    MSG msg;
    WNDCLASS winClass;

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
    
    stringstream ss;
    string sTitle;
    int i = 1;
    while(GetMessage( &msg, NULL, 0, 0 ) ){
        ss.clear();
        ss<<i++;
        ss>>sTitle;
        sTitle.insert( 0," - " ).insert( 0,szTitle );
        SetWindowText( hWin, sTitle.c_str() );
        TranslateMessage( &msg );
        DispatchMessage( &msg );
    }

    return msg.wParam;

}

LRESULT CALLBACK circle( HWND hWin, UINT iMsg, WPARAM wp, LPARAM lp ){
    switch( iMsg ){
    case WM_CREATE:
        PlaySound( szSound, NULL, SND_FILENAME | SND_ASYNC );
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc( hWin, iMsg, wp, lp);
}
