/*
 * i18n Demo by Jimbowhy, compile it with TDM-GCC:
   g++ -o i18n i18n.cpp resource.res -lgdi32 -lkernel32 -ladvapi32 -lwinmm && i18n
 */

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <windows.h>
#include <mmsystem.h>

UINT LoadMessage( DWORD id, DWORD lang_ID, PTSTR buf, UINT size, ...)
{
	va_list  args;
	va_start(args,size);
	return FormatMessage( FORMAT_MESSAGE_FROM_HMODULE,NULL,
		id, lang_ID, buf, size, &args);
	va_end(  args );
}
The Animator's Survival Kit Animated-Richard Williams Animation Masterclass
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
	SetThreadLocale( zh_CN );


	CPINFOEX  cpi;
	GetCPInfoEx(CP_THREAD_ACP,0,&cpi);
	printf( "GetACP(%d) GetOEMCP(%d) \n", GetACP(), GetOEMCP() );
	printf( "GetCPInfoEx(%x) %s\n", cpi.CodePage, cpi.CodePageName );
	printf( "           GetThreadLocale(0x%x)\n", GetThreadLocale() );
	printf( "    GetSystemDefaultLangID(0x%x)\n", GetSystemDefaultLangID() );
	printf( "      GetSystemDefaultLCID(0x%x)\n", GetSystemDefaultLCID() );
	//printf( "GetSystemDefaultUILanguage(0x%x)\n", GetSystemDefaultUILanguage() );
	printf( "      GetUserDefaultLangID(0x%x)\n", GetUserDefaultLangID() );
	printf( "        GetUserDefaultLCID(0x%x)\n", GetUserDefaultLCID() );
	//printf( "  GetUserDefaultUILanguage(0x%x)\n", GetUserDefaultUILanguage() );

	char rs[1024];
	wchar_t *cs;

	HRSRC hrc = FindResource( NULL, MAKEINTRESOURCE(IDS_HELLO),RT_STRING );
	HGLOBAL hrs = LoadResource( NULL,hrc );
	cs = (WCHAR *)LockResource(hrs);
	printf(" Find: %x %d [%s]\n", hrc, cs, cs );
	hrc = FindResource( NULL, MAKEINTRESOURCE(IDDSTAR/16+1),RT_STRING );
	hrs = LoadResource( NULL,hrc );
	cs = (WCHAR *)LockResource(hrs);
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

	return 0;
}
