#include <stdlib.h>
#include <stdio.h>

void main(void){
	unsigned long t[4] = {0x00,0x12,0x0444,0xFFF0};
	_asm
    {
        //INT 3
        MOV eax, 00
        INT 0x1A
		MOV ax, cx
		ROL eax, 16
		MOV ax, dx
		MOV t, eax
		MOV ecx, 3
		MOV ecx, 3
		RE:
		/* eax store quotient and remainer on edx */
		XOR edx, edx
		DIV t[ecx*4]
		MOV t[ecx*4], eax
		MOV eax, edx
		LOOP RE
    }
	printf("Time now %u: %02d:%02d:%02d\n",t[0],t[3],t[2],t[1]);
}

