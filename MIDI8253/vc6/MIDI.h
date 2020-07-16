#ifndef MIDI_H
#define MIDI_H

typedef struct MIDI838 {
	char MAGIC[4]; // MThd
	int	 hSize;
	short int tracks;
	short int quater; // delta-time
} MIDI838;

typedef struct Track{
	char MAGIC[4]; // MTrk
	int  length;
};


#endif // MIDI_H