#ifndef lib_header
#define lib_header

#ifdef BUILD_DLL  
#define EXPORT __declspec(dllexport) 
#else  
#define EXPORT
#endif

extern "C" EXPORT bool CheckForMDAC(int a,int b );
int sum(int a, int b, int c);

#endif //lib_header