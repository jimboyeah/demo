#include <iostream>
#include <string>

using namespace std;

int main()
{
    /*
     * Strong Static Type
     C++ is a statically typed language, which means that types are checked at compile time.
     The process by which types are checked is referred to as type-checking.

     * Variable
     A variable provides us with named storage that our programs can manipulate.

     *lvalue (pronounced "ell-value"):
     An expression that is an lvalue may appear as either the left-hand or right-hand
     side of an assignment.

     *rvalue (pronounced "are-value"): An expression that is an rvalue may appear on
     the right- but not left-hand side of an assignment.


    *Terminology: What Is an object?
    Strictly speaking, some might reserve the term object to describe only
    variables or values of class types.

    C++ programmers tend to be cavalier in their use of the term object. Most generally,
    an object is a region of memory that has a type. More specifically, evaluating an
    expression that is an lvalue yields an object.

     */


    /*
     * Although, at this point in the book, it may seem obscure to the reader,
       in C++ it is essential to understand that initialization is not assignment.
     * Initialization happens when a variable is created and gives that variable
       its initial value. Assignment involves obliterating an object's current value
       and replacing that value with a new one.
     * When we define a variable without an initializer,
       the system sometimes initializes the variable for us.
     */
    int i1(1024);    // direct-initializtion
    int i2 = 1024;   // copy-initialization

    /*
     * Distinguish Definition from Declaration
     * A definition of a variable allocates storage for the variable and may also
       specify an initial value for the variable. There must be one and
       only one definition of a variable in a program.
     * A declaration makes known the type and name of the variable to the program.
       A definition is also a declaration: When we define a variable,
       we declare its name and type. We can declare a name without defining it by
       using the extern keyword. A declaration that is not also a definition
       consists of the object's name and its type preceded by the keyword extern:
       
       extern int i3;   // declares but does not define it

       and in other cpp file:

       int i3 = 2000;
     */
    int i4;          // declares and defines it

    // If an initializer is present, the declaration is treated as a definition
    // even if the declaration is labeled extern.
    // but GCC is not allow: error: `i5' has both `extern' and initializer
    //extern int i5 = 9;


    const char *hdc = "Today if you have already use PHP, you will feel C++ is "
                "somehow a shadow of PHP!";
    cout << hdc << endl;



    /*
     * Default Constructor
       If the class has a default constructor, most classes wil provide,
       then we can define variables of that class without explicitly initializing them.
       For example, the string type defines its default constructor to initialize
       the string as an empty stringthat is, a string with no characters:
     */
    string empty;  // now empty is empty string ""


    //const Objects Are Local to a File By Default, use extern to expand global const variable.
    const string greeting = "Hello world!";
    cout << greeting << endl;


    /*
     * About Reference
     * A Reference Is an Alias
       int& ref;       // error: a reference must be initialized
       int& ref = 10;  // error: initializer must be an object
     * No reference of an array.
     * When a reference is initialized, it remains bound to that object as long as the reference exists.
       There is no way to rebind a reference to a different object;
     */
    int i6 = 1;
    cout << "i6 is " << i6 ;

    int& alias = i6;
    alias ++;

    cout << ", after alias++, i6 is " << i6 << endl;
    /*
    2. 什么是“引用”?申明和使用“引用”要注意哪些问题?
    答：引用就是某个目标变量的“别名”(alias)，对应用的操作与对变量直接操作效果完全相同。
    申明一个引用的时候，切记要对其进行初始化。引用声明完毕后，相当于目标变量名有两个名称，
    即该目标原名称和引用名，不能再把该引用名作为其他变量名的别名。
    声明一个引用，不是新定义了一个变量，它只表示该引用名是目标变量名的一个别名，
    它本身不是一种数据类型，因此引用本身不占存储单元，系统也不给引用分配存储单元。
    不能建立数组的引用。
    3. 将“引用”作为函数参数有哪些特点?
    (1)传递引用给函数与传递指针的效果是一样的。这时，被调函数的形参就成为原来主调函数中的
       实参变量或对象的一个别名来使用，所以在被调函数中对形参变量的操作就是对其相应的目标
       对象(在主调函数中)的操作。
    (2)使用引用传递函数的参数，在内存中并没有产生实参的副本，它是直接对实参操作，而使用一般
       变量传递函数的参数，当发生函数调用时，需要给形参分配存储单元，形参变量是实参变量的
       副本，如果传递的是对象，还将调用拷贝构造函数。因此，当参数传递的数据较大时，用引用比
       用一般变量传递参数的效率和所占空间都好。
    (3)使用指针作为函数的参数虽然也能达到与使用引用的效果，但是，在被调函数中同样要给形参
       分配存储单元，且需要重复使用"*指针变量名"的形式进行运算，这很容易产生错误且程序的
       阅读性较差;另一方面，在主调函数的调用点处，必须用变量的地址作为实参。而引用更容易
       使用，更清晰。
    */

    //A const reference is a reference that may refer to a const object:
    //Terminology: const Reference is a Reference to const
    const int i7(1024);
    const int& ref1 = i7;  // ok: both reference and object are const
    //int& ref2 = i7;     // error: non const reference to a const object

    /*
     * A const reference can be initialized to an object of a different type
       or to an rvalue, such as a literal constant
     */
    int i8 = 42;
    //  legal for const references only
    const int& ref3 = 42;
    const int& ref4 = ref3 + i8;

    double f1 = 3.14;
    //int &ref5 = f1; // error because type up casting
    const int &ref6 = f1; // compiler will create temporary int from the double


    /*
     * Type Definition
       A typedef lets us define a synonym for a type.
     * To hide the implementation of a given type and emphasize instead the purpose for which the type is used
     * To streamline complex type definitions, making them easier to understand
     * To allow a single type to be used for more than one purpose while making the purpose clear each time the type is used
     */
    typedef int wages;             // wages is a synonym for int
    typedef double salary;         // salary is a synonym for double
    typedef string remuneration;   // remuneration is a synonym for std::string

    remuneration monthly = "3600";
    cout << "My remuneration in month is " << monthly << endl;

    /*
    typedef struct Data {
        int age;
        char name[32];
    };

    typedef struct data_type {
      int age;
      char name[20];
    } Data;
    */



    /*
     * About Enumerations
       Often we need to define a set of alternative values for some attribute.
       A file, for example, might be open in one of three states: input, output,
       and append. One way to keep track of these state values might be to associate
       a unique constant number with each. We might write the following:

         const int input = 0;
         const int output = 1;
         const int append = 2;

       Although this approach works, it has a significant weakness:
       There is no indication that these values are related in any way.
       Enumerations provide an alternative method of not only defining
       but also grouping sets of integral constants.

     * By default, the first enumerator is assigned the value zero.
       Each subsequent enumerator is assigned a value one greater
       than the value of the enumerator that immediately precedes it.
     * Enumerators Are const Values
     */

    //And here let's define Weekday
    enum Weekday {
        Sunday = 0,
        Monday = 1,
        Tuesday = 2,
        Wednesday = 3,
        Thusday = 4,
        Friday = 5,
        Saturday = 6
    }; //an close semicolon must come here

    Weekday week = Tuesday;
    cout<<"Tuesday is weekday:"<<week<<endl;


    /*
     * About type cast
     * 4 casts: const_cast, dynamic_cast, reinterpret_cast, and the most common one static_cast
     */
    double f2 = 99.90;
    int i9 = static_cast<int>(f2);
    cout << "double static cast to integer:" << i9 << endl;



    //to avoid warning
    i1 = i2 = i4 = ref1;
    i1 = ref3;
    i1 = ref4;
    i1 = ref6;

    return 0;
}
