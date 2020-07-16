/*
 * Resource Demo by Jimbowhy, compile it with TDM-GCC:
   g++ -o resource resource.cpp resource.res -lgdi32 -lkernel32 -ladvapi32 -lwinmm && resource
   cls && nmake BUILD=RELEASE resource && resource

	#include <wchar.h>
	#include <tchar.h>
 */

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <clocale>
#include <windows.h>
#include <winnls.h>
#include <mmsystem.h>
#include "res\res.h"

typedef HWND (WINAPI *GCW)();
HWND GetConsoleWin()
{
    HMODULE hKernel32 = GetModuleHandle(("kernel32"));
    GCW f = (GCW)GetProcAddress(hKernel32,"GetConsoleWindow");
    return f();
}

HWND wconsole = GetConsoleWin();
void CALLBACK TimeSetProc( UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2 )
{
	static int count;
	char title[64];
	if( count>99 ) exit(0);
	POINT p;
	GetCursorPos(&p);
	ScreenToClient(wconsole,&p);
	sprintf( title, "TimeSet %d (%d,%d) %x", ++count,p.x,p.y,dwUser );
	SetConsoleTitle( title );
	HDC idc = GetDC( wconsole ); //GetConsoleWindow()
	HICON wx = *((HICON*) dwUser);
	DrawIcon( idc, p.x, p.y, wx );
}

void Loop()
{
	HANDLE hai = GetStdHandle( STD_INPUT_HANDLE );
	if( !hai ) {
		printf("GetStdHandle(%d)!\n", GetLastError() );
		return ;
	}
	SetConsoleMode( hai, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT );
	INPUT_RECORD buffer[4];
	DWORD numberRead;

	printf("------=========Press ESC/x to quit=========-------\n");
	while( true ){
		ReadConsoleInput( hai, buffer, 2, &numberRead);
		for(int i=0; i<numberRead; i++){
			KEY_EVENT_RECORD   &ike = buffer[i].Event.KeyEvent;
			char c = ike.uChar.AsciiChar;
			switch( buffer[i].EventType ){
				case KEY_EVENT:
					if( c=='x' || ike.wVirtualKeyCode==VK_ESCAPE ) return ;
					break;
			}
		}
	}
}

UINT LoadMessage( DWORD id, DWORD lang_ID, PTSTR buf, UINT size, ...)
{
	va_list  args;
	va_start(args,size);
	return FormatMessage( FORMAT_MESSAGE_FROM_HMODULE,NULL,
		id, lang_ID, buf, size, &args);
	va_end(  args );
}

char * GetTableString(HMODULE h, UINT ID, DWORD wLanguage=LANG_NEUTRAL)
{
	HRSRC rs = FindResourceEx( h,RT_STRING,MAKEINTRESOURCE(ID/16+1),wLanguage);
	if( !rs ) return NULL;
	HGLOBAL rc = LoadResource( h,rs );
	if( !rc ) return NULL;
	wchar_t * s = (wchar_t*) rc;
	int i = 0, j = 0, c = 0;
	for( i=0; i<=ID%16; i++ ) {
		if( *s ){
			s += c;
			c = *s; // element length
			s++;
		}else s++;
	}
	if( c==0 ) return NULL;
	// The unicode string directory element.
	char *t = new char[ c*2 ]; // double size in case UTF8 3byte per MBS' char
	int size = (c*2)*sizeof(char);
	//wcsncpy( t, s, c );
	memset( t, 0, size );
	WideCharToMultiByte( CP_UTF8,0,s,c,(char *)t,size,NULL,NULL);
	printf("\tL:%2d UTF8:%s \n\t", c, t);
	for(  j=0; j<c; j++) printf("0x%02x ", (unsigned char)((char*)t)[j] );
	memset( t, 0, size );
	WideCharToMultiByte( CP_THREAD_ACP,0,s,c,(char *)t,size,NULL,NULL); //CP_ACP
	printf("\n\tL:%2d  ACP:%s \n\t", c, t);
	for(  j=0; j<c; j++) printf("0x%02x ", (unsigned char)((char*)t)[j] );
	printf("\n");
	return t;
}

int main(){

	printf("\n--------====== use resource string & i18n ======---------\n");
	DWORD   DEU = MAKELANGID( LANG_GERMAN, SUBLANG_GERMAN );
	DWORD  enNU = MAKELANGID( LANG_ENGLISH,SUBLANG_NEUTRAL );
	DWORD  enUK = MAKELANGID( LANG_ENGLISH,SUBLANG_ENGLISH_UK );
	DWORD  enUS = MAKELANGID( LANG_ENGLISH,SUBLANG_ENGLISH_US );
	DWORD  zhCN = MAKELANGID( LANG_CHINESE,SUBLANG_CHINESE_SIMPLIFIED );
	DWORD  zhTW = MAKELANGID( LANG_CHINESE,SUBLANG_CHINESE_TRADITIONAL );
	DWORD en_NU = MAKELCID( enNU, SORT_DEFAULT );
	DWORD en_UK = MAKELCID( enUK, SORT_DEFAULT );
	DWORD en_US = MAKELCID( enUS, SORT_DEFAULT );
	DWORD zh_CN = MAKELCID( zhCN, SORT_DEFAULT );
	DWORD zh_TW = MAKELCID( zhTW, SORT_DEFAULT );

	//setlocale( LC_ALL, "English_UK" );
	//setlocale( LC_ALL, "English_United States.1252" );
	//setlocale( LC_ALL, "chinese-simplified" );
	//setlocale( LC_ALL, "chinese-traditional" );
	//SetThreadLocale( LOCALE_SYSTEM_DEFAULT );
	//SetThreadLocale( LOCALE_USER_DEFAULT );
	//SetThreadLocale( zh_CN );

	//CPINFOEX  cpi;
	//GetCPInfoEx(CP_THREAD_ACP,0,&cpi);
	//for( int i=0; i<40; i++) printf(" 0x%02x", ((unsigned char*)cpi.CodePageName)[i]);
	printf( "GetConsoleCP(%d)\n", GetConsoleCP() );
	printf( "GetConsoleOutputCP(%d)\n", GetConsoleOutputCP() );
	printf( "GetACP(%d) GetOEMCP(%d) \n", GetACP(), GetOEMCP() );
	//printf( "GetCPInfoEx(%d) %s\n", cpi.CodePage, cpi.CodePageName );
	printf( "           GetThreadLocale(0x%x)\n", GetThreadLocale() );
	printf( "    GetSystemDefaultLangID(0x%x)\n", GetSystemDefaultLangID() );
	printf( "      GetSystemDefaultLCID(0x%x)\n", GetSystemDefaultLCID() );
	//printf( "GetSystemDefaultUILanguage(0x%x)\n", GetSystemDefaultUILanguage() );
	printf( "      GetUserDefaultLangID(0x%x)\n", GetUserDefaultLangID() );
	printf( "        GetUserDefaultLCID(0x%x)\n", GetUserDefaultLCID() );
	//printf( "  GetUserDefaultUILanguage(0x%x)\n", GetUserDefaultUILanguage() );

	char rs[1024];
	char *cs;

	HRSRC hrc = FindResource( NULL, MAKEINTRESOURCE(IDS_HELLO),RT_STRING );
	HGLOBAL hrs = LoadResource( NULL,hrc );
	//cs = (char *)LockResource(hrs);
	cs = reinterpret_cast<char *>(LockResource(hrs));
	printf(" Find: %x %d [%s]\n", hrc, cs, cs );
	hrc = FindResource( NULL, MAKEINTRESOURCE(IDDSTAR/16+1),RT_STRING );
	hrs = LoadResource( NULL,hrc );
	cs = reinterpret_cast<char *>(LockResource(hrs));
	printf(" Find: %x %d [%s]\n", hrc, cs, cs );

	LoadString( NULL,IDS_HELLO,rs,1024 );
	printf( "LoadString: %s \n", rs );
	LoadString( NULL,IDDSTAR,rs,1024 );
	printf( "LoadString: %s \n", rs );

	cs = GetTableString( NULL,IDS_HELLO, LANG_NEUTRAL);
	printf("GetTableString Neutral: %s \n\n", cs);
	cs = GetTableString( NULL,IDS_HELLO, LANG_ENGLISH );
	printf("GetTableString English: %s \n\n", cs);
	cs = GetTableString( NULL,IDS_HELLO, enUK );
	printf("   GetTableString enUK: %s \n\n", cs);
	cs = GetTableString( NULL,IDS_HELLO, zhTW );
	printf("   GetTableString zhTW: %s \n\n", cs);
	cs = GetTableString( NULL,IDS_HELLO, zhCN );
	printf("   GetTableString zhCN: %s \n\n", cs);
	cs = GetTableString( NULL,IDS_HELLO, 0x0804 );
	printf(" GetTableString 0x0804: %s \n\n", cs);

	cs = GetTableString( NULL,IDDSTAR, LANG_NEUTRAL );
	printf("GetTableString Neutral: %s \n\n", cs);
	cs = GetTableString( NULL,IDDSTAR, LANG_ENGLISH );
	printf("GetTableString English: %s \n\n", cs);
	cs = GetTableString( NULL,IDDSTAR, enUK );
	printf("   GetTableString enUK: %s \n\n", cs);
	cs = GetTableString( NULL,IDDSTAR, zhCN );
	printf("   GetTableString zhCN: %s \n\n", cs);
	cs = GetTableString( NULL,IDDSTAR, zhTW );
	printf("   GetTableString zhTW: %s \n\n", cs);



	printf("\n--------====== use resource messagetable ======---------\n");
	char app[] = "Res.exe";
	char user[64];
	DWORD ulen = 64;
	GetUserName( user,&ulen );
    LoadMessage( EVENT_STARTED_BY, enUS, rs, 1024, app, user);
	printf("enUS: %s", rs);
    LoadMessage( EVENT_STARTED_BY, DEU, rs, 1024, app, user);
	printf("DEU: %s", rs);
    LoadMessage( EVENT_STARTED_BY, zhTW, rs, 1024, app, user);
	printf("zhTW: %s", rs);
    LoadMessage( EVENT_STARTED_BY, zhCN, rs, 1024, app, user);
	printf("zhCN: %s", rs);
	LoadMessage( EVENT_STARTED_BY, LANG_NEUTRAL, rs, 1024, app, user );
	printf("Neutral: %s" , rs);

	printf("\n--------====== use resource wave ======---------\n");
	printf( "wave play \n", rs );
	HRSRC ding_inf = FindResource( NULL, "DING", "WAVE");
	if( !ding_inf ) printf(" error FindResource %d\n", GetLastError() );
	HGLOBAL ding = LoadResource( NULL,ding_inf );
	//sndPlaySound( (char*)ding, SND_MEMORY | SND_SYNC | SND_NODEFAULT ); // this OK!
	if( !ding ) printf(" error LoadResource %d\n", GetLastError() );
	HANDLE wave = LockResource( ding );
	if( !wave ) printf(" error LockResource %d\n", GetLastError() );
	sndPlaySound( (char*)wave, SND_MEMORY | SND_SYNC | SND_NODEFAULT );
	UnlockResource( wave );
	FreeResource( ding );

	printf("\n--------====== use resource icon ======---------\n");
	HICON wx = LoadIcon( GetModuleHandle(NULL),"WxIcon" );
	if( !wx ) printf(" error LoadIcon %d\n", GetLastError() );
    MMRESULT mm = timeSetEvent( 1000/6,0,TimeSetProc,(DWORD)&wx,TIME_PERIODIC);


	printf("\n--------====== use resource bitmap ======---------\n");
	HBITMAP mario = LoadBitmap( GetModuleHandle(NULL),(char*)(16) );
	if( !mario ) printf(" error LoadBitmap %d\n", GetLastError() );
	HANDLE hm = LoadImage(NULL, "mario256.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	//mario = (HBITMAP)hm;

	HDC hdc = GetDC( GetConsoleWin() ); //GetConsoleWindow()
	HDC mask = CreateCompatibleDC(hdc);
	HDC draw = CreateCompatibleDC(hdc);
	//int blue  = RGB(0x60,0x80,0xc0);
	int blue  = RGB(0x50,0x75,0xe0);
	int white = RGB(0xff,0xff,0xff);
	int black = RGB(0x00,0x00,0x00);
	int sw = GetSystemMetrics(SM_CXSCREEN);//GetDeviceCaps( mask,ASPECTX );
	int sh = GetSystemMetrics(SM_CYSCREEN);//GetDeviceCaps( mask,ASPECTY );
	BITMAP bmp;
	GetObject( mario, sizeof(BITMAP), &bmp );
	int w = bmp.bmWidth, h = bmp.bmHeight;
	HBITMAP mono = CreateCompatibleBitmap( mask, w, h );
	SelectObject( mask,mono );
	SelectObject( draw,mario );
	printf(" Bitmap size (%d,%d) Screen size(%d,%d)\n", w, h, sw, sh);
	SetBkColor( draw, blue );
	BitBlt( mask, 0, 0, w, h, draw, 0, 0, SRCCOPY );
	BitBlt( hdc,  w+120, 2*h, w, h, mask, 0, 0, SRCAND );
	BitBlt( draw, 0, 0, w, h, mask, 0, 0, 0x00220326); // Color-keying
	BitBlt( hdc,  w+120, 2*h, w, h, draw, 0, 0, SRCPAINT);
	/*
	BitBlt( hdc, 0*w, 0, w, h, draw, 0, 0, SRCCOPY );
		BitBlt( mask, 0, 0, w, h, draw, 0, 0, SRCCOPY );
	BitBlt( hdc, 4*w, 0, w, h, mask, 0, 0, SRCAND);
	BitBlt( hdc, 1*w, 0, w, h, mask, 0, 0, SRCCOPY );
		BitBlt( mask, 0, 0, w, h, mask, 0, 0, NOTSRCCOPY );
	BitBlt( hdc, 2*w, 0, w, h, mask, 0, 0, SRCCOPY );
		//SetTextColor( draw, white );
		SetBkColor( draw, white );
		BitBlt( draw, 0, 0, w, h, mask, 0, 0, SRCAND );
	BitBlt( hdc, 3*w, 0, w, h, draw, 0, 0, SRCCOPY );
		BitBlt( hdc, 4*w, 0, w, h, draw, 0, 0, SRCPAINT);
	*/
	DeleteDC(hdc);
	DeleteDC(mask);
	DeleteDC(draw);
	DeleteObject(mario);
	DeleteObject(mono);

	Loop();
	return 0;
}
