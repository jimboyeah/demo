#include <iostream>
using namespace std;

class A {};
class B {};

int main () {

   A * a = new A;
   B * b = reinterpret_cast<B*>(a); //correct!

   printf("a -> %x\nb -> %x\n", a, b);
   // int i = (int *)0x197ad0;
   int* x = reinterpret_cast<int*>(0x197ad0);
   printf("int -> int *: %x", *x);

   double d = 2000.3;
   short s;
   // s = reinterpret_cast<short> (d); //compile error!
}