#include "lib.h"
#include <windows.h>
#include <iostream>
#include <cstdio>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

const char * getText()
{
    return "Test message...";
}

// LibTest implementation
const double LibTest::Pi = 3.14;

LibTest::LibTest ()
{
    cout << "LibTest inistance\n";
}

void LibTest::Test ()
{
    cout << "Test...\n";
}

int LibTest::Max (int a, int b)
{
    return a>b? a:b;
}

extern "C" BOOL WINAPI DllMain (
    HINSTANCE const instance,  // handle to DLL module
    DWORD     const reason,    // reason for calling function
    LPVOID    const reserved)  // reserved
{
    // freopen("log.txt", "a", stdout);

    // Perform actions based on the reason for calling.
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        // Initialize once for each new process.
        // Return FALSE to fail DLL load.
        // cout << "lib.cpp: DLL_PROCESS_ATTACH\n";
        printf("lib.cpp: DLL_PROCESS_ATTACH\n");
        break;

    case DLL_THREAD_ATTACH:
        // Do thread-specific initialization.
        // cout << "lib.cpp: DLL_THREAD_ATTACH\n";
        printf("lib.cpp: DLL_THREAD_ATTACH\n");
        break;

    case DLL_THREAD_DETACH:
        // Do thread-specific cleanup.
        // cout << "lib.cpp: DLL_THREAD_DETACH\n";
        printf("lib.cpp: DLL_THREAD_DETACH\n");
        break;

    case DLL_PROCESS_DETACH:
        // Perform any necessary cleanup.
        // cout << "lib.cpp: DLL_PROCESS_DETACH\n";
        printf("lib.cpp: DLL_PROCESS_DETACH\n");
        break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}