
#include <iostream>
#include <string>
 
// using std::string;
// using std::cout;
using namespace std;
 
int main ()
{
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

    cout << "Greeting message: ";
    cout << greeting << endl;

    string ss [] = {"Beijing", "Shanghai", "Chengdu"};
    cout << ss[1];

    return 0;
}
