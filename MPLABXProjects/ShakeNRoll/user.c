/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    /* Setup analog functionality and port direction */
	TRISA = 0x3F;				// Initially all inputs	
	ANSELA = 0;					// All digital I/O
	
	/* Enable pull-up on Shake sensor */
	WPUA = 0;					// Disable all pull-ups
	WPUAbits.WPUA3 = 1;			// Enable internal pull-up on A3
	IOCANbits.IOCAN3 = 1;
	OPTION_REGbits.nWPUEN = 0;	// Enable pull-ups	
	
    /* Enable interrupts */
}

