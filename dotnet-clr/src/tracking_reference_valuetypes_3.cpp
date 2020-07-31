// tracking_reference_valuetypes_3.cpp
// compile with: /clr
value struct G {
   int i;
};

struct H {
   int i;
};

int main() {
   G g;
   G % v = g;
   v.i = 4;
   System::Console::WriteLine(v.i);
   System::Console::WriteLine(g.i);

   H h;
   H % w = h;
   w.i = 5;
   System::Console::WriteLine(w.i);
   System::Console::WriteLine(h.i);
}