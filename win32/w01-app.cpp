#include <stdio.h>			// for printf
#include <windows.h>	// for WINAPI HINSTANCE MessageBox

#include <fstream>
#include <iostream>
using namespace std;

static string atitle = "Native Language Support";
static wstring wtitle = L"Native Language Support";
static string tipA = "UTF-8:\n";
static string tipW = "Unicode:\n";
static string amessage = "show 中国國語 in UTF8";
static wstring lmessage = L"show 中国國語 in long short*";
static wstring wmessage = TEXT(L"show 中国國語 in Unicode");
static wstring msgError = TEXT(L"Bad file to open");
// static wstring wmessage = L"show in Unicode";
// static wstring msgError = L"Bad file to open";

int WINAPI WinMain(HINSTANCE hApp, HINSTANCE prevApp, LPSTR cmdLine, int nCMD){ 
    return 1;
}

class App {
public:
	App(){
        testA();
        testW();
        cout << "amessage: " << amessage << endl;
        wcout << "lmessage: " << lmessage << endl;
        wcout << "wmessage: " << wmessage << endl;
	}
    void testA(){
        ofstream osf("./log.txt", ios::binary);
        if( !osf.bad() ){
            int size = amessage.size();
            osf << size << tipA.c_str();
            osf.write(amessage.c_str(), size);
            osf.close();
        }else{
            MessageBox(NULL, (const char*)msgError.c_str(), (const char*)wtitle.c_str(), MB_ICONEXCLAMATION);
        }
    }
    void testW(){
        wofstream osf("./logw.txt", ios::binary);
        if( !osf.bad() ){
            int size = wmessage.size();
            osf << size;
            osf.write( (wchar_t *)(tipW.c_str()), tipW.size());
            osf.write( wmessage.c_str(), size);
            osf.close();
        }else{
            MessageBox(NULL, (const char*)msgError.c_str(), (const char*)wtitle.c_str(), MB_ICONEXCLAMATION);
        }
    }
};

App app;