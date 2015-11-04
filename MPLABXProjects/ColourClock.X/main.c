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
#include "Clock.h"

#define SO		LATAbits.LATA2

#define BITOUT(b)\
	asm("bsf	12,2");\
	if (b & 0x80) {\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        b <<= 1;\
		asm("bcf	12,2");\
	} else {\
		asm("bcf	12,2");\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        b <<= 1;\
	}

#define BITOUT2(b) \
    if (b & 0x80) {\
		SO = 1;\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        b <<= 1;\
        SO = 0;\
    } else {\
		SO = 1;\
		Nop();\
        SO = 0;\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        b <<= 1;\
    }


/* i.e. uint16_t <variable_name>; */
inline void WriteRGB (unsigned char r, unsigned char g, unsigned char b) {
	asm("BANKSEL _r");  // only need this once
    BITOUT(r);
    BITOUT(r);
    BITOUT(r);
    BITOUT(r);
    BITOUT(r);
    BITOUT(r);
    BITOUT(r);
    BITOUT(r);
    BITOUT(g);
    BITOUT(g);
    BITOUT(g);
    BITOUT(g);
    BITOUT(g);
    BITOUT(g);
    BITOUT(g);
    BITOUT(g);
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
enum {     Black=0, Brown, Red, Orange, Yellow, Green, Blue, Violet, Gray,  White} hours10, hours1, mins10, mins1, secs10, secs1;
TCHAR r[] = {0x00u, 0x45u, 0xFFu, 0xFFu,  0xFFu, 0x00u, 0x00u, 0x94u, 0x80u, 0xFFu};
TCHAR g[] = {0x00u, 0x0Au, 0x00u, 0xA5u,  0xFFu, 0xFFu, 0x00u, 0x00u, 0x80u, 0xFFu};
TCHAR b[] = {0x00u, 0x0Au, 0x00u, 0x00u,  0x00u, 0x00u, 0xFFu, 0xD3u, 0x80u, 0xFFu};

/******************************************************************************/
/* Main Program                                                               */

/******************************************************************************/

void DecodeTime(void) {
//	if (secs1 < 9) {
//		secs1++;
//	} else if (secs10 < 5) {
//		secs10++; secs1 = 0;
//	} else if (mins1 < 9) {
//		mins1++; secs1 = 0; secs10 = 0;
//	} else if (mins10 < 5) {
//		mins10++; secs1 = 0; secs10 = 0; mins1 = 0;
//	} else if (hours < 24) {
//		secs1 = 0; secs10 = 0; mins1 = 0; mins10 = 0;
//		hours++; hours1 = hours % 10; hours10 = hours / 10;
//	} else {
//		secs1 = 0; secs10 = 0; mins1 = 0; mins10 = 0;
//		hours = 0; hours1 = 0; hours10 = 0;
//	}
	secs1 = seconds & 0x0F; secs10 = seconds >> 4;
	mins1 = minutes & 0x0F; mins10 = minutes >> 4;
	hours1 = hours & 0x0F; hours10 = hours >> 4;
}

void main (void) {
	/* Configure the oscillator for the device */
	ConfigureOscillator();

	/* Initialize I/O and Peripherals for application */
	InitApp();
	
	secs1 = Black; secs10 = Black; hours1 = Black; hours10 = Black; mins1 = Black; mins10 = Black;

	while (1) {
		__delay_us(50);									// LCD reset
		WriteRGB(r[secs1],  g[secs1],  b[secs1]);		// seconds
		WriteRGB(r[secs10], g[secs10], b[secs10]);
		WriteRGB(r[mins1],  g[mins1],  b[mins1]);		// minutes
		WriteRGB(r[mins10], g[mins10], b[mins10]);
		WriteRGB(r[hours1], g[hours1], b[hours1]);		// hours
		WriteRGB(r[hours10], g[hours10], b[hours10]);
		
		__delay_ms(250); __delay_ms(250);
		__delay_ms(250); __delay_ms(250);
		Clock_ReadTime();
		DecodeTime();
	}

}

