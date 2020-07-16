#include <string>
#include <cstdio>
#include <conio.h>
#include <iostream>

// https://www.runoob.com/w3cnote/c-get-keycode.html
void tryKey()
{
    for(int i: {1,2,3})
    {
        std::cout << "Press x key to continue ..." << std::endl;
        char key = getch(); // wait key press
        // char key = getchar(); // equal to getc(stdin)
        // char key = getc(stdin);
        switch(key)
        {
            case '\n':
                printf("New Line\n");
                break;
            case '\x27':
            case 'x':
                printf("Byte", key );
                exit(0);
                break;
            default:
                printf("-->%c\n", key );
                break;
        }
    }
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; ++i)
    {
        std::cout << i << " --> " << argv[i] << '\n';
    }
    if (argc==1) tryKey();
}