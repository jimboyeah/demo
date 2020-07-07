#include <iostream>
#include <string>
#include <fileapi.h>
#include <windows.h>

using namespace std;

#define FUCKMS NULL

int main(int argc, char *argv[])
{
    string file = "../src/file-text.cpp";
    if(argc==2) file = argv[1];

    HANDLE fh = CreateFileA(file.c_str(), FILE_GENERIC_READ, FILE_SHARE_READ,
        FUCKMS, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, FUCKMS);

    if (INVALID_HANDLE_VALUE == fh)
    {
        long dw = GetLastError();
        char *lpMsgBuf;

        cout << "GetLastError " << dw << endl;

        FormatMessage (
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
            FUCKMS,
            dw,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
            (LPTSTR) &lpMsgBuf,
            0, FUCKMS );

        cout << lpMsgBuf << endl;
        return 1;
    }

    long unsigned int size = GetFileSize(fh, FUCKMS);
    char* buf = (char *)LocalAlloc(LPTR, size);

    if (!ReadFile(fh, buf, size, &size, FUCKMS)) {
        cout << "Error for ReadFile" << GetLastError() << endl;
    };

    CloseHandle(fh); 
    string content(buf, size);

    cout << content << endl;
}