#include <windows.h>
#include <stdio.h>
#include <tchar.h>

#include <vector>

#define STRICT 1
#define WIN32_LEAN_AND_MEAN 1
#ifndef UNICODE
#define UNICODE
#endif


static void
PrintErrorMessage(const TCHAR *s, DWORD dwCode)
{
    // DWORD dwCode = GetLastError();
    LPVOID buf;
    if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS
        | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_MAX_WIDTH_MASK,
        NULL,
        dwCode,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &buf,
        0,
        NULL)) {

        const char *fmt = "%s 0x%X";
        int sz = snprintf(nullptr, 0, fmt, buf, dwCode);
        std::vector<char> msg(sz + 2);
        snprintf(&msg[0], msg.size(), fmt, buf, dwCode);

        MessageBox(NULL, _T(msg.data()), s, MB_OK);
        // _ftprintf(stderr, _T("%s: %s"), s, buf);
        fflush(stderr);
        LocalFree(buf);
    }
    else
        MessageBox(NULL, _T("unknown Windows error"), s, MB_OK);
        // _ftprintf(stderr, _T("%s: unknown Windows error\n"), s);
}


int main(int argc, char **argv)
{
    DWORD dwLastError;
    const TCHAR *wSZError = {"Error Message:\0"};
    if (argc==2)
    {
        char *end;
        dwLastError = strtol(argv[1], &end, 16); // atoi(argv[1]);
        printf("Test error code %d\n", dwLastError);
    }else{
        GetFileAttributes("FileNotexist.txt");
        dwLastError = GetLastError();
    }

    printf("Windows System Error:%d\n", dwLastError);
    PrintErrorMessage(wSZError, dwLastError);
    return dwLastError;
}