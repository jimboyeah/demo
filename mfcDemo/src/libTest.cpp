#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>

using namespace std;

typedef int (*AddFunc)(int a, int b);

void loadTest(int a, int b)
{
    HMODULE handle = LoadLibrary("dynamicLib_d.dll");
    cout << "Load DLL " << handle << endl;
    if (handle != NULL)
    {
        AddFunc add = (AddFunc)GetProcAddress(handle, "add");
        cout << "Load add function " << add << endl;
        if (add != NULL)
        {
            cout << "Test: " << a << " + " << b << " = " << add(a, b) << endl;
        }
        FreeLibrary(handle);
    }
}

int main(int argc, char ** argv)
{
    int a = 9, b = 8;
    if (argc == 3){
        a = atoi(argv[1]);
        b = atoi(argv[2]);
    }
    // cout << "Global constant PI: " << PI << endl;
    // cout << "LibTest::Pi: " << LibTest::Pi << endl;
    cout << "LibTest::Max(" << a << ", " << b << "): " << LibTest::Max(a, b) << endl;
    cout << "Test:" << a << " + " << b << " = " << add(a, b) << endl;
    cout << "Test: " << getText() << endl;

    LibTest lt;
    lt.Test();
    cout << "LibTest.G: " << lt.G << endl;

    loadTest(a, b);
    return add(a, b);
}

