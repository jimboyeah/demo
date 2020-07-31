#include <iostream>
struct A {
    virtual void foo() { std::cout << "A::foo() is called" << std::endl; }
    void bar() { std::cout << "A::bar() is called" << std::endl; }
};
struct B: public A {
    void foo() { std::cout << "B::foo() is called" << std::endl; }
    void bar() { std::cout << "B::bar() is called" << std::endl; }
    // void Bar() override { std::cout << "B::bar() is called" << std::endl; }
};

int main()
{
    A *a = new B();
    a->foo(); // B::foo() is called
    a->bar(); // A::bar() is called
}
