#include <iostream>
#include <string>
#include "Base.h" //for class declarations so that members can be introduced into class.

using namespace std;

Base::Base()
{
    //ctor
}

Base::Base(string msg)
{
    cout<<"Base under construction. "<<msg<<endl;
    _msg = msg;

    //4 casts: const_cast, dynamic_cast, reinterpret_cast, and the most common one static_cast
    int big = static_cast<int>(number);
    cout<<"double static cast to integer:"<<big<<endl;
}

Base::~Base()
{
    //dtor
    cout<<"Base is executed destruction."<<endl;
}

void Base::sayhello(){
    cout<<"Hello World! "<<_msg<<endl;
}

void Base::say(string msg){
    cout<<msg<<endl;
};


//define a static member and initialize it
string Base::name = "Base Class";


