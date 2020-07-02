#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
// #include <boost/format.hpp>
// #include <format> // C++20

using namespace std;

struct X {
    int x, y;
    int operator()(int i){
        x = y = i;
    }
    void f()
    {
        // the context of the following lambda is the member function X::f
        auto lambda = [=]()->int
        {
            return operator()(this->x + y); // X::operator()(this->x + (*this).y)
                                            // this has type X*
        };
        printf("<struct X(%d,%d)>\n", x, y);
    }
}x1;

class S {
    int x = 0;
    void use(int a, int b){
        printf("<use (%d,%d)>\n", a, b);
    }
public:
    void f() {
        int i = 0;
        //  auto l1 = [i, x]{ use(i, x); };    // error: x is not a variable
        auto l2 = [i, x=x, this]{ use(i, x); };  // OK, copy capture
        i = 1; x = 1; l2(); // calls use(0,0)
        auto l3 = [i, &x=x, this]{ use(i, x); }; // OK, reference capture
        i = 2; x = 2; l3(); // calls use(1,2)
    }
};

int main()
{
    x1(1);
    x1.f();
    S s1;
    s1.f();
    // cout << format("<struct X({},{})>\n", x1.x, x1.y);
}