#ifndef FORMAT_H
#include <avr/pgmspace.h>

typedef unsigned char	u8;
typedef char			s8;
typedef unsigned short	u16;
typedef short			s16;
typedef unsigned long	u32;
typedef long			s32;

#define NUM_NOTES (12*3)
extern const u16 periodTable[NUM_NOTES];// PROGMEM;

#define MAX_PERIOD 856
#define MIN_PERIOD 113
#define NO_PERIOD 0xFFFF

#define NO_NOTE			0x3Fu
#define NO_INST_PATTERN 0x00u
#define NO_INST         0xFFu

#define DEFAULT_SPEED 6
#define DEFAULT_BPM   125

struct sections_s
{
    u8		numinsts;
    u16		offsetinsts;
    u8		numorders;
    u16		offsetorders;
    u8		numpatterns;
    u16		offsetpatterns;
    u8		numsamples;
    u16		offsetsamples;
    u8		numnames;
    u16		offsetnames;
};

/** Pattern Packing Format **
	*  uses 3 bytes per note
	*     -00-     -01-     -02-
	*  |  BYTE  |  BYTE  |  BYTE  |
	*   AAAAAABB BBCCCCCX DDDDDDDD
	*
	*  NOTE NUMBER = AAAAAA
	*  EFFECT      = BBBB
	*  INST NUMBER = CCCCC
	*  EFFECT PARM = DDDDDDDD
	*  UNUSED      = X
*/

#define NOTE_SIZE 3
#define PATTERN_CHANNELS 4
#define PATTERN_ROWS 64
#define PATTERN_SIZE ( NOTE_SIZE * PATTERN_CHANNELS * PATTERN_ROWS )

#define MAX_VOLUME 63
#define MIN_VOLUME 0

#endif
