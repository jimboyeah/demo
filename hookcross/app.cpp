#pragma comment(lib,"winmm.lib")
#include <windows.h>
#include <sstream>
#include "app.h"

using namespace std;

static TCHAR szTitle[] = TEXT("Hook");
static TCHAR szSound[] = TEXT( "c:\\windows\\media\\Windows Logon Sound.wav" );
string tipText =  "Appication API HOOK Wating for a Wordpad.";

#include "../HookSrv/hooksrv.h"
//#pragma comment(lib,"../HookSrv/Debug/hooksrv.lib")
#pragma comment(lib,"../x64/Release/hooksrv.lib")

extern __declspec(dllimport) int hookCode;
//extern __declspec(dllimport) MOUSEHOOKSTRUCT SharedMSG;

HWND hWin;
HINSTANCE hAPP;
UINT COUNT;
HHOOK MyHook;
UINT TIMER_HOOK = 1;
char * MainClass = "notepad"; //"WordPadClass";
char * SubClass = "Edit"; //"RICHEDIT50W";
    

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

    return (int)msg.wParam;

}


void CALLBACK TimerProc(HWND hwin, UINT uMsg, UINT id, DWORD t){
    HWND hw = FindWindow( MainClass,NULL );
    if(!hw) return;
    DWORD thread = GetWindowThreadProcessId( hw, NULL );
    MyHook = HookStart( WH_MOUSE, hWin,  thread );
    if(MyHook){
        KillTimer( hWin,TIMER_HOOK );
        tipText = "Hooked for Wordpad.";
        RECT rect;
        GetClientRect( hWin, &rect );
        InvalidateRect( hWin, &rect, TRUE);
        UpdateWindow( hWin );
    }
}

void SendToPad(const char * buf){
    string txt(buf);
    HWND hw = FindWindow( MainClass,NULL );
    HWND  hc = FindWindowEx( hw, NULL,SubClass,NULL );
    if(!hc) return;
    for( int i=0; i<txt.length(); i++){
        SendMessage( hc, WM_CHAR, (char) txt[i], 0 );
    }
    SendMessage( hc, WM_CHAR, '\r\n', 0 );
    //SendMessage( hw, WM_KEYDOWN, VK_RETURN, 0 ); // "\r\n" for Wordpad;
}

const char * byte2hex(byte *bytes){
    stringstream ss;
    ss << std::hex;
    int len = 20;//string((char*)bytes).length();
    for(int i=0; i<len; i++){
        int j = (int)bytes[i];
        ss << " 0x" << (j<16?"0":"") << j;
    }
    string so = ss.str();
	string *ps = new string(so);// allocate memory return to caller
    const char *p = ps->c_str();
    return p;
}


LRESULT CALLBACK circle( HWND hWin, UINT iMsg, WPARAM wp, LPARAM lp ){
    HDC         hdc ;
    PAINTSTRUCT ps ;
    RECT        rect ;
    char buf[MAXBYTE];
    stringstream ss;
    TIMERPROC cb = reinterpret_cast<TIMERPROC>(TimerProc); // for VS97
	POINT p;
	MOUSEHOOKSTRUCT hs ;

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
        DrawText( hdc, tipText.c_str(), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER );
        EndPaint( hWin, &ps);
        return 0;
    case WM_HOOK:
        hs = *((MOUSEHOOKSTRUCT*)lp);
		p = hs.pt;
        ss << szTitle << " - " << ++COUNT << std::hex << " msg:0x" << hookCode
            << " wp:0x" << wp << " lp:0x" << lp << " sp:0x"<< &hs 
            << std::dec << " (" << p.x << "," << p.y << ")\n"
            << "hwnd:0x" << hs.hwnd << " hitTest:0x" << hs.wHitTestCode << " info:0x" << hs.dwExtraInfo << " (" << p.x << "," << p.y << ")" << "\n";
        ss.getline( buf, MAXBYTE-1);
        SetWindowText( hWin, buf );
        ss.getline( buf, MAXBYTE-1);
        SendToPad( buf );
        return 0;
    case WM_HOOKDESTORY:
        SetTimer( hWin, TIMER_HOOK,  1000, cb);
        tipText = "Waiting for a Wordpad.";
        RECT rect;
        GetClientRect( hWin, &rect );
        InvalidateRect( hWin, &rect, TRUE);
        UpdateWindow( hWin );
        return 0;
    }

    return DefWindowProc( hWin, iMsg, wp, lp);
}
