#pragma once

#ifndef LIB_H 
#define LIB_H 

// VS define LIB_EXPORT for DLL project
#ifdef LIB_EXPORTS
// #   define LIB_API __declspec(dllexport)
#   define LIB_API // use for module-define .def
#else
// #   define LIB_API __declspec(dllimport)
#   define LIB_API // use for module-define .def
#endif

class LIB_API LibTest
{
public:
    LibTest();
    void Test();
    const double G = 9.8;
    static const double Pi;
    // use Max avoid conflict with VS's macro max
    static int Max(int a, int b);

    // export friend
    // friend LIB_API LibTest operator+(const LibTest&a, const LibTest&b);
};

// add extern "C" to keep the symbol unchanged
extern "C" LIB_API int add(int x, int y);
extern "C" LIB_API const char * getText(void);
extern "C" LIB_API const double PI = 3.1415926;
// #define PI 3.1415926


#endif
