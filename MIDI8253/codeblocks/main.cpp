#include <windows.h>
#include <iostream>

using namespace std;

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
    int o;
    cout << "delay mips:" << mips << endl;
	asm("\
        mov %1, %%eax   \n\t\
        out %%al, $0x43 \n\t\
        mov %2, %%eax   \n\t\
        out %%al, $0x42 \n\t\
        mov %%ah, %%al  \n\t\
        out %%al, $0x42 \n\t\
        //mov $0x03,%%eax \n\t\
        sub %%eax,%%eax \n\t\
        in  $0x61, %%al \n\t\
        mov %%al, %0    \n\t\
        mov %%al, %%ah  \n\t\
        or  $0x03, %%al \n\t\
        out %%al, $0x61 \n\t\
        mov %3,%%ecx    \n\t\
        WAIT:loop WAIT  \n\t\
        mov %%ah, %%al  \n\t\
        out %%al, $0x61 \n\t"
        : "=r" (o)
        : "r"(control),"r"(frequent),"r"(mips)
        : "eax","ebx","ecx","ah","al","cc" );
	return o;
}

void play(int cpu_frequent) {
    int tempo = 120;
    int beat = (float)60/tempo/4 * cpu_frequent * 1000 * 1000;
    int c = CBIN | MOSQUR | LATCHA | SCNT2;
    int s8255 = PIT8253(NOTE_C, c, beat/4);
    PIT8253(NOTE_C, c, beat );
    PIT8253(NOTE_D, c, beat );
    PIT8253(NOTE_E, c, beat );
    PIT8253(NOTE_C, c, beat );
    PIT8253(MUTE, c, beat/4 );
    PIT8253(NOTE_C, c, beat );
    PIT8253(NOTE_D, c, beat );
    PIT8253(NOTE_E, c, beat );
    PIT8253(NOTE_C, c, beat );
    PIT8253(MUTE, c, beat/4 );
    PIT8253(NOTE_E, c, beat );
    PIT8253(NOTE_F, c, beat );
    PIT8253(NOTE_G, c, beat*2 );
    PIT8253(NOTE_E, c, beat );
    PIT8253(NOTE_F, c, beat );
    PIT8253(NOTE_G, c, beat*2 );
    PIT8253(NOTE_G, c, beat/2 );
    PIT8253(NOTE_A, c, beat/2 );
    PIT8253(NOTE_G, c, beat/2 );
    PIT8253(NOTE_F, c, beat/2 );
    PIT8253(NOTE_E, c, beat );
    PIT8253(NOTE_C, c, beat );
    PIT8253(NOTE_G, c, beat/2 );
    PIT8253(NOTE_A, c, beat/2 );
    PIT8253(NOTE_G, c, beat/2 );
    PIT8253(NOTE_F, c, beat/2 );
    PIT8253(NOTE_E, c, beat );
    PIT8253(NOTE_C, c, beat );
    PIT8253(NOTE_G1,c, beat );
    PIT8253(NOTE_C, c, beat/2 );
    PIT8253(NOTE_E, c, beat );
    PIT8253(NOTE_G1,c, beat );
    PIT8253(NOTE_C, c, beat*2 );
    PIT8253(NOTE_E, c, beat*3/2 );
    PIT8253(NOTE_G1,c, beat*2 );
    PIT8253(NOTE_C, c, beat*3 );
	cout << "Status of chip 8255:" << s8255 << endl;
	return;
}

long GET_CPU_FREQUENT(){
    unsigned long long s = 0, e = 0, ms = 100;
	unsigned int h = 0, l = 0;
    asm("\
        rdtsc           \n\t\
        mov %%eax, %0   \n\t\
        mov %%edx, %1   \n\t"
        : "=r"(l),"=r"(h) : :"eax","edx");
    s = l + h*0xFFFFFFFF;
    Sleep(ms);
    asm("\
        rdtsc           \n\t\
        mov %%eax, %0   \n\t\
        mov %%edx, %1   \n\t"
        : "=g"(l),"=g"(h) : :"eax","edx"); // avoid the same input type from before
    e = l + h*0xFFFFFFFF;
    return (e-s)/ms/1000; // MHz
}

char* CPUID(int index){
    char *buf = new char[17];
    buf[16] = '\0';
    asm("\
        mov %1, %%eax       \n\t\
        cpuid               \n\t\
        mov %%eax, (0)%0   \n\t\
        mov %%ebx, (4)%0   \n\t\
        mov %%ecx, (8)%0   \n\t\
        mov %%edx, (12)%0  \n\t"
        : "=o"(*buf)
        : "r"(index)
        :"eax","ebx","edx","ecx","memory");
    return buf;
}

char* GET_CPUID(){
    char * buf = CPUID(0x00);
    int i = 0;
    for(;i<8;i++){
        int x = i/4 * 4 + 4 + i;
        buf[i] = buf[x];
    }
    buf[12] = '\0';
    return buf;
}

char* GET_CPUINF(){
    char* buf = new char[49];
    int brand = 0x80000002;
    int i = 0, j =0;
    buf[48] = '\0';
    for(i=0;i<3;i++){
        char* b = CPUID(brand++);
        for(j=0;j<16;j++){
            buf[i*16+j] = b[j];
        }
    }
    return buf;
}

int main(void){
    long i = GET_CPU_FREQUENT();
    cout << "System CPU: " << GET_CPUID() << " ";
    cout << i/(float)1000 << "GHz(" << i << "MHz)" << endl;
    cout << GET_CPUINF() << endl;
    play(i);
}
