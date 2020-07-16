#ifndef MIDI8253_H
#define MIDI8253_H

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

static int TEMPO = 120;
static int CONTROL = CBIN | MOSQUR | LATCHA | SCNT2;

int play_demo();
int play_note(const int frequent, const float beat );
/*
int play_minim(int NOTE);
int play_quater(int NOTE);
int play_quaver(int NOTE);
int play_semiquaver(int NOTE);
int play_demisemiquaver(int NOTE);
int play_hemidemisemiquaver(int NOTE);
*/
void bouncing(int notes, const float beat);
void slide(const float beat, int s, const int e);

#endif // MIDI8253