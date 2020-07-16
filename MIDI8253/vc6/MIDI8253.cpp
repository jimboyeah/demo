#include <iostream>
#include <windows.h>
#include "MIDI8253.h"

using namespace std;

int play_note(const int frequent, const float beat )
{
    int old = 0;
    int mips = beat*1000*60/TEMPO/2; // millionseconds
    cout << "delay:" << mips << endl;
	_asm{
		mov eax, CONTROL
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
		push mips
		call Sleep
		//mov ecx, mips
        //WAIT:loop WAIT
		mov al, ah
		out 0x61, al
	}
	return old;
}

int play_demo() {
    float beat = 1;
    int s8253 = 
	play_note(NOTE_G, beat);    cout << "play_note(NOTE_G, beat);\n" << endl;
    play_note(NOTE_F, beat );   cout << "play_note(NOTE_F, beat);\n" << endl;
    play_note(NOTE_E, beat*2 ); cout << "play_note(NOTE_E, beat*2);\n" << endl;
    play_note(NOTE_c, beat );   cout << "play_note(NOTE_c, beat );\n" << endl;
    play_note(NOTE_B, beat );   cout << "play_note(NOTE_B, beat );\n" << endl;
    play_note(NOTE_D, beat*2 ); cout << "play_note(NOTE_D, beat*2 );\n" << endl;

    play_note(NOTE_F, beat/2 ); cout << "play_note(NOTE_F, beat/2 );\n" << endl;
    play_note(NOTE_F, beat/2 ); cout << "play_note(NOTE_F, beat/2 );\n" << endl;
    play_note(NOTE_F, beat );   cout << "play_note(NOTE_F, beat );\n" << endl;
    play_note(NOTE_A, beat/2 ); cout << "play_note(NOTE_A, beat/2 );\n" << endl;
    play_note(NOTE_A, beat/2 ); cout << "play_note(NOTE_A, beat/2 );\n" << endl;
    play_note(NOTE_A, beat );   cout << "play_note(NOTE_A, beat );\n" << endl;
    play_note(NOTE_G, beat );   cout << "play_note(NOTE_G, beat );\n" << endl;
    play_note(NOTE_G, beat*2 ); cout << "play_note(NOTE_G, beat*2 );\n" << endl;

    play_note(NOTE_E, beat/2 ); cout << "play_note(NOTE_E, beat/2 );\n" << endl;
	slide(beat/32,NOTE_F,NOTE_e);cout << "slide(c,beat/32,NOTE_F,NOTE_e);\n" << endl;
    play_note(NOTE_e, beat*2 ); cout << "play_note(NOTE_e, beat*2 );\n" << endl;
    play_note(NOTE_d, beat/2 ); cout << "play_note(NOTE_d, beat/2 );\n" << endl;
    play_note(NOTE_d, beat/2 ); cout << "play_note(NOTE_d, beat/2 );\n" << endl;
    play_note(NOTE_d, beat );   cout << "play_note(NOTE_d, beat );\n" << endl;
    play_note(NOTE_c, beat/2 ); cout << "play_note(NOTE_c, beat/2 );\n" << endl;
    play_note(NOTE_A, beat*2 ); cout << "play_note(NOTE_A, beat*2 );\n" << endl;

    play_note(NOTE_A, beat/2 ); cout << "play_note(NOTE_A, beat/2 );\n" << endl;
    play_note(NOTE_D, beat/2 ); cout << "play_note(NOTE_D, beat/2 );\n" << endl;
    play_note(NOTE_A, beat/2 ); cout << "play_note(NOTE_A, beat/2 );\n" << endl;
    play_note(NOTE_G, beat*2 ); cout << "play_note(NOTE_G, beat*2 );\n" << endl;

    play_note(NOTE_D, beat/2 ); cout << "play_note(NOTE_D, beat/2 );\n" << endl;
    play_note(NOTE_F, beat );   cout << "play_note(NOTE_F, beat );\n" << endl;
    play_note(NOTE_E, beat/2 ); cout << "play_note(NOTE_E, beat/2 );\n" << endl;
    play_note(NOTE_C, beat*2 ); cout << "play_note(NOTE_C, beat*2 );\n" << endl;
	return s8253;
}

void bouncing(int notes[], const float beat) {
	int i = 10;
	int l = sizeof(notes);
	for(i=l; i>0; i--){
		play_note(notes[i%l], beat/l/2 );
	}
	for(i=0; i<l; i++){
		play_note(notes[i%l], beat/l/2 );
	}
	return;
}

void slide(const float beat, int s, const int e) {
	int i = 0, len = 0, t = 0;
	int n[16];
	while(1){
		n[i] = s;
		s = s / 1.06;
		len = i++;
		if(i>=16||s<=e) break;
	}
	n[len] = n[31] = e;
	t = beat/len;
	for(i=0; i<len; i++){
		play_note(n[i], t);
	}
	return;
}
