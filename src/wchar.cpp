#include <iostream> 
using namespace std; 
  
int main() 
{ 
    cout << "cout << 中文测试" << endl;
    printf("printf << 中文测试\n");

    setlocale(LC_ALL, "zh_CN.UTF-8");
    wchar_t w  = L'汉'; 
    wprintf(L"%lc\n", w);

    wchar_t ws[]  = L"wchar 中文测试"; //{0x496c, 0x496c};
    cout << "cout << wchar_t[] -> " << ws << endl;
    printf("printf wchar_t[] -> %s\n", ws);
    wprintf(L"wprintf %ls\n", ws);

    wcout << L"Wide character value:: " << ws << endl ; 
    wcout << L"Size of the wide char is:: " << sizeof(ws) << endl; 

    // wide-char type array string 
    wchar_t wtest[] = L"宽字符测试：" ; 
    wcout << wtest << endl; 
    wcout.flush();

    wchar_t wide;
    wscanf(L"%lf", &wide);
    // scanf("%lf", &wide);

    wcout << wide << "\n";

    return 0; 
} 