#include <iostream>
#include <string>
#include <vector>
#include <format>

int main(void)
{
   using namespace std;
   cout << "Press Ctrl+D (Linux) or Ctrl+Z (Windows) to send EOF.\n";
   string val;

   vector<string> vs ={"Hello", "C++"};
   // cout << &((*vs.begin()).empty) << endl;

   int ia = 3, ib = 4;
   double d = ia/ib;
   
   cout << std::format("double d = {}/{} = {}", ia, ib, d ) << endl;

   int a[9] = {1,2,3,};
   int *p1 = a, *p2 = &a[1];
   cout << "Element 1st @" << p1 << endl 
        << "Element 2nd @" << p2 << endl 
        << "Distance between 1st and 2nd: " << p2 - p1 << endl;
   
   while (std::cin >> val)
   {
      std::cout << "User type: " << val << std::endl;
   }
}