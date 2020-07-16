// const_cast
#include <iostream>
using namespace std;

void print (char * str)
{
  cout << str << endl;
}

int main () {
  const char * c = "sample text";
  char *cc = const_cast<char *> (c) ;
  print(cc);
  return 0;
}