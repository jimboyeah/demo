#include <windows.h>
#include <stdio.h>

int main()
{
    DWORD dwVersion = 0; 
    DWORD dwMajorVersion = 0;
    DWORD dwMinorVersion = 0; 
    DWORD dwBuild = 0;
    BOOL isNT = false;

    dwVersion = GetVersion();
 
    // Get the Windows version.
    dwMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
    dwMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));

    // Get the build number.
    if (dwVersion < 0x80000000){
        dwBuild = (DWORD)(HIWORD(dwVersion));
        isNT = true;
    }

    printf("Windows %sVersion is %d.%d (%d)\n", 
                isNT? "NT ":"",
                dwMajorVersion,
                dwMinorVersion,
                dwBuild);
    return 0;
}