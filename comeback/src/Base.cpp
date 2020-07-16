#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
using namespace std;

/*
 * This file contains class declarations and definition.
 * Please note such a file is ease to introduce multiple definition error
 * when it was include in main program.
 */

/*
 * A global string variable
 * multiple definition of `name'?
 * because name was use in main.cpp and Base.cpp will be include in main.cpp
 * which process will make declaration if new variable exists.
 * That is means a variable named name was declared in main.cpp
 * if no static global variable named name. So this code line following will generate an error:
 * string name = "Jimbo";
 * Also you can use extern to declare variable in main.cpp:
 * extern string name;
 * C++ supports C's notion of separate compilation. This can be used to organize a
 * program into a set of semiindependent fragments. Also useful when static member is required.
 */

static string name = "Jimbo";

class Base {
    public:
    Base (string msg){
        cout<<"Base under construction. "<<msg<<endl;
        _msg = msg;

        //What is the trouble initialize static member in a constructor?
        //name = "Base Class by Constructor";

        //4 casts: const_cast, dynamic_cast, reinterpret_cast, and the most common one static_cast
        int big = static_cast<int>(number);
        cout<<"double static cast to integer:"<<big<<endl;
    }
    ~Base (){
        cout<<"Base is executed destruction."<<endl;
    }
    void sayhello(){
        cout<<"Hello World! "<<_msg<<endl;
    }

    //declare a static method and initilize herein
    static void say(string msg){
        cout<<msg<<endl;
    };

    //must be const and static if member initialization is with.
    static double const number = 99.99;

    //declare a static member and initialize it outside
    static string name;


    private:
    //a non-constant member will be initialize within constructor
    string _msg;

    //error: invalid in-class initialization of static data member of non-integral type `std::string'
    //static string _msg = "Hello World!";
    //static string const _msg = "Hello World!";

    //error: ISO C++ forbids in-class initialization of non-const static member `_msg'
    //static char _msg = 'H';

}; //It is a common mistake among new programmers to forget the semicolon at the end of a class definition.


//Static member initialization, this part of defination of a class will be separated into files.

/*
 * Because class declaration of this file will include in main program,
 * so this definition will generate a multiple definition error. And let's use construtor to initialize it.
 * Multiple definition are come from:
 * 1. When Base.cpp was include in main.cpp, compiler will recognize a definition of following code.
 * 2. When compiler start compile this Base.cpp, it will also generate a new definition.
 * So program crushed if you do so!
 * I tried preprocessor to avoid multiple definition but it does work really!
 * Finally I found this was use in main.cpp
 *  //Initilize static member with extern
 *  extern string Base::name = "Base Class";
 */
//string Base::name = "Base Class";

//error: `static' may not be used when defining (as opposed to declaring) a static data member
//static string Base::name = "Base Class";

#endif //BASH_H


