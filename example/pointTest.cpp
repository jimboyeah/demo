
#include <iostream>
#include "point.hpp"

using namespace std;

int main(int argc, char** argv)
{
  Point a;
  Point b(2, 7);
  Point c;
  
  c.setX(85);
  c.setY(24);
  
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = (" << c.getX() << ", " << c.getY() << ")\n";

  cout << "foo + bar = " << foo << " + " << bar << " = " << (foo + bar) << endl;

  return 0;
}