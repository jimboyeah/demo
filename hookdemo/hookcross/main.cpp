#include "../hooksrv/main.h"
#include <windows.h>
#include <sstream>

using namespace std;

static TCHAR szTitle[] = TEXT("Hook");
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

    return (int)msg.wParam;

}



extern EXPORT int hookCode;
extern EXPORT POINT SharedPoint;
extern EXPORT MOUSEHOOKSTRUCT SharedMSG;

UINT COUNT;
HHOOK MyHook;
UINT TIMER_HOOK = 1;
string tipText =  "Appication API HOOK Wating for a Wordpad.";

void CALLBACK Try2Hook(HWND hwin, UINT uMsg, UINT id, DWORD t){
    HWND hw = FindWindow( "WordPadClass",NULL );
    InvalidateRect( hWin, NULL, TRUE);

    if(hw && MyHook){
        //KillTimer( hWin,TIMER_HOOK );
        tipText = "Hooked for Wordpad.";
        UpdateWindow( hWin );
        return;
    }

    if(!hw && MyHook){
        HookDown( MyHook );
        MyHook = NULL;
        return;
    }

    if(!hw){
        tipText = "Waiting for a Wordpad.";
        UpdateWindow( hWin );
        return;
    }
    DWORD thread = GetWindowThreadProcessId( hw, NULL );
    MyHook = HookStart( WH_MOUSE, hWin, thread );
    HookStart( WH_JOURNALRECORD, hWin, NULL);
}

void SendToPad(const char * buf){
    string txt(buf);
    HWND hw = FindWindow( "WordPadClass",NULL );
    HWND  hc = FindWindowEx( hw, NULL,"RICHEDIT50W",NULL );
    if(!hc) return;
    for( unsigned int i=0; i<txt.length(); i++){
        SendMessage( hc, WM_CHAR, (char) txt[i], 0 );
    }
    SendMessage( hc, WM_KEYDOWN, VK_RETURN, 0 ); // "\r\n" for Wordpad;
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
    TIMERPROC cb = reinterpret_cast<TIMERPROC>(Try2Hook); // for VS97

    unsigned short val;
    char a[100];

    switch( iMsg ){
    case WM_CREATE:
        PlaySound( szSound, NULL, SND_FILENAME | SND_ASYNC );
        //PlaySound( "SystemStart", NULL, SND_ALIAS | SND_ASYNC );
        SetTimer( hWin, TIMER_HOOK,  1000, cb);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        HookDown( MyHook );
        MyHook = NULL;
        return 0;
    case WM_PAINT:
        hdc = BeginPaint( hWin, &ps);
        GetClientRect( hWin, &rect );

    val = GetKeyState(VK_PAUSE);
    //if( val ) PostQuitMessage(0);
    ss.clear();
    ss << COUNT++ << std::hex << " 0x" << val << " " << tipText;
    ss.getline(a, 100);

        DrawText( hdc, a, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER );
        EndPaint( hWin, &ps);
        return 0;
    case WM_HOOK:
        MOUSEHOOKSTRUCT hs = SharedMSG;
        POINT p = hs.pt;
        ss.clear();
        ss << szTitle << " - " << ++COUNT << std::hex << " msg:0x" << hookCode
            << " wp:0x" << wp << " lp:0x" << lp << " sp:0x"<< &SharedMSG
            << std::dec << " (" << SharedPoint.x << "," << SharedPoint.y << ")\n"
            << "hwnd:0x" << hs.hwnd << " hitTest:0x" << hs.wHitTestCode << " info:0x"
            << hs.dwExtraInfo << " (" << p.x << "," << p.y << ")" << "\n";
        ss.getline( buf, MAXBYTE-1);
        SetWindowText( hWin, buf );
        ss.getline( buf, MAXBYTE-1);
        SendToPad( buf );
        return 0;
    }

    return DefWindowProc( hWin, iMsg, wp, lp);
}
