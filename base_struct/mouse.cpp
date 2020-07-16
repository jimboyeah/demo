/*
 * Console mouse Demo by Jimbowhy, compile it with TDM-GCC:
   g++ -o mouse mouse.cpp -lgdi32 -lwinmm && mouse
 */

#pragma comment(lib, "gdiplus.lib")
#define ULONG_PTR ULONG

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <gdiplus.h>
#include <mmsystem.h>

using namespace std;
using namespace Gdiplus;


typedef HWND (WINAPI *GCW)();
HWND GetConsoleWin()
{
    HMODULE hKernel32 = GetModuleHandle("kernel32");
    GCW f = (GCW)GetProcAddress(hKernel32,"GetConsoleWindow");
    return f();
}

typedef bool (WINAPI *TBLT)(HDC, int, int, int, int, HDC, int, int, int, int, UINT);
bool _TransparentBlt(HDC d, int x, int y, int dx, int dy, HDC s, int xs, int ys, int dxs, int dys, UINT ck)
{
    HMODULE h = LoadLibrary("msimg32.dll"); //GetModuleHandle
	if( !h ){
		if( GetLastError()==ERROR_MOD_NOT_FOUND ) cout << "ERROR_MOD_NOT_FOUND";
		return false;
	}
    TBLT f = (TBLT)GetProcAddress(h,"TransparentBlt");
	if( !f ){
		if( GetLastError()==ERROR_PROC_NOT_FOUND ) cout << "ERROR_PROC_NOT_FOUND";
		return false;
	}
    return f( d,x,y,dx,dy,s,xs,ys,dxs,dys,ck);
}

void drawCross(){
	HWND hwnd = GetConsoleWin();
	HDC  hdc  = GetDC( hwnd );

	HBITMAP mario = (HBITMAP)LoadImage(NULL, "res\\mario256.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BITMAP bmp;
	GetObject( mario, sizeof(BITMAP), &bmp );
	int w = bmp.bmWidth, h = bmp.bmHeight;
	/*
	BITMAPINFO bmi;
	unsigned char *bits = new unsigned char[bmp.bmHeight * bmp.bmWidthBytes];
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER); 
	bmi.bmiHeader.biWidth = bmp.bmWidth;
	bmi.bmiHeader.biHeight = -bmp.bmHeight;
	bmi.bmiHeader.biPlanes = bmp.bmPlanes;
	bmi.bmiHeader.biBitCount = bmp.bmBitsPixel;
	bmi.bmiHeader.biCompression = BI_RGB;
	GetDIBits( hdc, mario, 0, bmp.bmHeight, bits, &bmi, DIB_RGB_COLORS );
	*/
	//mario = CreateDIBitmap( hdc,&bmi.bmiHeader,CBM_INIT,bits,&bmi,DIB_PAL_COLORS);
	HDC dcs = CreateCompatibleDC(hdc);
	HDC dcm = CreateCompatibleDC(hdc);
	HBITMAP mono = CreateCompatibleBitmap( dcm,w,h);
	//HBITMAP mono = CreateBitmap( w,h,1,1,NULL );
	//int blue  = RGB(0x50,0x75,0xe0);
	int blue  = RGB(0x60,0x80,0xc0);
	int green = RGB(0xa0,0xe0,0x00);
	SelectObject( dcs,mario );
	SelectObject( dcm,mono );
	//SetBkMode ( dcs,TRANSPARENT );
	//SetTextColor( dcs,black );
	SetBkColor  ( dcs,blue );
	int x = 240, y = 240;
	BitBlt( dcm, 0, 0, w, h, dcs, 0, 0, SRCCOPY );
	BitBlt( dcs, 0, 0, w, h, dcm, 0, 0, 0x00220326); // Color-keying, NOT SRCERASE
	BitBlt( hdc, x, y, w, h, dcm, 0, 0, SRCAND );	 // optional
	BitBlt( hdc, x, y, w, h, dcs, 0, 0, SRCPAINT);

	/*
	//TransparentBlt( hdc,220,100,w,h,dcs,0,0,w,h,blue );
	
	/*if( GetDeviceCaps( hdc,CAPS1 ) & C1_TRANSPARENT ){
		cout << "\nC1_TRANSPARENT support! \n";
		int om = SetBkMode ( hdc,NEWTRANSPARENT );
		int oc = SetBkColor( hdc,RGB(0xe0,0x75,0x50) );
		BitBlt( hdc, 0, 0, bmp.bmWidth, bmp.bmHeight, dcs, 0, 0, SRCCOPY );
		SetBkMode ( hdc,om );
		SetBkColor( hdc,oc );
	}*/
	DeleteDC(dcm);
	DeleteDC(dcs);
	DeleteObject(mario);
	DeleteObject(mono);

	return ;
	RECT rect;
	GetClientRect( hwnd, &rect );
	HPEN hpen = CreatePen( PS_SOLID, 2, RGB(255, 0, 0) );
	SelectObject( hdc, hpen );
	LineTo( hdc, rect.right, rect.bottom );
	MoveToEx(hdc,rect.right, rect.top, NULL );
	LineTo( hdc, rect.left,  rect.bottom );
	ReleaseDC( hwnd,hdc );
}

void drawNoise(){
	HWND hwnd = GetConsoleWin();
	HDC  hdc  = GetDC( hwnd );

	HBITMAP hbmp = (HBITMAP)LoadImage(NULL, "mario16.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	DIBSECTION dib;
	BITMAPINFO bmi;
	BITMAPINFOHEADER bmih;
	BITMAP bmp;
	//unsigned char *bits = new unsigned char[8*1366*768];
	//dib.dsBm.bmBits = bits;
	//HBITMAP hbmi = CreateDIBSection( hdc, &bmi, DIB_PAL_COLORS, (void **)&bits, NULL, 0 );
	//GetObject( hbmp, sizeof(dib), &dib );
	//bmp = dib.dsBm;
	GetObject( hbmp, sizeof(BITMAP), &bmp );
	unsigned char *bits = new unsigned char[bmp.bmHeight * bmp.bmWidthBytes];
	//bmp.bmBits = bits;
	//GetBitmapBits( hbmp, bmp.bmHeight * bmp.bmWidthBytes, bits);
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER); 
	bmi.bmiHeader.biWidth = bmp.bmWidth;
	bmi.bmiHeader.biHeight = -bmp.bmHeight;
	bmi.bmiHeader.biPlanes = bmp.bmPlanes;
	bmi.bmiHeader.biBitCount = bmp.bmBitsPixel;
	bmi.bmiHeader.biCompression = BI_RGB;
	GetDIBits( hdc, hbmp, 0, bmp.bmHeight, bits, &bmi, DIB_RGB_COLORS );
	//bmp = dib.dsBm;
	//bmih = dib.dsBmih;
	//bmp.bmBits = (void **)bits;
	bmih = bmi.bmiHeader;
	cout << endl  << "  type:" << bmp.bmType; 
	cout << endl  << " width:" << bmp.bmWidth; 
	cout << endl  << "height:" << bmp.bmHeight; 
	cout << endl  << "wBytes:" << bmp.bmWidthBytes; 
	cout << endl  << "planes:" << bmp.bmPlanes; 
	cout << endl  << "p-bits:" << bmp.bmBitsPixel; 
	cout << endl  << "  bits:" << bmp.bmBits << endl; 

	cout<< "Bitmap Information:\n"
		<< "      bitmap size: " << bmih.biSize			<< endl
		<< "            width: " << bmih.biWidth			<< endl
		<< "           height: " << bmih.biHeight			<< endl
		<< "           planes: " << bmih.biPlanes			<< endl
		<< "             bits: " << bmih.biBitCount		<< endl
		<< "      compression: " << bmih.biCompression	<< endl
		<< "       image size: " << bmih.biSizeImage		<< endl
		<< "            X-PPM: " << bmih.biXPelsPerMeter	<< endl
		<< "            Y-PPM: " << bmih.biYPelsPerMeter	<< endl
		<< " index color used: " << bmih.biClrUsed		<< endl
		<< "  important index: " << bmih.biClrImportant	<< endl
		<< endl;

	int x,y,l;
	for( x=0; x<bmp.bmWidth; x++ ){
		for( y=0; y<bmp.bmHeight; y++){
			l = (x+y*bmp.bmWidth)*4;
			int color = RGB(bits[l+2],bits[l+1], bits[l]);
			if( color==0xda7c4e||color==0x800000||color==0xe07550||color==0xff0000 )
				continue; // Transparent sky blue
			SetPixel( hdc, x+240, y, color );
		}
	}
	ReleaseDC(NULL,hdc); 
	DeleteDC(hdc); 
	DeleteObject(hbmp); 
}

void setConsoleColor(){
	HANDLE hcmd;
	hcmd = GetStdHandle( -11 ); //STD_OUTPUT_HANDLE (DWORD)(0xfffffff5)
	SetConsoleTextAttribute( hcmd, BACKGROUND_RED | BACKGROUND_GREEN );
	cout<< string( 80, 'X' );
}

void printConsoleInfo()
{
	CONSOLE_SCREEN_BUFFER_INFO bi;
	HANDLE hao = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo( hao, &bi );
	COORD size = bi.dwSize;
	COORD pos  = bi.dwCursorPosition;
	COORD win = bi.dwMaximumWindowSize; 
	SMALL_RECT v = bi.srWindow;
	cout<< "Connsole Screen Buffer Infomation:" << endl
		<< "            size: " << size.X << "," << size.Y << endl
		<< " cursor position: " <<  pos.X << "," <<  pos.Y << endl
		<< "     view window: " << v.Top << "," << v.Right << "," << v.Bottom << "," << v.Left << endl
		<< "      max window: " <<  win.X << "," << win.Y << endl;
	//SetConsoleWindowInfo( hao,true,&v );
	//CloseHandle( hao );
}

COORD SetCursorPositionRight(int ost)
{
	CONSOLE_SCREEN_BUFFER_INFO bi;
	HANDLE hao = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo( hao, &bi );
	COORD size = bi.dwSize;
	COORD pos  = bi.dwCursorPosition;
	pos.X = size.X - ost;
	SetConsoleCursorPosition( hao,pos );
	return pos;
	//CloseHandle( hao );
}

COORD GetCursorPositionPixel(COORD poc)
{
	HWND hwnd = GetConsoleWin();
	RECT rect;
	GetClientRect( hwnd, &rect );

	CONSOLE_SCREEN_BUFFER_INFO bi;
	HANDLE hao = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo( hao, &bi );

	COORD pos  = bi.dwCursorPosition;
	SMALL_RECT v = bi.srWindow;
	pos.X = poc.X*(rect.right/v.Right);
	pos.Y = poc.Y*(rect.bottom/v.Bottom);
	return pos;
}

//SetConsoleCtrlHandler(ConsoleHandlerRoutine, true);
BOOL WINAPI ConsoleHandlerRoutine( DWORD t)
{
	string tm[] = { "CTRL_C_EVENT","CTRL_BREAK_EVENT", "CTRL_CLOSE_EVENT", 
					"CTRL_LOGOFF_EVENT", "CTRL_SHUTDOWN_EVENT" };
	cout << tm[t] << "\t";
	return false;
}

void CmdProc(UINT msg, WPARAM wp, LPARAM lp)
{
	switch(msg){
		case WM_KEYDOWN: // 256
		cout << "CmdProc WM_KEYDOWN:" << wp;
		break;
		case WM_KEYUP:	 // 257
		cout << "CmdProc WM_KEYUP:" << wp;
		break;
	}
	cout << endl;
}

void CmdMessageLoop()
{
	MSG msg;
	int pq = 0;
	static int c;
	PostMessage( NULL, WM_USER+1, 9, 8 );
	//PostMessage( FindWindow(NULL,"bitmap"), WM_QUIT, 9, 8 );
	while( int r = GetMessage(&msg,NULL,0,0) ) { 
		cout << "CmdMessageLoop:" << msg.message << " WM_USER:" << WM_USER << " " ;
		if (r != -1) { 
			CmdProc(msg.message, msg.wParam, msg.lParam); 
		}
		DispatchMessage(&msg); // for SetTimer
			return;
	}
}

int main(int argc, char *args[] ){

	HWND hwnd = GetConsoleWin();
	HDC  hdc  = GetDC( hwnd );
	
	drawCross();
	drawNoise();

	printConsoleInfo();

	CmdMessageLoop();

	HANDLE hao = GetStdHandle( STD_OUTPUT_HANDLE); 
	HANDLE hai = GetStdHandle( STD_INPUT_HANDLE );
	if( hai==INVALID_HANDLE_VALUE ) cout << "INVALID_HANDLE_VALUE" << endl;
	SetConsoleMode( hai, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT );
	
	INPUT_RECORD buffer[4];
	DWORD numberRead, numberWrited;
	COORD post = {0,0};

	char txt[80];

	while( true ){
		ReadConsoleInput( hai, buffer, 4, &numberRead);
		for(int i=0; i<numberRead; i++){
			INPUT_RECORD &ir = buffer[i];
			KEY_EVENT_RECORD &ike = ir.Event.KeyEvent;
			MENU_EVENT_RECORD &imu = ir.Event.MenuEvent;
			FOCUS_EVENT_RECORD &ife = ir.Event.FocusEvent;
			WINDOW_BUFFER_SIZE_RECORD &iwb = ir.Event.WindowBufferSizeEvent;
			MOUSE_EVENT_RECORD &ime = ir.Event.MouseEvent;
			COORD pos = ime.dwMousePosition;
			DWORD lp;
			char c = ike.uChar.AsciiChar;
			string mi;
			switch( ir.EventType ){
				case KEY_EVENT:
					lp = 0xd0000000 | ike.wRepeatCount | (ike.wVirtualScanCode<<16) | (ike.dwControlKeyState!=0)<<24;
					if( ike.bKeyDown ) PostMessage( NULL, WM_KEYDOWN, ike.wVirtualKeyCode, lp);
					sprintf( txt, " Key %c Down(%x) VK(%x) Rep(%x) ScanCode(%x) \n", 
						c, ike.bKeyDown, ike.wVirtualKeyCode, ike.wRepeatCount, ike.wVirtualScanCode );
					post = SetCursorPositionRight(strlen(txt)+30);
					WriteConsoleOutputCharacter( hao,txt,strlen(txt),post,&numberWrited );
					if( 'x'==c || ike.wVirtualKeyCode==VK_ESCAPE ){
						cout << "bye, programme exit.";
						return 0;
					}
					break;
				case MOUSE_EVENT:
					mi += ime.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED? "LEFT ":"";
					mi += ime.dwButtonState==RIGHTMOST_BUTTON_PRESSED? "RIGHT ":"";
					mi += ime.dwEventFlags==MOUSE_WHEELED? "WHEELED ":""; // WHEELED 0x0008
					mi += ime.dwEventFlags==MOUSE_MOVED? "MOVED ":"";
					mi += ime.dwEventFlags==DOUBLE_CLICK? "CLICK ":"";
					mi += ime.dwControlKeyState==LEFT_CTRL_PRESSED? "LEFT_CTRL ":"";
					mi += ime.dwControlKeyState==LEFT_ALT_PRESSED? "LEFT_ALT ":"";
					mi += ime.dwControlKeyState==SHIFT_PRESSED? "SHIFT ":"";
					mi += ime.dwControlKeyState==ENHANCED_KEY? "ENHANCED_KEY ":"";
					mi += ime.dwControlKeyState==CAPSLOCK_ON? "CAPSLOCK_ON ":"";
					mi += ime.dwControlKeyState==NUMLOCK_ON? "NUMLOCK_ON ":"";
					mi += ime.dwControlKeyState==SCROLLLOCK_ON? "SCROLLLOCK_ON ":"";
					sprintf(txt, " Mouse(%d,%d) %s ", pos.X, pos.Y, mi.data() );
					post = SetCursorPositionRight(strlen(txt)+1);
					WriteConsoleOutputCharacter( hao,txt,strlen(txt),post,&numberWrited );
					//WriteConsoleOutput();
					//WriteConsole( hao,txt,strlen(txt),&numberWrited,NULL );
					pos = GetCursorPositionPixel(pos);
					SetPixel( hdc, pos.X, pos.Y, RGB(0x80,0xff,0x60) );
					break;
				case FOCUS_EVENT:
					printf(" Focus %d ", ife.bSetFocus );
					break;
				case MENU_EVENT:
					printf(" Menu %d ", imu.dwCommandId );
					break;
				case WINDOW_BUFFER_SIZE_EVENT:
					printf("Window buffer(%d, %d)", iwb.dwSize.X, iwb.dwSize.Y);
					break;
			}
		}
	}
	CloseHandle( hai );
	CloseHandle( hao );
	return 0;
}

