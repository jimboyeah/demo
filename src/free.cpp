#include <cstdlib>
#include <cstdio>
#include <thread>
#include <cstdbool>

#if defined(WIN32) || defined(WIN64)
    #include <windows.h>
    #define sleep(n) Sleep(1000 * (n))
#else
    #include <unistd.h>
#endif

int * test(bool leak)
{
    //char arr[0];                  // error: cannot define zero-length array
    char *cpa = new char[0];         // ok: but cp can't be dereferenced
    delete [] cpa;

    int* p1 = (int*)std::malloc(1000*1000*100*sizeof *p1);
    if (!leak) std::free(p1); // every allocated pointer must be freed
 
    int* p2 = (int*)std::calloc(10, sizeof *p2);
    int* p3 = (int*)std::realloc(p2, 1000*sizeof *p3);
    if(p3) // p3 not null means p2 was freed by std::realloc
       std::free(p3);
    else // p3 null means p2 was not freed
       std::free(p2);
    return p1;
}

int main(int argc, char *argv[])
{
    bool leak = argc > 1 && 0 == strcmp("-leak", argv[1]);
    for (int i = 0; i < 1000000; ++i)
    {
        int *p = test(leak);
        if (p==NULL)
        {
            printf("NULL return %d\n", p);
            break;
        } 
        printf("test %d\n", i);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        // sleep(1);
    }
    printf("DONE!");
}