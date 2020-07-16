#include<cstdio>

int hanoi(int n)
{
	if( n>1 ) return 2 * hanoi( n-1 )+1;
	return 1;
}

void routine(char A, char B, char C,int n)
{
	static int i = 1;
	if( n>1 ){
		routine( A,C,B, n-1); // µÝ³Ì
		printf( "%d: %c => %c \n", i++, A, C );
		routine( B,A,C, n-1); // ¹é³Ì
	}else{
		printf( "%d: %c => %c \n", i++, A, C );
	}
}

int main()
{	
	int n, i;
	
	printf( "Number of tray in Hanoi Tower: ");
	scanf( "%d", &n );
	
	i = hanoi(n);

	printf( "%d tray%cneeds at least %d step%c", n, (n>1?'s':' '), i, (i>1?'s':'.') );;
	printf( "Suppose 6 seconds for every step, that is %d seconds." , i*6 );

	routine('A','B','C',n);

	return 0;
}
