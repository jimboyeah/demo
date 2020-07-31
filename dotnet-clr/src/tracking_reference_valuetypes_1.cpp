// tracking_reference_valuetypes_1.cpp
// compile with: /clr

using namespace System;

int main() {
   int i = 10;
   int % j = i;
   Object ^ o = j;   // j is implicitly boxed and assigned to o
}