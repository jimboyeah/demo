#include <iostream> 
#include <cstring> 
#include <boost/scoped_array.hpp>

char *get(const char *s) 
{ 
  int size = std::strlen(s); 
  // char *text = new char[size + 1]; 
  // std::strncpy(text, s, size + 1); 
  // return text; 
  boost::scoped_array<char> cs(new char[size + 1]);
  std::strncpy(cs.get(), s, size + 1); 
  return cs.get(); 
} 

void print(char *text) 
{ 
  std::cout << text << std::endl; 
} 

int main(int argc, char *argv[]) 
{ 
  if (argc < 2) 
  { 
    std::cerr << argv[0] << " <data>" << std::endl; 
    return 1; 
  } 

  char *text = get(argv[1]); 
  print(text); 
  delete[] text; 
} 
