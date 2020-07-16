#include "iostream"
#include <stdlib.h>

using namespace std;

//求下面函数的返回值(微软)
//假定x = 9999. 答案：8
//思路：将x转化为2进制，看含有的1的个数。

int main(int argc, char** args, char ** envs)
{
    cout << "argument counter:" << argc << endl;
    for(int i=0; i<argc; i++){
        cout << "argument " << i << ":" << args[i] << endl;
    }

    if(argc != 2){
        cout << "USAGE: bitfind number \nTo find how many bit is seted in a number. For example:\n bitfind 16." << endl;
        return 1;
    }

    int x = atoi(args[1]);
    int countx = 0;
    while(x)
    {
        countx ++;
        x = x&(x-1);
    }
    cout << "counter:" << countx << endl;
    return countx;
}
