/*********************************************************************\
	IA32 CPU Instructions demo by Jimbowhy 2016/4/1 18:10:28
	Compiler: Visual C++ 6, TDM-GCC 4.7.1
	
	CPUID Opcode [0F A2] CPU Identification
	The ID flag (bit 21) in the EFLAGS register indicates support for the CPUID instruction.
	CPUID returns processor identification and feature information in the EAX, EBX, ECX, and EDX registers.

	RDTSC Opcode [0F 31] Read time stamp counter
	Loads the current value of the processor's time-stamp counter,
	a 64-bit MSR into the EDX:EAX registers.

	RDTSCP Opcode [0F 01 F9] Read time stamp counter and processor ID
	Acts like what RDTSC will do, and also loads the IA32_TSC_AUX MSR 
	(address C000_0103H) into the ECX register.

	Text Out:
	CPU Information:
	  CPU Frequency: 1570 MHZ
	CPU Manufacture: AuthenticAMD
		   CPU Type: AMD Phenom(tm) II P920 Quad-Core Processor
\*********************************************************************/

#include <cstdio>
#include <cstring>
#include <ctime>

void sleep( int ms )
{
	clock_t wait = clock() + ms * CLOCKS_PER_SEC / 1000;
	while (clock() < wait) { /* do nothing just waiting */ }
}

#ifdef _MSC_VER // for MSVC inline assembly

char * CPUID(unsigned int v)
{
	int r[4];
	__asm
	{
		mov eax,v
		cpuid
		mov r+0, eax
		mov r+4, ebx
		mov r+8, ecx
		mov r+12,edx
    }
	char *ret = new char[16];
	memcpy( ret, r, 16 );
	return ret;
}
/* tricky code
	int *r = new int[4]; access violated
	unsigned int r[4];
	__asm
	{
		mov eax,v
		cpuid
		mov r[0],eax  // mov	dword ptr [ebp-10h],eax
		mov r[1],ebx  // mov	dword ptr [ebp-0Fh],ebx
		mov r[2],ecx  // mov	dword ptr [ebp-0Eh],ecx
		mov r[3],edx  // mov	dword ptr [ebp-0Dh],edx
    }
*/

//@return frequency in MHz
int GetCPUFreq()
{
	int s,e;
	_asm rdtsc
	_asm mov s,eax
	sleep(50);
	_asm rdtsc
	_asm mov e,eax
	return (e-s)/50000;
}

#else // for GCC inline assembly
// asm ( "statements" : output_registers : input_registers : clobbered_registers);

char * CPUID(unsigned int v)
{
	unsigned int *r = new unsigned int[4];
	memset( r, 0, 4*sizeof(int) );
	__asm__ __volatile__(""::"a"(v) );
	asm("cpuid");
	asm __volatile__("":"=a"(r[0]), "=b"(r[1]), "=c"(r[2]), "=d"(r[3]) );
	return (char *) r;
}

int GetCPUFreq()
{
	int s, e;
	asm __volatile__( "rdtsc":"=a"(s) );
	sleep(50);
	asm __volatile__( "rdtsc":"=a"(e) );
	return (e-s)/50000;
}

#endif


//@return manufacture
char * GetManuID()
{
	char *id = new char[16];
	memset( id, 0, 16 );
	char *r = CPUID(0);
	memcpy( id+0, r+4,  4 );
	memcpy( id+4, r+12, 4 );
	memcpy( id+8, r+8,  4 );
	delete r;
	return id;
}

char * GetCPUType()
{
	unsigned int id = 0x80000002;
	char *type = new char[64];
	memset( type, 0, 64 );

	for(int t = 0 ; t < 3 ; t++ )
	{
		char *r = CPUID(id+t);
		memcpy( type + 16*t + 0, r+0, 4 );
		memcpy( type + 16*t + 4, r+4, 4 );
		memcpy( type + 16*t + 8, r+8, 4 );
		memcpy( type + 16*t +12, r+12,4 );
		delete r;
	}

	return type;
}

int main()
{
	printf("CPU Information: \n");
	printf("  CPU Frequency: %d%s\n", GetCPUFreq(), "MHz");
	printf("CPU Manufacture: %s\n",   GetManuID() );
	printf("       CPU Type: %s\n",   GetCPUType() );
	return 0;
}
