#include <iostream>
#include <vector>
 
int main() {
    std::vector<int> v = {0, 1, 2, 3, 4, 5};
 
    // access by const reference
    for (const int& i : v) std::cout << i << ' ';
    std::cout << '\n';
 
    // access by value, the type of i is int
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
 
    // access by reference, the type of i is int&
    for (auto&& i : v) std::cout << i << ' ';
    std::cout << '\n';
 
    // the initializer may be a braced-init-list
    for (int n : {0, 1, 2, 3, 4, 5}) std::cout << n << ' ';
    std::cout << '\n';
 
    int a[] = {0, 1, 2, 3, 4, 5};
    // the initializer may be an array
    for (int n : a) std::cout << n << ' ';
    std::cout << '\n';
 
    // the loop variable need not be used
    for (int n : a) std::cout << 1 << ' ';
    std::cout << '\n';
 
}