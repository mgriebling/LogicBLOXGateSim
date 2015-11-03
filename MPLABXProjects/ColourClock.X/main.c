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

#define SO		LATAbits.LATA2
#define Nop()	NOP()

inline void BITOUT(unsigned char b) {
//    if (b & 0x80) {
//		SO = 1;
//        Nop();
//        Nop();
//        Nop();
//        Nop();
//        Nop();
//        Nop();
//        b <<= 1;
//        SO = 0;
//    } else {
//		SO = 1;
//		Nop();
//        SO = 0;
//        Nop();
//        Nop();
//        Nop();
//        Nop();
//        b <<= 1;
//    }
	asm("BANKSEL (PORTA)");
	asm("BSF	 RA2");			// set SO
	asm("BANKSEL _b");
	asm("BITFSC	 _b,7");
	asm("BRA	 _lab1");
	
}


/* i.e. uint16_t <variable_name>; */
inline void WriteRGB (unsigned char r, unsigned char g, unsigned char b) {
    BITOUT(g);
    BITOUT(g);
    BITOUT(g);
    BITOUT(g);
    BITOUT(g);
    BITOUT(g);
    BITOUT(g);
    BITOUT(g);
    BITOUT(r);
    BITOUT(r);
    BITOUT(r);
    BITOUT(r);
    BITOUT(r);
    BITOUT(r);
    BITOUT(r);
    BITOUT(r);
    BITOUT(b);
    BITOUT(b);
    BITOUT(b);
    BITOUT(b);
    BITOUT(b);
    BITOUT(b);
    BITOUT(b);
    BITOUT(b);
}


/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */

/******************************************************************************/

void main (void) {
	/* Configure the oscillator for the device */
	ConfigureOscillator();

	/* Initialize I/O and Peripherals for application */
	InitApp();


	while (1) {
		WriteRGB(0xFF, 0xFF, 0xFF);
	}

}

