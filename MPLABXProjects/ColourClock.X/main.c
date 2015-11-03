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

static unsigned char red, green, blue;

/*
 1057  0012  1FF1               	btfss	WriteRGB@g,7
  1058  0013  2821               	goto	l22
  1059  0014  0022               	movlb	2	; select bank2
  1060  0015  150C               	bsf	12,2	;volatile
  1061  0016  0000               	nop
  1062  0017  0000               	nop
  1063  0018  0000               	nop
  1064  0019  0000               	nop
  1065  001A  0000               	nop
  1066  001B  0000               	nop
  1067  001C  1003               	clrc
  1068  001D  0DF1               	rlf	WriteRGB@g,f
  1069  001E  0022               	movlb	2	; select bank2
  1070  001F  110C               	bcf	12,2	;volatile
  1071  0020  282C               	goto	l760
  1072  0021                     l22:	
  1073  0021  0022               	movlb	2	; select bank2
  1074  0022  150C               	bsf	12,2	;volatile
  1075  0023  0000               	nop
  1076  0024  0022               	movlb	2	; select bank2
  1077  0025  110C               	bcf	12,2	;volatile
  1078  0026  0000               	nop
  1079  0027  0000               	nop
  1080  0028  0000               	nop
  1081  0029  0000               	nop
  1082  002A  1003               	clrc
  1083  002B  0DF1               	rlf	WriteRGB@g,f
 */

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
	asm("BANKSEL _red");  // only need this once
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

	red = 0x00; green = 0x55, blue = 0x00;
	__delay_ms(10);					// oscillator stabilization
	while (1) {
		__delay_us(50);				// LCD reset
		WriteRGB(green, red, blue);	// seconds
		WriteRGB(red,   green, blue);
		WriteRGB(blue, red, green);	// minutes
		WriteRGB(green, red, blue);
		WriteRGB(red,   green, blue);	// hours
		WriteRGB(blue, red, green);
	}

}

