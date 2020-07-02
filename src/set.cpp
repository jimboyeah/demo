#include <iostream>
#include <iomanip>
#include <set>
#include <string>

using namespace std;

template <typename T>
void showset(set<T> v)
{
    for (typename set<T>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << setw(10) << left << *it;
    }
    cout << endl;
}

int main()
{
    set<int> nums{9,8,1,2,3,4,5,5,5,6,7,7 };
    showset(nums);
    set<string> fruits{ "pineapple", "apple", "melon", "peach" };
    showset(fruits);

    nums.insert(9); // do nothing for existing one
    fruits.insert("berry");
    showset(fruits);
    
    // system("pause");
    return 0;
} 