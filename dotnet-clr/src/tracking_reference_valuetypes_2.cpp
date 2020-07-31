// tracking_reference_template.cpp
// compile with: /clr
using namespace System;

class Temp {
public:
   // template functions
   template<typename T>
   static int f1(T% tt) {   // works for object in any location
      Console::WriteLine("T %");
      return 0;
   }

   template<typename T>
   static int f2(T& rt) {   // won't work for object on the gc heap
      Console::WriteLine("T &");
      return 1;
   }
};

// Class Definitions
ref struct R {
   int i;
};

int main() {
   R ^hr = gcnew R;
   int i = 1;

   Temp::f1(i); // ok
   Temp::f1(hr->i); // ok
   Temp::f2(i); // ok

   // error can't track object on gc heap with a native reference
   // Temp::f2(hr->i);
}

/*
T %
T %
T &
*/