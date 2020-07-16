/*
    The library defines several higher-level abstract data types,
    including strings and vectors. The string class provides
    variable-length character strings, and the vector type manages
    a collection of objects of a single type.

    Iterators allow indirect access to objects stored in a container.
    Iterators are used to access and navigate between the elements
    in strings and vectors.

    and more about Queue, List, Map, Set, Stack,
    Double-Ended Queue, Priority Queue, Multimap, Multiset
 */

#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int main()
{

    /* About string
     *   string s1;           Default constructor; s1 is the empty string
     *   string s2(s1);       Initialize s2 as a copy of s1
     *   string s3("value");  Initialize s3 as a copy of the string literal
     *   string s4(n, 'c');   Initialize s4 with n copies of the character 'c'
     *   string s5 = s1 + s2; s5 is hello, world\n
     *   s1 += s2;            equivalent to s1 = s1 + s2
     */

    string s1 = "Hello "; //use copy constructor
    string s2 = "world!\n";
    cout << s1 + s2;
    for(string::size_type index=0; index<s1.size(); index++){
        char c = s1[index];
        //use cctype function like isupper
        cout << c << (isupper(c)?" is":" isn't") << " a uppercase.\n";
    }

   /*
    * Mixing Library strings and C-Style Strings
        We can initialize a string from a string literal:
        More generally, because a C-style string has the same type as a string literal
        and is null-terminated in the same way, we can use a C-style string anywhere that
        a string literal can be used:

        We can initialize or assign to a string from a C-style string.
        We can use a C-style string as one of the two operands to the string addition or
        as the right-hand operand to the compound assignment operators.

        The reverse functionality is not provided:
        There is no direct way to use a library string when a C-style string is required.
        For example, there is no way to initialize a character pointer from a string:

          char *str = st2; // compile-time type error

        There is, however, a string member function named c_str that we can often use to accomplish what we want:

          char *str = st2.c_str(); // almost ok, but not quite

        The name c_str indicates that the function returns a C-style character string. Literally,
        it says, "Get me the C-style string representation"that is, a pointer to the beginning of a null-terminated
        character array that holds the same data as the characters in the string.

        This initialization fails because c_str returns a pointer to an array of const char.
        It does so to prevent changes to the array. The correct initialization is:

          const char *str = st2.c_str(); // ok

        The array returned by c_str is not guaranteed to be valid indefinitely.
        Any subsequent use of st2 that might change the value of st2 can invalidate the array.
        If a program needs continuing access to the data, then the program must copy the array returned by c_str.
    */
    string proem = "This popular tutorial introduction to standard C++ has been completely updated, reorganized";
    const char *fromstring = proem.c_str();
    cout << "C-style string form string object:" << fromstring << endl;


    /*
     * About Arraies and Pointers
       The language defines two lower-level compound types arrays and pointers that are similar to
       vectors and iterators. Like a vector, an array holds a collection of objects of some type.
       Unlike vectors, arrays are fixed size; once an array is created, new elements cannot be added.
       Like iterators, pointers can be used to navigate among and examine the elements in an array.
     * Advice: Avoid Pointers and Arrays
       Modern C++ programs should almost always use vectors and iterators in preference
       to the lower-level arrays and pointers. Well-designed programs use arrays and
       pointers only in the internals of class implementations where speed is essential.
     * No Array Copy or Assignment
     * Caution: Arrays Are Fixed Size
     * There are no arrays of references.
     * The dimension must be a constant expression whose value is greater than or equal to one.
       A constant expression is any expression that involves only integral literal constants, enumerators,
       or const objects of integral type that are themselves initialized from constant expressions.
     * A nonconst variable, or a const variable whose value is not known until run time,
       cannot be used to specify the dimension of an array.
     * An explicitly initialized array need not specify a dimension value.
       The compiler will infer the array size from the number of elements liste

       AT THE END
     * Checking Subscript Values
       As with both strings and vectors, the programmer must guarantee that the subscript value is
       in rangethat the array has an element at the index value. By far, the most common causes of
       security problems are so-called "buffer overflow" bugs. These bugs occur when a subscript is
       not checked and reference is made to an element outside the bounds of an array or
       other similar data structure.
     */
    const int d1 = 10;
    int a1[d1];
    a1[d1-d1] = 90;
    a1[d1-1] = 99;
    cout << "Address of array a1 is " << a1 << endl;

    int a2[] = {1,2,3}; // compiler will infer the first demension is 3: int a2[3] = {1,2,3};
    //count << "Address of array a2 is " << static_cast<int>(a2) << endl;

    string a3[] = {"Hello","world"};
    //count << "Address of array a3 is " << a3 << endl;

    /*
     * C-Style Character String
     * Character Arrays Are Special
       A character array can be initialized with either a list of comma-separated character literals
       enclosed in braces or a string literal. Note, however, that the two forms are not equivalent.
       Recall that a string literal contains an additional terminating null character. When we create
       a character array from a string literal, the null is also inserted into the array.
     * C-style strings are not actually a type in either C or C++. Instead, C-style strings are
       null-terminated arrays of characters, so a4 and csn are not C-style string for not null-terminated.
     * Although C++ supports C-style strings, they should not be used by C++ programs.
       C-style strings are a surprisingly rich source of bugs and are the root cause of
       many, many security problems.
     * The Standard C library provides a set of functions operate on C-style string,
       such as strlen, strcmp, strcat, strcpy, strncmp, strncat, strncpy.
     * NOTE: These functions do no checking on their string parameters.
     * NOTE: strlen returns the length of the string not including the null.
       When Using C-Style Strings, Use the strn*** Functions
       #include <cstring>

       which is the C++ version of the string.h header from the C library.
     */
    char a4[] = {'C','+','+'};      // no null, dimension is 3, not C-style string
    char a5[] = {'C','+','+',0};    // explicit null, dimension is 4
    char a6[] = {'C','+','+','\0'}; // explicit null, dimension is 4
    char a7[] = "C++";              // null terminator added automatically
    const char *cs = "C++";         // null terminator added automatically
    char *csn = a4;                 // points to first element of an arrayj, but not C-style string
    char *cs2 = a5;                 // points to first element of a null-terminated char array

    //char a8[6] = "Daniel"; //compile-time error "Daniel" is 7 elements
    //It is important to remember the null-terminator when initializing an array of characters to a literal.

    // Question: How to test the length?


    /*
     * Pointers are iterators for arrays: A pointer can point to an element in an array.
     * Conceptually, pointers are simple: A pointer points at an object. Like an iterator,
       a pointer offers indirect access to the object to which it points. However, pointers
       are a much more general construct. Unlike iterators, pointers can be used to point at
       single objects. Iterators are used only to access elements in a container.
     * Specifically, a pointer holds the address of another object.
     * string* p1, p2; // p1 is a pointer to string,  p2 is a string
     */
    string s3("Hello world");
    string *p1 = &s3;
    *p1 = "Good evening!"; // contents of s now changed
    string *p2 = p1;        // p2 same as p1 point to s3.
    cout << "greet again:" << *p2 << endl; // dereference to retrieve data's address!

    // const Pointer to a const Object
    const char *p3 = "GOOD"; // ok! point a literal string.
    cout << "p3 point to literal string:" << *p3 << endl; // *p3 is the address of literal "GOOD"
    cout << "p3 point to literal string:" << p3 << endl;  // content of p3 is the address of literal "GOOD"

    int i1 = 99;
    int * p4 = &i1;
    int ** p5 = &p4;
    cout << "OK! Pointer p5 points to p4:" << **p5 << endl;


    int a8[] = {1,2,3};
    int *p6 = a8;   // p6 points to a8[0];
    p6 = &a8[2];    // p6 points the last element of a8
    cout << "p6 points to " << *p6 << endl;
    cout << "pointer subscripts: p6[0] is " << p6[0] << endl;

    p6--;           // ok, p6 points a8[1]
    //WARNING: YOUR ARE AT THE RISK OF POTENTIAL INATTENTION IF ILLEGAL POINTER!
    cout << "pointer arithmetic: p6-- is " << *p6 << endl;
    cout << "pointer arithmetic: *(p6-1) is " << *(p6-1) << endl;


    //Computing an Off-the-End Pointer
    const size_t asize = 5;
    int a9[asize] = {1,2,3,4,5};
    // pend points just after the last and donn't dereference!
    for( int *ps = a9, *pend = a9+asize; ps != pend; ++ps){
        cout << *ps << ' ';
    }
    cout << "here Off-the-End" << endl;
    // Now we should know: Pointers Are Iterators for Arrays




    //Pointers and Typedefs
    string st = "Some literal";
    typedef string *pstring;
    const pstring cstr = &st; // what is this?
    cout << "Const Pointer point to string:" << *cstr << endl; // remember dereference is retrieve data's address!
    /*
     The simple answer is that it is a pointer to const pstring.
     The deeper question is:

     what underlying type does a pointer to const pstring represent?
     Many think that the actual type is

        const string *cstr; // wrong interpretation of const pstring cstr

     That is, that a const pstring would be a pointer to a constant string. But that is incorrect.
     The mistake is in thinking of a typedef as a textual expansion. When we declare a const pstring,
     the const modifies the type of pstring, which is a pointer. Therefore, this definition
     declares cstr to be a const pointer to string. The definition is equivalent to

        // cstr is a const pointer to string
        string *const cstr; // equivalent to const pstring cstr

     */



    char *ctwice = "Twice pointer";
    char **p7 = &ctwice; // ok! pointer point to a pointer!
    cout << "*p7 is a " << *p7 << endl;
    cout << "p7 is a Twice pointer! but **p7 is " << **p7 << endl;


    // To know a10 is base address of an array, it points to an array.
    // a10[0] is a pointer point to char *, it is address of string "Hello"
    char *a10[] = {"Hello","world"};
    char **p8 = a10;
    cout << "What will we see?        p8: " << p8 << endl;  // address of an array
    cout << "What will we see?       *p8: " << *p8 << endl; // address of "Hello"
    cout << "What will we see then? **p8: " << **p8 << endl;// address of 'H'


    // To know a11 is base address of an array, a11[0] is address of string "Hello"
    // So we can infer a11 is another pointer.
    string a11[] = {"Hello","world"};
    string *p9 = a11; // points to an array, so do a10.
    cout << "What will we see? a11:" << a11 << endl;
    cout << "*p9 is word at the first of a11:" << *p9 << endl;
    string **p10 = &p9;
    cout << "Twice pointer **p10 is:" << **p10 << endl;


    // Now turn to string - a native C++ style string
    // Here p12 is pointer points to twice pointer! Because stwice is a really pointer or reference!
    string stwice = "Twice pointer"; // Note: a copy initialization with char[]
    string *p11 = &stwice;
    string **p12 = &p11; // ok! pointer point to a pointer!
    cout << "p11 is not a " << *p11 << endl;
    cout << "triple pointer p12:" << p12 << endl; // What is happend?
    cout << "pointer points to a pointer *p12:" << *p12 << endl; // What is happend?
    cout << "pointer points to a string **p12:" << **p12 << endl; // What is happend?




    // The type void* is a special pointer type that can hold an address of any object:
    //void* pany = a8;
    //cout << "void * pointer pany is " << pany << endl;
    //cout << "content in pany[0] is " << pany[0] << endl;



    /* About vector - a class template and a collection of objects of a single type
     * Key Concept:
     *   vectors Grow Dynamically,
     *   Safe, Generic Programming
     *   vector<T> v1;       vector that holds objects of type T;
     *   vector<T> v2(v1);   v2 is a copy of v1
     *   vector<T> v3(n, i); v3 has n elements with value i
     *   vector<T> v4(n);    v4 has n copies of a value-initialized object(initialized to empty)
     * Use size_type:
     *   vector<T>::size_type
     * And is it right?
     *   vector< vector<int> > ivec;
     */
    vector<string> words;
    words.push_back("Hope");
    words.push_back("was");
    words.push_back("all");
    words.push_back("had");
    words.push_back("until");
    words.push_back("you");
    words.push_back("came");

    string first = words.front();
    cout << "First word words.front():" << first << endl;
    first = words[0];
    cout << "First word words[0]:" << first << endl;

    //Using an Array to Initialize a vector
    const size_t arr_size = 6;
    int int_arr[arr_size] = {0, 1, 2, 3, 4, 5};
    // ivec has 6 elements: each a copy of the corresponding element in int_arr
    vector<int> ivec(int_arr, int_arr + arr_size);



    /* About iterator
     * Another way access to vector's elements.
     * Iterator is a type for standard containers
     * and a type that can be used to examine the elements of a container and to navigate between them.
     * and a way to avoid such a run-time error when attempting to fetch an element that doesn't exist.
     * There is no assurance that the implementation will detect subscript element that are known to exist.
     */

    //vector<string>::iterator it = words.iterator;
    vector<string>::iterator it = words.begin();
    it += 3;
    words.insert(it,"I");
    //now words is in sequence: Hope was all I had until you came.

    for(it = words.begin(); it != words.end(); it++){
        string space = (it==words.begin()? "":" ");
        cout << space << *it; //read word via iterator
    }
    cout << "." << endl;



    /* About bitset
     * Some programs deal with ordered collections of bits.
     * Each bit can contain either a 0 (off) or a 1 (on) value.
     * Using bits is a compact way to keep yes/no information (sometimes called flags)
        bitset<n> b;            b has n bits, each bit is 0
        bitset<n> b(u);         b is a copy of the unsigned long value u
        bitset<n> b(s);         b is a copy of the bits contained in string s
        bitset<n> b(s, pos, n); b is a copy of the bits in n characters from s starting from position pos
     */

    //vb1 is smaller than the initializer
    bitset<8> vb1(0xffff);
    cout << "vb1 is:" << vb1 << endl;

    //vb2 has the same size as initializer
    bitset<16> vb2(0xffff);
    cout << "vb2 is:" << vb2 << endl;

    //on a 32-bit machine, bits 0 to 31 initialized from 0xffffffff
    //bitset<64> vb3(0xffffffff); // bits 32 through 63 initialized to zero
    //cout << vb3 << endl;

    //initialize from string, the bit pattern in vbs will repeat in 11110000 twice
    string s16 = "1111000011110000";
    bitset<16> vbs(s16);
    cout << "vbs is:" << vbs << endl;

    //vbs.any() equals to !vbs.none()
    cout << (vbs.any()? "vbs has some bit seted.":"vbs has no any bit seted.") << endl;

    vbs.flip();
    vbs.flip(0); //reverses value of first bit
    vbs[0].flip(); //the same as above
    cout << "vbs.flip():" << vbs << endl;

    vbs.set(0);
    vbs.set();
    cout << "vbs.set():" << vbs << endl;

    //Retrieving the Value of a bitset
    //Retrieve the value from a bitset
    unsigned long ul = vbs.to_ulong();
    cout << "vbs has unsigned long value vbs.to_ulong():" << ul << endl;
    //error: no matching function for call to `std::bitset<16u>::to_string()'?
    //cout << vbs.to_string() << endl;

    vbs.reset(0);
    vbs.reset();
    cout << "vbs.reset():" << vbs << endl;

    cout << "vbs.test(0):" << (vbs.test(0)? "True":"False") << endl;

    //To avoid operand appears twice, C++ offers a condensed approach
    //arithmetic assignment operator+=, *=, and so.
    int i = 0;
    i *= 0;

   return 0;
}
