#include <iostream>
using namespace std;

class BaseA
{
public:
    BaseA() { cout << "BaseA ..." << endl; }
    virtual void print(){ cout << "BaseA print..." <<endl; }
};

class BaseB
{
public:
    void print(){cout << "BaseB print..." << endl;}
};

class MultiA: public BaseA { };
class MultiB: public BaseA { };
class MultiC: virtual public BaseA { 
public:
    MultiC() { cout << "MultiC ..." << endl; }
};
class MultiD: virtual public BaseA { 
public:
    MultiD() { cout << "MultiD ..." << endl; }
};

class X : public BaseA, public BaseB { };
class Y : public MultiA, public MultiB { };
class Z : public MultiD, public MultiC { };

int main(int argc, char* argv[])
{
    X x;
    // x.print(); // ambiguous
    x.BaseA::print();
    x.BaseB::print();

    Y y;
    // y.print(); // ambiguous
    y.MultiA::print();
    y.MultiB::print();

    Z z;
    z.print();
    z.MultiC::print();
    z.MultiD::print();

    return 0;
}