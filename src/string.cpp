#include <iostream>
#include <string>
 
using namespace std;
 
int main ()
{
   string str1 = "Hello";
   string str2 = "World";
   string str3;
   int  len ;
 
   str3 = str1;
   cout << "str3 : " << str3 << endl;
 
   str3 = str1 + str2;
   cout << "str1 + str2 : " << str3 << endl;
 
   // str3.resize(5);
   len = str3.size();
   cout << "str3.size() :  " << len << endl;
 
   // c++11 raw string literials
   string raw_str = R"(
     some raw string...
   )";
   cout << raw_str;
   
   return 0;
}