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
    2. ʲô�ǡ����á�?������ʹ�á����á�Ҫע����Щ����?
    �����þ���ĳ��Ŀ������ġ�������(alias)����Ӧ�õĲ�����Ա���ֱ�Ӳ���Ч����ȫ��ͬ��
    ����һ�����õ�ʱ���м�Ҫ������г�ʼ��������������Ϻ��൱��Ŀ����������������ƣ�
    ����Ŀ��ԭ���ƺ��������������ٰѸ���������Ϊ�����������ı�����
    ����һ�����ã������¶�����һ����������ֻ��ʾ����������Ŀ���������һ��������
    ��������һ���������ͣ�������ñ���ռ�洢��Ԫ��ϵͳҲ�������÷���洢��Ԫ��
    ���ܽ�����������á�
    3. �������á���Ϊ������������Щ�ص�?
    (1)�������ø������봫��ָ���Ч����һ���ġ���ʱ�������������βξͳ�Ϊԭ�����������е�
       ʵ�α���������һ��������ʹ�ã������ڱ��������ж��βα����Ĳ������Ƕ�����Ӧ��Ŀ��
       ����(������������)�Ĳ�����
    (2)ʹ�����ô��ݺ����Ĳ��������ڴ��в�û�в���ʵ�εĸ���������ֱ�Ӷ�ʵ�β�������ʹ��һ��
       �������ݺ����Ĳ�������������������ʱ����Ҫ���βη���洢��Ԫ���βα�����ʵ�α�����
       ������������ݵ��Ƕ��󣬻������ÿ������캯������ˣ����������ݵ����ݽϴ�ʱ�������ñ�
       ��һ��������ݲ�����Ч�ʺ���ռ�ռ䶼�á�
    (3)ʹ��ָ����Ϊ�����Ĳ�����ȻҲ�ܴﵽ��ʹ�����õ�Ч�������ǣ��ڱ���������ͬ��Ҫ���β�
       ����洢��Ԫ������Ҫ�ظ�ʹ��"*ָ�������"����ʽ�������㣬������ײ��������ҳ����
       �Ķ��Խϲ�;��һ���棬�����������ĵ��õ㴦�������ñ����ĵ�ַ��Ϊʵ�Ρ������ø�����
       ʹ�ã���������
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
