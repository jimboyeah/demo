// #include <boost/format.hpp>
// #include <format> // C++20

#include <string>
#include <vector>
#include <cstdarg>

std::string format(const char *pszFmt, ...)
{
    std::string str;
    va_list args;
    va_start(args, pszFmt);
    {
        int nLength = _vscprintf(pszFmt, args);
        nLength += 1;  // plus 1 for null-terminator
        std::vector<char> vectorChars(nLength);
        _vsnprintf(vectorChars.data(), nLength, pszFmt, args);
        str.assign(vectorChars.data());
    }
    va_end(args);
    return str;
}

int main()
{
    char c = 'A';
    std::string str = format("c=%c", c);  // c=A
         
    int i = 10;
    str = format("i=%c", i);  // i=10
     
    double d = 1.5;
    str = format("d=%f", d);  // d = 1.500000
     
    std::string strName = ("txdy");
    str = format("I am %s", strName.c_str());  // I am txdy
}
