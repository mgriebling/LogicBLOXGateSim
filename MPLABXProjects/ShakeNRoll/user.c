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
#include "system.h"
#include "mcc_generated_files/mcc.h"

#include "user.h"

CARDINAL roll;

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

void InitApp(void)
{
//    /* Setup analog functionality and port direction */
//	TRISA = 0x3F;				// Initially all inputs	
//	ANSELA = 0;					// All digital I/O
//	SLRCONA = 0;				// Turn off slew rate limits for max. current
//	
//	/* Enable pull-up on Shake sensor */
//	WPUA = 0;					// Disable all pull-ups
//	WPUAbits.WPUA3 = 1;			// Enable internal pull-up on A3
//	IOCANbits.IOCAN3 = 1;
//	IOCAPbits.IOCAP3 = 1;
//	IOCAFbits.IOCAF3 = 0;		// Clear interrupt flags
//	OPTION_REGbits.nWPUEN = 0;	// Enable pull-ups	

	SYSTEM_Initialize();
	
	roll = 0;
	
    /* Enable interrupts */
	INTCONbits.PEIE = 1;
	INTCONbits.GIE = 1;
}

