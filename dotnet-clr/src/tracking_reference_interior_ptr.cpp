// tracking_reference_interior_ptr.cpp
// compile with: /clr
using namespace System;

public ref class R {
public:
   R(int i) : m_i(i) {
      Console::WriteLine("ctor: R(int)");
   }

   int m_i;
};

class N {
public:
   N(int i) : m_i(i) {
      Console::WriteLine("ctor: N(int i)");
   }

   int m_i;
};

int main() {
   R ^hr = gcnew R('r');
   N n('n');

   R ^%thr = hr;
   N %tn = n;

   // Declare interior pointers
   interior_ptr<R^> iphr = &hr;
   interior_ptr<N> ipn = &n;

   // Modify data through interior pointer
   (*iphr)->m_i = 1;   // (*iphr)-> m_i == thr->m_i
   ipn->m_i = 4;   // ipn->m_i == tn.m_i

   ++thr->m_i;   // hr->m_i == thr->m_i
   ++tn.m_i;   // n.m_i == tn.m_i

   ++hr->m_i;   // (*iphr)->m_i == hr->m_i
   ++n.m_i;   // ipn->m_i == n.m_i
}

/*
ctor: R(int)
ctor: N(int i)
*/