#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class Stack 
{
private:
    vector<T> elems;

public:
    Stack<T>& push(T const&);
    T pop();
    T top() const;
    bool empty() const {
        return elems.empty();
    }
    int size() const {
        return elems.size();
    }
};

template<class T>
Stack<T>& Stack<T>::push(T const& elem)
{
    elems.push_back(elem);
    return *this;
}

template<class T>
T Stack<T>::pop()
{
    if (elems.empty())
    {
        throw out_of_range("<Stack<T>::pop() with empty stack");
    }
    T back = elems.back();
    elems.pop_back();
    return back;
}

template <class T>
T Stack<T>::top() const
{
    if (elems.empty())
    {
        throw out_of_range("<Stack<T>::top() with empty stack");
    }
    return elems.back();
}

int main()
{
    try
    {
        Stack<int> iStack;
        Stack<string> sStack;

        iStack.push(7).push(8);
        cout << iStack.pop() << endl;
        cout << iStack.top() << endl;

        sStack.push("hello").push("world");
        cout << sStack.pop() << sStack.pop()  << endl;
        sStack.pop();
    } catch (exception const& ex)
    {
        cerr << "Exception: " << ex.what() << endl;
        return -1;
    }
}
