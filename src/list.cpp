
#include <list>
#include <iostream>
#include <iomanip>
#include <list>
#include <string>

using namespace std;

template <typename T>
void showlist(list<T> v)
{
    for (typename list<T>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << setw(4) << *it;
    }
    cout << endl;
}

int main()
{
    list<int> l1{ 4,2,3,4,5,5,6,7,7 };
    l1.sort();
    l1.reverse();
    showlist(l1);
    list<double> l2;
    list<char> l3(10);
    list<int> l4(5, 10); // 将元素都初始化为10
    showlist(l4);

    // system("pause");
    return 0;
} 