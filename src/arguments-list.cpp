#include <cstdarg>
#include <iostream>
 
using namespace std;
 
void print ( const char * fmt, ... )
{
    va_list arguments;                     // A place to store the list of arguments
    va_start ( arguments, fmt );           // Initializing arguments to store all values after fmt
    char * arg;
    for ( ;; )
    {
        arg = va_arg (arguments, char*);  // Adds the next value in argument list to sum.
        if (arg == NULL) break;
        printf("%u %s %d\n", &arg, fmt, &arg);
        cout << arg;
    }
    va_end ( arguments );                  // Cleans up the list
}

int main()
{
    print("\t-->", "Apple", "Pineapple", "Applewife", "Applewood", NULL);
}