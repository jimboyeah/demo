#include "lib.h"

int sum(int a, int b, int c)
{
	return a+b+c;
}

EXPORT bool CheckForMDAC(int a,int b )
{
	char ca = 8,cb=-8;
	ca = ca+cb;
	ca = 128,cb=128;
	ca = ca+cb;
	ca = -128,cb=-128;
	ca = ca+cb;
	a=-1,b=-1;
	a=a+b;
	a=0x7fffffff,b=0x7fffffff;
	a=a+b;

	return true;
}