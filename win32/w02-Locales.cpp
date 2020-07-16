#include "windows.h"

#include <iostream>
#include <string.h>
using namespace std;

#define STR_LEN 32

int CALLBACK enumLocales( LPTSTR lpLocaleString ){

	LCID uiCurLocale;
	TCHAR szCurName[STR_LEN];

	if (!lpLocaleString) return FALSE;

	uiCurLocale = atoi(lpLocaleString);

	int size = GetLocaleInfo(uiCurLocale, LOCALE_SLANGUAGE, szCurName, STR_LEN);
	if(size==0){
		DWORD error = GetLastError();
		switch(error){
		case ERROR_INSUFFICIENT_BUFFER:
		case ERROR_INVALID_FLAGS:
		case ERROR_INVALID_PARAMETER:
		default:
			; //cerr<<"Error matched."<<endl;
		}
	}else{
		string sLanguage = (szCurName);
		cout<<"Locales:"<<lpLocaleString<<" LangID:"<<sLanguage.substr(0,size).c_str()<<endl;
	}
    return 1;
}

int main(void)
{
    LOCALE_ENUMPROC esp = enumLocales;
    BOOL isOK = EnumSystemLocales( esp, LCID_INSTALLED);
	return 0;
}
