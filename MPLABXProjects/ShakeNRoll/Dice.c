
#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include "system.h"
#include "Dice.h"

#define X1		LATAbits.LATA2
#define X2		LATAbits.LATA4
#define X3		LATAbits.LATA5
#define X4		LATAbits.LATA1
#define X5		LATAbits.LATA0

#define X1DIR	TRISAbits.TRISA2
#define X2DIR	TRISAbits.TRISA4
#define X3DIR	TRISAbits.TRISA5
#define X4DIR	TRISAbits.TRISA1
#define X5DIR	TRISAbits.TRISA0

#define IN		(1)
#define OUT		(0)

const TCHAR DiePatterns[] = {0x01, 0x06, 0x07, 0x66, 0x67, 0x7E};

static TCHAR phase = 0;

void LightDie1(TCHAR pips) {
	switch (pips & (1 << phase)) {
		case 1:
			// Turn on MC1 - Single pip
			X2DIR = OUT; X2 = 1;
			X1DIR = OUT; X1 = 0;
			break;
		case 2:
			// Turn on TR1
			X1DIR = OUT; X1 = 1;
			X2DIR = OUT; X2 = 0;
			break;
		case 4:
			// Turn on BL1
			X1DIR = OUT; X1 = 1;
			X3DIR = OUT; X3 = 0;
			break;	
		case 8:
			// Turn on ML1
			X1DIR = OUT; X1 = 1;
			X4DIR = OUT; X4 = 0;
			break;
		case 16:
			// Turn on MR1
			X1DIR = OUT; X1 = 1;
			X5DIR = OUT; X5 = 0;
			break;
		case 32:
			// Turn on TL1
			X2DIR = OUT; X2 = 1;
			X4DIR = OUT; X4 = 0;
			break;
		case 64:
			// Turn on BR1
			X2DIR = OUT; X2 = 1;
			X5DIR = OUT; X5 = 0;
			break;
	}	
}

void LightDie2(TCHAR pips) {
	switch (pips & (1 << (phase - 7))) {
		case 1:
			// Turn on MC2 - Single pip
			X2DIR = OUT; X2 = 1;
			X3DIR = OUT; X3 = 0;
			break;
		case 2:
			// Turn on TR2
			X3DIR = OUT; X3 = 1;
			X1DIR = OUT; X1 = 0;
			break;
		case 4:
			// Turn on BL2
			X3DIR = OUT; X3 = 1;
			X2DIR = OUT; X2 = 0;
			break;	
		case 8:
			// Turn on ML2
			X3DIR = OUT; X3 = 1;
			X4DIR = OUT; X4 = 0;
			break;
		case 16:
			// Turn on MR2
			X3DIR = OUT; X3 = 1;
			X5DIR = OUT; X5 = 0;
			break;
		case 32:
			// Turn on TL2
			X4DIR = OUT; X4 = 1;
			X1DIR = OUT; X1 = 0;
			break;
		case 64:
			// Turn on BR2
			X4DIR = OUT; X4 = 1;
			X2DIR = OUT; X2 = 0;
			break;
	}	
}

void Dice_Show (TCHAR dice1, TCHAR dice2) {
	for (phase = 0; phase < 14; phase++) {
		TRISA |= 0x37; // everything is an input to turn off LEDs
		if (phase < 7) LightDie1(DiePatterns[dice1]);
		else LightDie2(DiePatterns[dice2]);
		__delay_ms(1);
	}
}