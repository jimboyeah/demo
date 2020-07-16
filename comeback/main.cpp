/*
 * TITLE:Jimbo's study program here begin
 * FILE:main.cpp
 * DATE:2012/02/20 when new C++0x specification had released.
 */

#include <iostream>
#include <string>
#include "Base.CPP"
#include "Time.CPP"

using namespace std;

/*
 * Initilize static member with extern
 * to avoid multiple definition error when Base.CPP was include in main.cpp
 * NOTE: this code style will generate a warning.
 */
extern string Base::name = "Base Class";

int main()
{
    cout << "Hello world!" << endl;
    cout<<name<<endl;

    Base base = *new Base("She said, I means he said, ...");
    base.sayhello();
    base.say("Hello, this is statick!");
    cout<<"Class' Name:"<<base.name<<endl;
    base.name = "New Name";
    cout<<"Class' Name:"<<Base::name<<endl;



    /*
     * Declarations and Definitions
     * Let's digress for a moment to note a subtle distinction between the terms
     * definition and declaration as applied to variables.
     * A declaration introduces a variable's name into a program and specifies its type
     * However, if a declaration also sets aside memory for the variable, it is also
     * called a definition.
     */

    //Struct is a type of class which member with public by default, usually used to hold data only.
    //Time t ; //Declaration and definition together! What a miraculous thing in C++!
    Time t = *new Time(1,0,30);
    //Time t = {1,0,30}; //brace symbol initializer availed if no construtor offer!
    cout<<"Seconds of the time is "<<t.getTime()<<endl;

    return 0;
}
