#include <windows.h>
#include <stdint.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std; 

typedef struct EnumHWndsArg
{
    std::vector<HWND> *vecHWnds;
    DWORD dwProcessId;
}EnumHWndsArg, *LPEnumHWndsArg;

HANDLE GetProcessHandleByPID(int pid)
{
    return OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
}

DWORD GetProcessIDByName(const char* pName)
{
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hSnapshot) {
        return 0;
    }
    PROCESSENTRY32 pe = { sizeof(pe) };
    for (BOOL ret = Process32First(hSnapshot, &pe); ret; ret = Process32Next(hSnapshot, &pe)) {
        if (strcmp(pe.szExeFile, pName) == 0) {
            CloseHandle(hSnapshot);
            return pe.th32ProcessID;
        }
        //printf("%-6d %s\n", pe.th32ProcessID, pe.szExeFile);
    }
    CloseHandle(hSnapshot);
    return 0;
}

BOOL CALLBACK lpEnumFunc(HWND hwnd, LPARAM lParam)
{
    EnumHWndsArg *pArg = (LPEnumHWndsArg)lParam;
    DWORD  processId;
    GetWindowThreadProcessId(hwnd, &processId);
    if (processId == pArg->dwProcessId)
    {
        pArg->vecHWnds->push_back(hwnd);
        printf("---> Enum Windows %p\n", hwnd);
    }
    return TRUE;
}

void GetHWndsByProcessID(DWORD processID, std::vector<HWND> &vecHWnds)
{
    EnumHWndsArg wi;
    wi.dwProcessId = processID;
    wi.vecHWnds = &vecHWnds;
    EnumWindows(lpEnumFunc, (LPARAM)&wi);
}

BOOL Toggle(const char *name,  int state=SW_SHOW){
    HWND hwin = FindWindowA( name, NULL );
    return ShowWindow( hwin, state );
}

int32_t main(int argc, char ** argv)
{
    if (argc==1){
        printf("Usage demo: toggle notepad.exe");
        return 0;
    }

    // DWORD pid = (DWROD)atoi(argv[1]);
    // HANDLE handle = GetCurrentProcess();
    DWORD pid = GetProcessIDByName(argv[1]);
    printf("%s pid = %u\n", argv[1], pid);

    if (pid == 0) return 0;

    char *wndName = new char[256];
    char *wndNameChild = new char[256];
    std::vector<HWND> vecHWnds;
    GetHWndsByProcessID(pid, vecHWnds);
    printf("vecHWnds.size() = %u\n", vecHWnds.size());
    for (const HWND &hwn : vecHWnds)
    {
        HWND parent = GetParent(hwn);
        GetClassName(parent, wndName, 256);
        GetClassName(parent, wndNameChild, 256);
        if (parent == NULL)
        {
            printf("%p --> Main Window [%s, %s]\n", hwn, wndName, wndNameChild);
        }
        else
        {
            printf("%p is child window of %p\n", hwn, parent);
        }
    }

    string act;
    string wndNameTip("Window Name:");
    for(; ;){
        cout << "options: show, hide, exit: ";
        cin >> act;
        if(act=="show"){
            cout << wndNameTip;
            cin >> act;
            if( act.length()>0 ) Toggle( act.c_str(), SW_SHOW );
        }else if( act=="hide"){
            cout << wndNameTip;
            cin >> act;
            if( act.length()>0 ) Toggle( act.c_str(), SW_HIDE );
        }else if( act=="exit") break;
    }

    // getchar();
    return 0;
}
