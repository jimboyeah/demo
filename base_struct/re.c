#include "Stdio.h"
#include "iostream"


class Base 
{
    public:
    Base(std::string _name){
        //std::string name = *new std::string(_name);
        std::cout<<"Hello World, this is "<<_name<<"."<<std::endl;
    }
    std::string sayhello(){
        //std::cout<<"Hello World, this is "<<this.name<<std::endl;
        return "Hi!";
    };

    private:
    std::string name;
    //char[] name = "jimbo";
};

int main(void)
{
    //Conversion from 'Base*' to non-scalar type 'Base' requested!
    //Base base = new Base("Base");

    //Try this for my gril Yang
    Base base = *new Base("Yang");

    std::cout<<base::sayhello();

    return 0;
}
