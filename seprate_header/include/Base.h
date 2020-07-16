#ifndef BASE_H
#define BASE_H

#include <iostream>
/*
 * Headers Are for Declarations, Not Definitions
   Because headers are included in multiple source files,
   they should not contain definitions of variables or functions.

 * Some const Objects Are Defined in Headers
   Recall that by default a const variable (Section 2.4, p. 57) is local to
   the file in which it is defined. As we shall now see, the reason for this
   default is to allow const variables to be defined in header files.

 * A Brief Introduction to the Preprocessor
   In order to write our own headers, we need to understand a bit more about how a #include directive works.
   The #include facility is a part of the C++ preprocessor.
   The preprocessor manipulates the source text of our programs and runs before the compiler.
   C++ inherits a fairly elaborate preprocessor from C.
   Modern C++ programs use the preprocessor in a very restricted fashion.
   A #include directive takes a single argument: the name of a header.
   The pre-processor replaces each #include by the contents of the specified header.
   Our own headers are stored in files. System headers may be stored in a compiler-specific format
   that is more efficient. Regardless of the form in which a header is stored, it ordinarily
   contains class definitions and declarations of the variables and functions needed
   to support separate compilation.

 * Avoiding Multiple Inclusions
   Before we write our own header, we need to introduce some additional preprocessor facilities.
   The preprocessor lets us define our own variables.
   We can use these facilities to guard against including a header more than once:

    #ifndef BASE_H
    #define BASE_H
    ...
    $endif // BASE_H

 * Using Our Own Headers
   The #include directive takes one of two forms:

    #include <standard_header>
    #include "Base.h"

   If the header name is enclosed by angle brackets (< >), it is presumed to be a standard header.
   The compiler will look for it in a predefined set of locations, which can be modified by setting
   a search path environment variable or through a command line option. The search methods used
   vary significantly across compilers. We recommend you ask a colleague or consult your compiler's
   user's guide for further information.

   If the header name is enclosed by a pair of quotation marks, the header is presumed to be a nonsystem header.
   The search for nonsystem headers usually begins in the directory in which the source file is located.


   We know from C++ Primer Section 1.5(p. 20) that ordinarily class definitions go into a header file.
   In fact, C++ programs use headers to contain more than class definitions.
   Recall that every name must be declared or defined before it is used.
   The programs we've written so far handle this requirement by putting
   all their code into a single file. As long as each entity precedes
   the code that uses it, this strategy works. However, few programs are
   so simple that they can be written in a single file. Programs made up
   of multiple files need a way to link the use of a name and its declaration.
   In C++ that is done through header files.

   To allow programs to be broken up into logical parts, C++ supports
   what is commonly known as separate compilation. Separate compilation
   lets us compose a program from several files. To support separate compilation,
   we'll put the definition of Sales_item in a header file. The member functions
   for Sales_item, which we'll define in Section 7.7 (p. 258), will go in
   a separate source file. Functions such as main that use Sales_item objects are
   in other source files. Each of the source files that use Sales_item
   must include our Sales_item.h header file.

 */

#include <string>

using namespace std;

class Base
{
    public:
        Base();
        Base(string msg);
        virtual ~Base();

        static string name;

        // must be const and static if member initialization is with.
        // VS compiler will give:
        // error C2864: “Base::number”: 只有静态常量整型数据成员才可以在类中初始化|
        static double const number = 99.99;

        string Get_msg() { return _msg; }
        void Set_msg(string val) { _msg = val; }
        static void say(string msg);
        void sayhello();

    protected:
    private:
        string _msg;
};

#endif // BASE_H
