#include <iostream>
#include <string>
#include <cerrno>
#include <cstdlib>
 
int main()
{
    const char* p = "10 20000000000000000000000 0x00FF 30 -40";
    char *end;
    std::cout << "Parsing '" << p << "':\n";
    for (long i = std::strtol(p, &end, 16);
         p != end;
         i = std::strtol(p, &end, 10))
    {
        std::cout << "'" << std::string(p, end-p) << "' -> ";
        p = end;
        if (errno == ERANGE){
            std::cout << "range error, got ";
            errno = 0;
        }
        std::cout << i << '\n';
    }
}