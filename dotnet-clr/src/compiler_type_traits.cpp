// compiler_type_traits.cpp
// compile with: /clr

using namespace System;
#include <stdio.h>

template <class T>
ref struct is_class {
   literal bool value = __is_ref_class(T);
};

ref class R {};

int main () {
   if (is_class<R>::value)
      Console::WriteLine("R is a ref class");
   else
      Console::WriteLine("R is not a ref class");
}

// // __has_assign( type ) <========================================================================

// ref struct R {
//     void operator=(R% r) {}
// };

// int __has_assign_test() {
//     System::Console::WriteLine(__has_assign(R));
// }

// // __has_copy( type ) <==========================================================================

// ref struct R {
// R(R% r) {}
// };

// int __has_copy_test() {
//     System::Console::WriteLine(__has_copy(R));
// }

// // __has_finalizer( type ) <=====================================================================

// ref struct R {
// ~R() {}
// protected:
// !R() {}
// };

// int __has_finalizer_test() {
//     Console::WriteLine(__has_finalizer(R));
// }

// // __has_nothrow_assign( type ) <================================================================

// struct S {
// void operator=(S& r) throw() {}
// };

// int __has_nothrow_assign_test() {
//     __has_nothrow_assign(S) == true ?
//     printf("true\n") : printf("false\n");
// }

// // __has_nothrow_constructor( type ) <===========================================================

// struct S {
// S() throw() {}
// };

// int __has_nothrow_constructor_test() {
//     __has_nothrow_constructor(S) == true ?
//     printf("true\n") : printf("false\n");
// }

// // __has_nothrow_copy( type ) <==================================================================

// struct S {
// S(S& r) throw() {}
// };

// int __has_nothrow_copy_test() {
//     __has_nothrow_copy(S) == true ?
//     printf("true\n") : printf("false\n");
// }

// // __has_trivial_assign( type ) <================================================================

// struct S {};

// int __has_trivial_assign_test() {
//     __has_trivial_assign(S) == true ?
//     printf("true\n") : printf("false\n");
// }

// // __has_trivial_constructor( type ) <===========================================================

// struct S {};

// int __has_trivial_constructor_test() {
//     __has_trivial_constructor(S) == true ?
//     printf("true\n") : printf("false\n");
// }

// // __has_trivial_copy( type ) <==================================================================

// struct S {};

// int __has_trivial_copy_test() {
//     __has_trivial_copy(S) == true ?
//     printf("true\n") : printf("false\n");
// }

// // __has_trivial_destructor( type ) <============================================================

// // has_trivial_destructor.cpp
// struct S {};

// int __has_trivial_destructor_test() {
//     __has_trivial_destructor(S) == true ?
//     printf("true\n") : printf("false\n");
// }

// // __has_user_destructor( type ) <===============================================================

// // has_user_destructor.cpp

// ref class R {
// ~R() {}
// };

// int __has_user_destructor_test() {
//     Console::WriteLine(__has_user_destructor(R));
// }

// // __has_virtual_destructor( type ) <============================================================

// // has_virtual_destructor.cpp
// struct S {
// virtual ~S() {}
// };

// int __has_virtual_destructor_test() {
//     __has_virtual_destructor(S) == true ?
//     printf("true\n") : printf("false\n");
// }

// // __is_abstract( type ) <=======================================================================

// // is_abstract.cpp
// struct S {
// virtual void Test() = 0;
// };

// int __is_abstract_test() {
//     __is_abstract(S) == true ?
//     printf("true\n") : printf("false\n");
// }

// // __is_base_of( base , derived ) <==============================================================

// // is_base_of.cpp
// struct S {};
// struct T : public S {};

// int __is_base_of_test() {
//     __is_base_of(S, T) == true ?
//     printf("true\n") : printf("false\n");

//     __is_base_of(S, S) == true ?
//     printf("true\n") : printf("false\n");
// }

// // __is_class( type ) <==========================================================================

// struct S {};

// int __is_class_test() {
//     __is_class(S) == true ?
//     printf("true\n") : printf("false\n");
// }

// // __is_convertible_to( from , to ) <============================================================

// struct S {};
// struct T : public S {};

// int ma=_test() {
// S * s = new S;
// T * t = new T;
// s = t;
//     __is_convertible_to(T, S) == true ?
//     printf("true\n") : printf("false\n");
// }

// // __is_delegate( type ) <=======================================================================

// delegate void MyDel();
// int __is_delegate_test() {
//     System::Console::WriteLine(__is_delegate(MyDel));
// }

// // __is_empty( type ) <==========================================================================

// struct S {
// int Test() {}
// static int i;
// };
// int __is_empty_test() {
//     __is_empty(S) == true ?
//     printf("true\n") : printf("false\n");
// }

// // __is_enum( type ) <===========================================================================

// // is_enum.cpp
// enum E { a, b };

// struct S {
// enum E2 { c, d };
// };

// int __is_enum_test() {
//     __is_enum(E) == true ?
//     printf("true\n") : printf("false\n");

//     __is_enum(S::E2) == true ?
//     printf("true\n") : printf("false\n");
// }

// // __is_interface_class( type ) <================================================================

// interface class I {};
// int __is_interface_class_test() {
//     Console::WriteLine(__is_interface_class(I));
// }

// // __is_pod( type ) <============================================================================

// struct S {};

// int __is_pod_test() {
//     __is_pod(S) == true ?
//     printf("true\n") : printf("false\n");
// }

// // __is_polymorphic( type ) <====================================================================

// struct S {
//     virtual void Test(){}
// };

// int __is_polymorphic_test() {
//     __is_polymorphic(S) == true ?
//     printf("true\n") : printf("false\n");
// }

// // __is_ref_array( type ) <======================================================================

// int __is_ref_array_test() {
//     array<int>^ __is_ref_array_test= gcnew array<int>(10);
//     Console::WriteLine(__is_ref_array(array<int>));
// }

// // __is_ref_class( type ) <======================================================================

// ref class R {};
// int __is_ref_class_test() {
//     Console::WriteLine(__is_ref_class(Buffer));
// Console::WriteLine(__is_ref_class(R));
// }

// // __is_sealed( type ) <=========================================================================

// ref class R sealed{};
// int __is_sealed_test() {
//     System::Console::WriteLine(__is_sealed(R));
// }

// // __is_simple_value_class( type ) <=============================================================


// ref class R {};
// value struct V {};
// value struct V2 {
// R ^ r;   // not a simnple value type
// };

// int __is_simple_value_class_test() {
//     Console::WriteLine(__is_simple_value_class(V));
//     Console::WriteLine(__is_simple_value_class(V2));
// }

// // __is_union( type ) <==========================================================================

// union A {
//     int i;
//     float f;
// };

// int __is_union_test() {
//     __is_union(A) == true ?
//     printf("true\n") : printf("false\n");
// }

// // __is_value_class( type ) <====================================================================

// value struct V {};

// int __is_value_class_test() {
//     System::Console::WriteLine(__is_value_class(V));
// }
