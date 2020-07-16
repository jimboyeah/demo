#include <iostream>
#include <cstring>
#include <time.h>

using namespace std;

int main()
{
   /*
    * Dynamically Allocating Arrays
        A variable of array type has three important limitations:
        Its size is fixed, the size must be known at compile time,
        and the array exists only until the end of the block in which it was defined.
        Real-world programs usually cannot live with these restrictionsthey need a way to
        allocate an array dynamically at run time. Although all arrays have fixed size,
        the size of a dynamically allocated array need not be fixed at compile time.
        It can be (and usually is) determined at run time. Unlike an array variable,
        a dynamically allocated array continues to exist until it is explicitly freed by the program.
    */

    const char *cp = "hello";
    int cnt = 0;

    while (*cp) {
        cout << *cp << ' ';
        ++cnt;
        ++cp;
    } //count C-style char
    cout << "count:" << cnt << endl;

   /*
    while (cp) {
        ++cnt;
        ++cp;
    } //error dead loop may be
    cout << "count:" << cnt << endl;
    */

   /*
    const char ca[] = {'h', 'e', 'l', 'l', 'o'}; //error not null-terminated may cause dead loop
    const char *cp2 = ca;
    while (*cp2) {
      cout << *cp2 << endl;
      ++cp2;
    }
    */


   /*
    * Definite a new dynamic array
        This new expression allocates an array of ten ints and returns a pointer to
        the first element in that array, which we use to initialize.
    * Initializing a Dynamically Allocated Memory
        When we allocate an array of objects of a class type, then that type's
        default constructor is used to initialize each element.
        If the array holds elements of built-in type, then the elements are uninitialized.
    */

    //char arr[0];                  // error: cannot define zero-length array
    char *cpa = new char[0];         // ok: but cp can't be dereferenced

    int *pia = new int[10];         // array of 10 uninitialized ints
    int *pib = new int[10] ();      // array of 10 value-initialize ints
    string *psa = new string[10];   // array of 10 empty strings, initialized
   /*
    * Each of these new expressions allocates an array of ten objects.
    * In the first case, those objects are strings. After allocating memory to hold the objects,
        the default string constructor is run on each element of the array in turn.
    * In the second case, the objects are a built-in type; memory to hold ten ints is allocated,
        but the elements are uninitialized.
    * The parentheses are effectively a request to the compiler to value-initialize the array,
        which in this case sets its elements to 0.
    */


   /*
    * Freeing Dynamic Memory
        When we allocate memory, we must eventually free it.
        Otherwise, memory is gradually used up and may be exhausted.
        When we no longer need the array, we must explicitly return its memory to the free store.
        We do so by applying the delete [] expression to a pointer that addresses the array we want to release:

        If the empty bracket pair is omitted, it is an error,
        but an error that the compiler is unlikely to catch;
        the program may fail at run time.
    */
    delete [] psa;
    delete [] cpa;
    delete [] pia;
    delete [] pib;



    const char *cpb = "This opportunity is a gift from harven.";
    int sl = strlen(cpb);
    const char *cpc = new char[sl+1]; // memory allocated include null-terminator
    strncpy((char *)cpc, cpb, sl+1); // copy string to dynamic allocated memory area, crash here!
    //It is essential to remember to add 1 to the length returned from strlen to accommodate the trailing null.
    cout << "cpb length is " << sl << endl;
    cout << "cpb locate in " << &cpb << endl;
    cout << "cpc locate in " << &cpc << endl;
    cout << "cpb points to " << cpb << endl;
    cout << "cpc points to " << cpc << endl;

    cpc = "new string coming."; // becareful, length must within predefined value.
    cout << "cpb locate in " << &cpb << endl;
    cout << "cpc locate in " << &cpc << endl;
    cout << "cpb points to " << cpb << endl;
    cout << "cpc points to " << cpc << endl;
    delete cpc;


   /*
    * Dynamic Arrays of const Objects
        If we create an array of const objects of built-in type on the free store,
        we must initialize that array:
        The elements are const, there is no way to assign values to the elements.
        The only way to initialize the elements is to value-initialize the array:

              // error: uninitialized const array
              const int *pci_bad = new const int[100];
              // ok: value-initialized const array
              const int *pci_ok = new const int[100]();

        It is possible to have a const array of elements of a class type that provides a default constructor:

              // ok: array of 100 empty strings
              const string *pcs = new const string[100];

        In this case, the default constructor is used to initialize the elements of the array.
        Of course, once the elements are created, they may not be changedwhich means that
        such arrays usually are not very useful.
    */


    int maxsize = 32;
    char tx[maxsize]; // just allocate memory
    const char *fmt = "%Y-%m-%d %H:%M:%S";
    //time_t *tt; //this fault because a pointer uninitialized
    time_t *tt = new time_t();
    time(tt);
    struct tm * time = gmtime(tt);
    strftime( tx, maxsize-1, fmt, time );
    //size_t ts = strftime( tx, maxsize-1, "%Y-%m-%d %H:%M:%S", time ); error why?
    cout << tx << endl;
    delete tt;


    // The clock_t clock( void ); function returns the processor time since the program started, or -1
    // if that information is unavailable. To convert the return value to seconds,
    // divide it by CLOCKS_PER_SECOND. (Note: if your compiler is POSIX compliant,
    // then CLOCKS_PER_SECOND is always defined as 1000000.)
    // clock_t is defined: typedef	long	clock_t;
    cout << "CLOCKS_PER_SECOND:" << CLOCKS_PER_SEC << endl;



   /*
    * Contrasting C-Style Strings and C++ Library strings
        The following two programs illustrate the differences in using C-style character strings
        versus using the C++ library string type.
        The string version is shorter, easier to understand, and less error-prone:
    */

    clock_t stamp = clock();

    size_t maxloop = 1000000;
    // C-style character string implementation
    const char *pc = "a very long literal string";
    const size_t len = strlen(pc +1);   // space to allocate
    // performance test on string allocation and copy
    for (size_t ix = 0; ix != maxloop; ++ix) {
        char *pc2 = new char[len + 1];  // allocate the space
        strcpy(pc2, pc);                // do the copy
        if (strcmp(pc2, pc))            // use the new string
            ;                           // do nothing
        //delete [] pc2;                  // free the memory
    }

    cout << "Time elapsed 1:" << double(clock()-stamp)/CLOCKS_PER_SEC << endl;
    stamp = clock();

    // string implementation - C++'s object perspective
    string str("a very long literal string");
    // performance test on string allocation and copy
    for (unsigned int ix = 0; ix != maxloop; ++ix) {
        string str2 = str;  // do the copy, automatically allocated
        if (str != str2)    // use the new string
            ;               // do nothing
    }                       // str2 is automatically freed

    cout << "Time elapsed 2:" << double(clock()-stamp)/CLOCKS_PER_SEC << endl;



    /*
    * C-style Dynamic Memory Allocation <stdlib.h>
    * void *malloc( size_t size );
        Returns a pointer to a chunk of memory of size size, or NULL if there is an error.
        The memory pointed to will be on the heap, not the stack,
        so make sure to free it when you are done with it.
    * void *realloc( void *ptr, size_t size );
        Changes the size of the object pointed to by ptr
        to the given size. size can by any size, larger or smaller than the original.
        The return value is a pointer to the new space, or NULL if there is an error.
    * void *calloc( size_t num, size_t size );
        Returns a pointer to space for an array of num objects, each of size size.
        Returns NULL if there is an error.
    * void free( void *ptr );
        deallocates the space pointed to by ptr, freeing it up for future use.
        ptr must have been used in a previous call to malloc(), calloc(), or realloc().
    */
    struct Data {
        int age;
        char name[32];
    };

    Data *bob;
    bob = (Data*) malloc( sizeof(Data) );
    if( bob != NULL ) {
      bob->age = 22;
      strcpy( bob->name, "Robert" );
      printf( "%s is %d years old.\n", bob->name, bob->age );
    }
    free( bob );



    return 0;
}
