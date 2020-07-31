// friend_assemblies_2.cpp
// compile by using: /clr
#using "..\bin-clr\friend_assembly_internal.dll" as_friend

int main() {
   Class1 ^ a = gcnew Class1;
   a->Test_Public();
}