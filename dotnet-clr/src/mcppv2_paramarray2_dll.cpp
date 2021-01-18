// mcppv2_paramarray2.cpp
// compile with: /clr:safe /LD
using namespace System;

#include <cstdio>

public ref class C {
public:
    void f( ... array<String^>^ a ) {
        Console::WriteLine("1 -> {0}\n2 -> {1}\n...", a[0], a[1]);
        printf("1 -> %s\n2 -> %s\n...", a[0]->ToCharArray(), a[1]->ToCharArray());
    }
};