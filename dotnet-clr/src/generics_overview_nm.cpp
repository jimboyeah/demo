// generics_overview.cpp
// compile with: /clr /c
using namespace System;

#using <system.dll>


generic <typename T>

ref class List {};

generic <typename T>

ref class Queue : public List<T> {};

int main()
{
   Console::WriteLine("read the fucking code!");
}