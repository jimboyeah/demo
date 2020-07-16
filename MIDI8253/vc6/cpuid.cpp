#include <iostream>
#include <windows.h>
#include "cpuid.h"

bool SUPPORT_CPUID(){
	bool spd =false;
	_asm{
		pushfd
		pop eax
		mov ebx, eax
		xor eax, 0x00200000
		push eax
		popfd
		pushfd
		pop eax
		cmp eax, ebx
		je unsuport
			mov spd, -1
		unsuport: 
			nop
	}
	return true; // never mind this
}

long GET_CPU_FREQUENT(){
    long double s, e, ms = 200;
	unsigned int h = 0, l = 0;
    __asm{
        rdtsc 
        mov l, eax
		mov h, edx
	}
    s = l + h*0xFFFFFFFF;
    Sleep(ms); // watcom sleep in seconds
    _asm{
        rdtsc 
        mov l, eax
		mov h, edx
	}
    e = l + h*0xFFFFFFFF;
    return (e-s)/ms/1000; // MHz
}

char* CPUID(unsigned int index){
    char buf[5][4] = {0};
	char *pc = (char *)malloc(20);
	int a = 0, b = 0, c = 0, d = 0;
	int i = 0;
    buf[4][0] = 0;
    _asm{
        mov eax, index
        cpuid
        mov a, eax
        mov b, ebx
        mov c, ecx
        mov d, edx
	}
	*(int*)buf[0] = a;
	*(int*)buf[1] = b;
	*(int*)buf[2] = c;
	*(int*)buf[3] = d;
	//printf("%x %d:%d \n",index, a, b);
	for(i=0; i<16; i++){
		pc[i] = ((char*)&buf)[i];
		//printf(" %d:%c ",i, pc[i]);
	}
    return pc;
}

char* GET_CPUID(){
    char * buf = CPUID(0x00);
    int i = 0;
    for(i=0;i<8;i++){
        int x = i/4 * 4 + 4 + i;
        buf[i] = buf[x];
    }
    buf[12] = 0;
    return buf;
}

char* GET_CPUINF(){
    char *buf = new char[49];
    int brand = 0x80000002;
    int i = 0, j =0;
    for(i=0;i<3;i++){
        char* b = CPUID(brand++);
        for(j=0;j<16;j++){
            buf[i*16+j] = b[j];
			//printf("%c",b[j]);
        }
		free(b);
    }
    buf[48] = 0;
    return buf;
}
