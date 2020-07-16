#include <iostream>
//include "Base.cpp" //This line for error, because it has definition but declaration for class
#include "Base.h" //for class declarations

/*
 * To successfully compile this program, don't forget add include and src path in your project settings.
 */

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    //cout<<name<<endl;

    Base base = *new Base("She said, I means he said, ...");
    base.sayhello();
    base.say("Hello, this is statick!");
    cout<<"Class' Name:"<<base.name<<endl;
    base.name = "New Name";
    cout<<"Class' Name:"<<Base::name<<endl;

    return 0;
}
