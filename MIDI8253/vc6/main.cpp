#include <iostream>
#include <windows.h>
#include "MIDI8253.h"
#include "cpuid.h"

using namespace std;

int main(void){
    bool cpuid = SUPPORT_CPUID();
    if(cpuid){
        cout.setf(ios::fixed);
        cout.precision(2);
        long i = GET_CPU_FREQUENT();
        cout << "System CPU: " << GET_CPUID() << " "
             << (i/1000.0) << "GHz(" << i << "MHz)" << endl
             << GET_CPUINF() << endl;
    }else{
        cout << "Your CPU doesn't support CPUID instruction." << endl;
    }
    
	//play_demo();
	return 0;
}
