#include <iostream>
#include <string>

int main(void)
{
   using namespace std;
   std::cout << "Press Ctrl+D (Linux) or Ctrl+Z (Windows) to send EOF.\n";
   std::string val;

   int a[9] = {1,2,3,};
   int *p1 = a, *p2 = &a[1];
   cout << "Element 1st @" << p1 << endl 
        << "Element 2nd @" << p2 << endl 
        << "Distance between 1st and 2nd: " << p2 - p1 << endl;
   
   while (std::cin >> val)
   {
      std::cout << "You type: " << val << std::endl;
   }
}