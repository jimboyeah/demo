#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include <sstream>

using namespace std;

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define EXPORT __declspec(dllexport)
    #define SHARED __attribute__((section ("Shared"), shared))
#else
    #define EXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif


EXPORT HHOOK HookStart( int hookID, HWND hWindow, DWORD dwThreadId );
EXPORT BOOL HookDown( HHOOK );

#define WM_HOOK         WM_USER + 1
#define WM_HOOKDESTORY  WM_USER + 2

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
