#include <iostream>

#include "main.h"
#include "lib.h"
#include "print.h"

using namespace std;

int main(void)
{
	print("1+2+3=");
	cout << sum(1,2,3) << endl;
}