#include <iostream>
#include <string>

int main(void)
{
   std::cout << "Press Ctrl+D (Linux) or Ctrl+Z (Windows) to send EOF.\n";
   std::string val;
   while (std::cin >> val)
   {
      std::cout << "You type: " << val << std::endl;
   }
}