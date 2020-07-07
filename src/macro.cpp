#include <string>
#include <iostream>
#include <windows.h>
#include <fileapi.h>

using namespace std;

#define PI 3.1415926
#define pi "3.1415926"
#define FUCKMS "M$"

typedef unsigned int uint;

void OgldevFileError(const char* pFileName, uint line, const char* pFileError);

#define OGLDEV_FILE_ERROR(FileError) OgldevFileError(__FILE__, __LINE__, FileError);

void OgldevFileError(const char* pFileName, uint line, const char* pFileError)
{
#ifdef WIN32
    char msg[1000];
    _snprintf_s(msg, sizeof(msg), "%s:%d: unable to open file? no, just a `%s`", pFileName, line, pFileError);
    MessageBoxA(NULL, msg, NULL, 0);
#else
    fprintf(stderr, "%s:%d: unable to open file? no, just a `%s`\n", pFileName, line, pFileError);
#endif    
}

int main()
{
    OGLDEV_FILE_ERROR("demo from opengl-tutorial.org tutorial02 shader")
}