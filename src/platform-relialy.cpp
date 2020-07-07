#include <iostream>
// https://stackoverflow.com/questions/5919996/how-to-detect-reliably-mac-os-x-ios-linux-windows-in-c-preprocessor

#ifdef _WIN32
    //define something for Windows (32-bit and 64-bit, this part is common)
    #ifdef _WIN64
        #define msg "for Windows (64-bit only)"
    #else
        #define msg "for Windows (32-bit only)"
    #endif
#elif __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_IPHONE_SIMULATOR
       #define msg "for iOS Simulator"
    #elif TARGET_OS_IPHONE
       #define msg "for iOS device"
    #elif TARGET_OS_MAC
       #define msg "for Other kinds of Mac OS"
    #else
       #define msg "= "Unknown Apple platform""
     #endif
#elif __ANDROID__
    #define msg "for android"
#elif __linux__
    #define msg "for linux"
#elif __unix__ // all unices not caught above
    #define msg "for Unix"
#elif defined(_POSIX_VERSION)
    #define msg "for POSIX"
#else
    #define msg "Unknown compiler"
#endif

int main()
{
     std::cout << msg << std::endl;
}
