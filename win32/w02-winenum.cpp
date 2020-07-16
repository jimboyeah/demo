#include <windows.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct MyParam
{
    std::vector<HWND> *hWindows;
    DWORD pid;
} EnumHWndsArg, *LPEnumHWndsArg;

BOOL CALLBACK EnumProc( HWND hwnd, LPARAM lParam ){
    char buf[MAXWORD];
    char bufClass[MAXWORD];
    DWORD thread;
    EnumHWndsArg *ea = (LPEnumHWndsArg) lParam;
    ea->hWindows->push_back(hwnd);

    GetWindowTextA( hwnd, buf, MAXWORD );
    GetClassNameA( hwnd, bufClass, MAXWORD );
    thread = GetWindowThreadProcessId( hwnd, NULL );
    
    string title(buf);
    if(
        title==string("Default IME") || 
        title==string("Default IME") || 
        title==string("MSCTFIME UI")
    ) return true;
    cout << "Win: " << hwnd << " PID: " << thread << " WinClass:" << bufClass << " Title:" << buf << endl;
    return true;
}

int main(){
    EnumHWndsArg ea = {new std::vector<HWND>{}, 0};
    BOOL isok = EnumWindows( EnumProc,  (LPARAM)&ea);
    cout << "Windows Count: " << ea.hWindows->size() << endl;
    return 0;
}

