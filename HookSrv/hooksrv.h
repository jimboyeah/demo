#include <windows.h>
#include <sstream>

using namespace std;

#define EXPORT __declspec(dllexport)
#define IMPORT extern _declspec(dllimport)
// IMPORT int hookCode;

EXPORT HHOOK HookStart( int, HWND, DWORD);
EXPORT BOOL HookDown( HHOOK );

#define WM_HOOK WM_USER + 1
#define WM_HOOKDESTORY WM_USER + 2
 
