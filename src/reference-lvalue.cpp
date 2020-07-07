#include <iostream>

void process_(int& i){
    std::cout << "process_lvalue_reference ... " << i << std::endl;
}

void process_(int&& i){
    std::cout << "process_rvalue_reference ... " << i << std::endl;
}

template<typename T> 
void forward_(T&& i){
    process_(std::forward<T>(i));
    std::cout << "is_rvalue_reference ... " << std::is_rvalue_reference<T&&>::value << std::endl;
    std::cout << "is_lvalue_reference ... " << std::is_lvalue_reference<T&&>::value << std::endl;
    std::cout << "is_same<T&&, T> ... " << std::is_same<T&&, T>::value << std::endl;
    std::cout << "is_same<T&, T> ... " << std::is_same<T&, T>::value << std::endl;
}

int main()
{
    int i = 0;
    const int j = i;
    process_(i);            // process_lvalue_reference ... 0
    process_(1);            // process_rvalue_reference ... 1
    process_(std::move(i)); // process_rvalue_reference ... 0
    forward_(i);            // process_lvalue_reference ... 0
    forward_(std::move(i)); // process_rvalue_reference ... 0
}
