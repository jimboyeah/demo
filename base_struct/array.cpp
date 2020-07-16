#include <stdio.h>

void t(int *a[], int i){
	printf("value %d: %d\n",i, a[i]);
}

int main(){
	int  *ap1 [2]; // array which contain two pointer to int[2]. [ (int[2])*,(int[2])* ]
	int (*ap2)[2]; // 'int (*)[2]', symbol [] precced */&
	int ia[]={3,6},ja[]={4,7},ka[]={5,8},la[]={2,9};

	ap1[0] = ia;   // copy ia to ap1[0]
	ap1[1] = ka;
	ap2 = &ja;
	
	printf("Address ijkl:%d, %d, %d, %d\n",&ia, &ja, &ka, &la);
	printf("  Address A: %d, %d\n",&ap1, &ap2);
	printf("  Address 0: %d, %d\n",&ap1[0], &ap2[0]);       // &ap1[0] = &(ap1[0])
	printf("  Address 1: %d, %d\n",&ap1[1], &ap2[1]);
	printf("  Address N: %d, %d\n",&ap1[1][0], &ap2[1][0]); // ap2[1][x] is error
	printf("  Address M: %d, %d\n",&ap1[1][1], &ap2[1][1]);
	printf("     Values: %d, %d\n",ap1[0], ap2[0]);
	printf("     Values: %d, %d\n",ap1[1], ap2[1]);		 // error use app[2]
	printf("     Values: %d, %d\n",ap1[1][1], ap2[1]);

	t(ap1,0); // print address of ia

	return 0;
}