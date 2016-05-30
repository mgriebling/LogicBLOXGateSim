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

#define ROLL_TIME	(1000)	// mS
#define HOLD_TIME	(5000)
#define CYCLE_TIME	(14)
#define DIE_COUNT	(6)

TCHAR die1, die2;
TCHAR i;
CARDINAL time;

void main (void) {
	/* Initialize I/O and Peripherals for application */
	InitApp();

	die1 = 1; die2 = 6;
	while (1) {		
		// Roll the dice until it stops shaking
		time = 0;
		do {
			roll = 0;
			for (i = 1; i < (DIE_COUNT+1); i++) {
				Dice_Show(i, i); // takes 14 mS
			}
			if (roll != 0) {
				die1 = (roll % DIE_COUNT) + 1; 
				die2 = ((roll >> 4) % DIE_COUNT) + 1;
				time = ROLL_TIME / (CYCLE_TIME * DIE_COUNT);	// keep rolling for ROLL_TIME
			}
			if (time > 0) time--;
		} while (roll != 0 || time != 0);
		
		// slow down roll to show final dice value
		i = DIE_COUNT;
		for (time=0; time<(ROLL_TIME/CYCLE_TIME); time++) {		
			Dice_Show(die1, die2);	// takes 14 mS
			if (i == 0) {
				if (die1 == 6) die1 = 1; else die1++;
				if (die2 == 6) die2 = 1; else die2++;
				i = time/DIE_COUNT;
			}
			i--;
		}
		
		// show dice for about HOLD_TIME
		for (time=0; time<(HOLD_TIME/CYCLE_TIME); time++) {
			Dice_Show(die1, die2);	// takes 14 mS
		}
		
		// fade out the dice
		Dice_Dim (die1, die2);
		
        //*************************************************************************************
        SLEEP(); // processor goes into sleep mode and clears watchdog
        //*************************************************************************************
		
	}

}

