#include <strstrea.h>
#include <string>
using namespace std;

static char *INT1302STATUS = "\
	00h	successful completion\n\
	01h	invalid function in AH or invalid parameter\n\
	02h	address mark not found\n\
	03h	disk write-protected\n\
	04h	sector not found/read error\n\
	05h	reset failed (hard disk)\n\
	05h	data did not verify correctly (TI Professional PC)\n\
	06h	disk changed (floppy)\n\
	07h	drive parameter activity failed (hard disk)\n\
	08h	DMA overrun\n\
	09h	data boundary error (attempted DMA across 64K boundary or >80h sectors)\n\
	0Ah	bad sector detected (hard disk)\n\
	0Bh	bad track detected (hard disk)\n\
	0Ch	unsupported track or invalid media\n\
	0Dh	invalid number of sectors on format (PS/2 hard disk)\n\
	0Eh	control data address mark detected (hard disk)\n\
	0Fh	DMA arbitration level out of range (hard disk)\n\
	10h	uncorrectable CRC or ECC error on read\n\
	11h	data ECC corrected (hard disk)\n\
	20h	controller failure\n\
	31h	no media in drive (IBM/MS INT 13 extensions)\n\
	32h	incorrect drive type stored in CMOS (Compaq)\n\
	40h	seek failed\n\
	80h	timeout (not ready)\n\
	AAh	drive not ready (hard disk)\n\
	B0h	volume not locked in drive (INT 13 extensions)\n\
	B1h	volume locked in drive (INT 13 extensions)\n\
	B2h	volume not removable (INT 13 extensions)\n\
	B3h	volume in use (INT 13 extensions)\n\
	B4h	lock count exceeded (INT 13 extensions)\n\
	B5h	valid eject request failed (INT 13 extensions)\n\
	B6h	volume present but read protected (INT 13 extensions)\n\
	BBh	undefined error (hard disk)\n\
	CCh	write fault (hard disk)\n\
	E0h	status register error (hard disk)\n\
	FFh	sense operation failed (hard disk)\n\
	";

static char *INT1308TYPE = "\
	01h	360K\n\
	02h	1.2M\n\
	03h	720K\n\
	04h	1.44M\n\
	05h	2.88M on some machines (at least AMI 486 BIOS)\n\
	06h	2.88M\n\
	10h	ATAPI Removable Media Device\n\
	";

static char *INT1308STATUS = "\
	00h	successful completion\n\
	01h	invalid function in AH or invalid parameter\n\
	02h	address mark not found\n\
	03h	disk write-protected\n\
	04h	sector not found/read error\n\
	05h	reset failed (hard disk)\n\
	05h	data did not verify correctly (TI Professional PC)\n\
	06h	disk changed (floppy)\n\
	07h	drive parameter activity failed (hard disk)\n\
	08h	DMA overrun\n\
	09h	data boundary error (attempted DMA across 64K boundary or >80h sectors)\n\
	0Ah	bad sector detected (hard disk)\n\
	0Bh	bad track detected (hard disk)\n\
	0Ch	unsupported track or invalid media\n\
	0Dh	invalid number of sectors on format (PS/2 hard disk)\n\
	0Eh	control data address mark detected (hard disk)\n\
	0Fh	DMA arbitration level out of range (hard disk)\n\
	10h	uncorrectable CRC or ECC error on read\n\
	11h	data ECC corrected (hard disk)\n\
	20h	controller failure\n\
	31h	no media in drive (IBM/MS INT 13 extensions)\n\
	32h	incorrect drive type stored in CMOS (Compaq)\n\
	40h	seek failed\n\
	80h	timeout (not ready)\n\
	AAh	drive not ready (hard disk)\n\
	B0h	volume not locked in drive (INT 13 extensions)\n\
	B1h	volume locked in drive (INT 13 extensions)\n\
	B2h	volume not removable (INT 13 extensions)\n\
	B3h	volume in use (INT 13 extensions)\n\
	B4h	lock count exceeded (INT 13 extensions)\n\
	B5h	valid eject request failed (INT 13 extensions)\n\
	B6h	volume present but read protected (INT 13 extensions)\n\
	BBh	undefined error (hard disk)\n\
	CCh	write fault (hard disk)\n\
	E0h	status register error (hard disk)\n\
	FFh	sense operation failed (hard disk)\n\
	";

static char *INT1342STATUS = "\
	00h	successful completion\n\
	01h	invalid function in AH or invalid parameter\n\
	02h	address mark not found\n\
	03h	disk write-protected\n\
	04h	sector not found/read error\n\
	05h	reset failed (hard disk)\n\
	05h	data did not verify correctly (TI Professional PC)\n\
	06h	disk changed (floppy)\n\
	07h	drive parameter activity failed (hard disk)\n\
	08h	DMA overrun\n\
	09h	data boundary error (attempted DMA across 64K boundary or >80h sectors)\n\
	0Ah	bad sector detected (hard disk)\n\
	0Bh	bad track detected (hard disk)\n\
	0Ch	unsupported track or invalid media\n\
	0Dh	invalid number of sectors on format (PS/2 hard disk)\n\
	0Eh	control data address mark detected (hard disk)\n\
	0Fh	DMA arbitration level out of range (hard disk)\n\
	10h	uncorrectable CRC or ECC error on read\n\
	11h	data ECC corrected (hard disk)\n\
	20h	controller failure\n\
	31h	no media in drive (IBM/MS INT 13 extensions)\n\
	32h	incorrect drive type stored in CMOS (Compaq)\n\
	40h	seek failed\n\
	80h	timeout (not ready)\n\
	AAh	drive not ready (hard disk)\n\
	B0h	volume not locked in drive (INT 13 extensions)\n\
	B1h	volume locked in drive (INT 13 extensions)\n\
	B2h	volume not removable (INT 13 extensions)\n\
	B3h	volume in use (INT 13 extensions)\n\
	B4h	lock count exceeded (INT 13 extensions)\n\
	B5h	valid eject request failed (INT 13 extensions)\n\
	B6h	volume present but read protected (INT 13 extensions)\n\
	BBh	undefined error (hard disk)\n\
	CCh	write fault (hard disk)\n\
	E0h	status register error (hard disk)\n\
	FFh	sense operation failed (hard disk)\n\
	";

static char * INT_search( char *table, const int id){
	istrstream *inf = new istrstream( table);
	char s[256];
	int i;
	inf>>i;
	inf>>s;
	cout << s << " :" << i;
	return "TODO";
}

/*
 * Translate INT return value or status into text
 * exm: INT_msg( INT1342STATUS, 0x00) = "successful completion"
 * des: Fail to return "INT_msg_failed" for noting found.
 *		Return "INT_msg_undefined" for absent table.
 */
static char *INT_msg(char *target, const int id){
	char *r;
	r = INT_search(target,id);
	if( strlen(r)==0 ) return "INT_msg_failed";
	return r;
}

