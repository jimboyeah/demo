/* 杨季文《80x86汇编语言程序设计教程》 */

#include"stdio.h"
#include"Wtypes.h"
#include "dos.h"

DWORD _cr0;
void _declspec(naked) ring0isr(void)
{
    _asm
    {
        mov eax,cr0//ring 0 level command
        mov _cr0,eax
    }
    _asm iretd//interrupt return;
}

void main()
{
    DWORDLONG idtr = 0, saveidt = 0;
    WORD gate[4]={0x0000,0x0028,0xee00,0x0000};
union REGS s;

    _asm
    {
        sidt idtr
        mov ebx ,DWORD ptr[idtr+2];
        add ebx,24
        mov esi,ebx
        lea edi,saveidt
        movsd
        movsd
        lea eax,ring0isr
        mov gate ,ax
        shr eax,16
        mov [gate+6],ax
        lea esi,gate
        mov edi,ebx
        movsd
        movsd
        int 3h
        lea esi,saveidt
        mov edi,ebx
        movsd
        movsd
    }
    printf("cr0=0x%x",_cr0);
}