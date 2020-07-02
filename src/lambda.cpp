#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
 
int main()
{
    std::vector<int> c = {1, 2, 3, 4, 5, 6, 7};
    int x = 5;
    c.erase(std::remove_if(c.begin(), c.end(), [x](int n) { return n < x; }), c.end());
 
    std::cout << "remove x<5 from c: ";
    std::for_each(c.begin(), c.end(), [](int i){ std::cout << i << ' '; });
    std::cout << '\n';
 
    // the type of a closure cannot be named, but can be inferred with auto
    auto plus4 = [](int i) { return i + 4; };
    std::cout << "plus4(6): " << plus4(6) << '\n';
 
    // like all callable objects, closures can be captured in std::function
    // (this may incur unnecessary overhead)
    std::function<int(int)> plus4f = [](int i) { return i + 4; };
    std::cout << "plus4f(6): " << plus4f(6) << '\n';
}