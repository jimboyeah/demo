// override_native_keyword.cpp
using namespace System;

#using <system.dll>

#include <stdio.h>
__interface I1 {
   virtual void f();
};

class X : public I1 {
public:
   virtual void f() override {}   // OK
   // virtual void g() override {}   // C3668 I1::g does not exist
};


int main()
{
   Console::WriteLine("read the fucking code!");
}
