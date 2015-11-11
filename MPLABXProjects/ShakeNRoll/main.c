/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */
#include "Dice.h"

TCHAR phase;
TCHAR die1, die2;

void main (void) {
	/* Configure the oscillator for the device */
	ConfigureOscillator();

	/* Initialize I/O and Peripherals for application */
	InitApp();

	phase = 0; die1 = 0; die2 = 5;
	while (1) {						
		Dice_Show(die1, die2);	// takes 14 mS
		phase++;
		if (phase == 40) {
			// change the dice
			phase = 0;
			die1++; die2++;
			if (die1 == 6) die1 = 0;
			if (die2 == 6) die2 = 0;
		}
	}

}

