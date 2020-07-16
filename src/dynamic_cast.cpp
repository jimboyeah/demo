#include <iostream>
using namespace std;

// class CBase { };
class CBase { virtual void dummy() {} };
class CDerived: public CBase { };

int main()
{
   CBase b; CBase* pb;
   CDerived d; 
   CDerived* pd;

   pb = dynamic_cast<CBase*>(&d);     // ok: derived-to-base
   pd = dynamic_cast<CDerived*>(&b);  // wrong: base-to-derived
   // error: cannot dynamic_cast (source type is not polymorphic)
   cout << "address : " << pd;
}