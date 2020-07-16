#include <stdio.h>
#include <dos.h>
#include"malloc.h"  


#define CBIN	0x00  // Binary Counter
#define CBCD	0x01  // Binary Coded Decimal Counter
#define MOINTR	0x00  // Count Terminal Interupt
#define MOSHOT	0x02  // Programmable One-Shot
#define MORATE	0x04
#define MOSQUR	0x06
#define MOSOFT	0x08
#define MOHARD	0x0A
#define LATCH0	0x00
#define LATCHL	0x10 // latch low 8-bit
#define LATCHH	0x20 // latch hight 8-bit
#define LATCHA	0x30 // auto low then high 8-bit
#define SCNT0	0x00
#define SCNT1	0x40
#define SCNT2	0x80

#define MUTE 0xffff
#define NOTE_A2 0x1530 // 220Hz
#define NOTE_B2 0x12DF // 247Hz
#define NOTE_C1 0x11CB // 262Hz
#define NOTE_D1 0x0FDB // 294Hz
#define NOTE_E1 0x0E20 // 330Hz
#define NOTE_F1 0x0D52 // 350Hz
#define NOTE_G1 0x0BE4 // 392Hz
#define NOTE_A1 0x0A98 // Standard Pitch A1 = 440Hz
#define NOTE_B1 0x0970 // 494Hz
#define NOTE_C 0x08E6 // 524Hz
#define NOTE_D 0x07EE // 588Hz
#define NOTE_E 0x0710 // 660Hz
#define NOTE_F 0x06AB // 699Hz
#define NOTE_G 0x05F2 // 784Hz
#define NOTE_A 0x054C // 880Hz
#define NOTE_B 0x04B8 // 988Hz
#define NOTE_c 0x0474 // 1047Hz
#define NOTE_d 0x03F8 // 1175Hz
#define NOTE_e 0x0389 // 1319Hz
#define NOTE_f 0x0357 // 1397Hz
#define NOTE_g 0x02F9 // 1568Hz
#define NOTE_a 0x02A6 // 1761Hz
#define NOTE_b 0x025C // 1976Hz
#define NOTE_c1 0x023A // 2094Hz
#define NOTE_d1 0x01FC // 2350Hz
#define NOTE_e1 0x01C5 // 2638Hz
#define NOTE_f1 0x01AC // 2794Hz
#define NOTE_g1 0x017D // 3136Hz
#define NOTE_a1 0x0153 // 3521Hz
#define NOTE_b1 0x012E // 3952Hz
#define NOTE_c2 0x011D // 4187Hz
#define NOTE_d2 0x00FE // 4699Hz
#define NOTE_e2 0x00E3 // 5275Hz
#define NOTE_f2 0x00D6 // 5588Hz
#define NOTE_g2 0x00BF // 6272Hz
#define NOTE_a2 0x00AA // 7041Hz

int PIT8253(int frequent, int control, int mips )
{
    int old = 0;
    printf("delay mips:%.8u\n", mips);
	_asm{
		mov eax, control
		out 0x43, al
		mov eax, frequent
		out 0x42, al
		mov al, ah
		out 0x42, al
		sub eax, eax
		in  al, 0x61
		mov old, eax
		mov ah, al
		or  al, 0x03
		out 0x61, al
		mov eax, mips
		call delay
		//mov ecx, mips
        //WAIT:loop WAIT
		mov al, ah
		out 0x61, al
	}
	return old;
}

void play(int cpu_frequent) {
    int tempo = 80;
    //int beat = (float)60/tempo/4 * cpu_frequent * 1000 * 1000;
	int beat = 1000*60/tempo/2; // millionseconds
    int c = CBIN | MOSQUR | LATCHA | SCNT2;
    int s8255 = 
	PIT8253(NOTE_G, c, beat);
    PIT8253(NOTE_F, c, beat );
    PIT8253(NOTE_E, c, beat*2 );
    PIT8253(NOTE_c, c, beat );
    PIT8253(NOTE_B, c, beat );
    PIT8253(NOTE_D, c, beat*2 );

    PIT8253(NOTE_F, c, beat/2 );
    PIT8253(NOTE_F, c, beat/2 );
    PIT8253(NOTE_F, c, beat );
    PIT8253(NOTE_A, c, beat/2 );
    PIT8253(NOTE_A, c, beat/2 );
    PIT8253(NOTE_A, c, beat );
    PIT8253(NOTE_G, c, beat );
    PIT8253(NOTE_G, c, beat*2 );

    PIT8253(NOTE_E, c, beat/2 );
	slide(c,beat/32,NOTE_F,NOTE_e);
    PIT8253(NOTE_e, c, beat*2 );
    PIT8253(NOTE_d, c, beat/2 );
    PIT8253(NOTE_d, c, beat/2 );
    PIT8253(NOTE_d, c, beat );
    PIT8253(NOTE_c, c, beat/2 );
    PIT8253(NOTE_A, c, beat*2 );

    PIT8253(NOTE_A, c, beat/2 );
    PIT8253(NOTE_D, c, beat/2 );
    PIT8253(NOTE_A, c, beat/2 );
    PIT8253(NOTE_G, c, beat*2 );

    PIT8253(NOTE_D, c, beat/2 );
    PIT8253(NOTE_F, c, beat );
    PIT8253(NOTE_E, c, beat/2 );
    PIT8253(NOTE_C, c, beat*2 );
	//bouncing(c, beat);
	printf("Status of chip 8255: 0x%x \n", s8255);
	return;
}

void bouncing(int c, int beat) {
	int i = 10;
	int n[5] = {NOTE_C, NOTE_E, NOTE_G, NOTE_c, NOTE_e};
	for(; i>0; i--){
		PIT8253(n[i%5], c, beat/5 );
	}
	return;
}

void slide(int c, const int beat, int s, int e) {
	int i = 0, len = 0, t = 0;
	int n[24];
	while(1){
		n[i] = s;
		s = s / 1.06;
		len = i++;
		if(i>=24||s<=e) break;
	}
	n[len] = n[31] = e;
	t = beat/len;
	for(i=0; i<len; i++){
		PIT8253(n[i], c, t);
	}
	return;
}

long GET_CPU_FREQUENT(){
    unsigned long long s, e, ms = 200;
	unsigned int h = 0, l = 0;
    _asm{
        rdtsc
        mov l, eax
		mov h, edx
	}
    s = l + h*0xFFFFFFFF;
    //sleep(ms); // watcom sleep in seconds
	//test in dosbox: config -set "cpu cycles=10000"
	delay(ms);
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
    char *buf = malloc(49);
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

int main(void){
    long i = GET_CPU_FREQUENT();
    printf("System CPU: %s ", GET_CPUID() );
    printf("%.2fGHz(%dMHz)\n", (i/1000.0), i );
    printf("%s\n", GET_CPUINF() );
	play(i);
	return 0;
}
