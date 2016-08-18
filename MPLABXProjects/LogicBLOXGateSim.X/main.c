/*
 * File:   main.c
 * Author: michaelgriebling
 *
 * Created on June 7, 2016, 8:09 AM
 */


// PIC32MX230F256B Configuration Bit Settings

// 'C' source line config statements

#define SYS_FREQ	96000000ul

#include <xc.h>
#include <stdlib.h>

// DEVCFG3
// USERID = No Setting
#pragma config PMDL1WAY = ON            // Peripheral Module Disable Configuration (Allow only one reconfiguration)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow only one reconfiguration)
#pragma config FUSBIDIO = ON            // USB USID Selection (Controlled by the USB Module)
#pragma config FVBUSONIO = ON           // USB VBUS ON Selection (Controlled by USB Module)

// DEVCFG2
#pragma config FPLLIDIV = DIV_1         // PLL Input Divider (1x Divider)
#pragma config FPLLMUL = MUL_24         // PLL Multiplier (24x Multiplier)
#pragma config UPLLIDIV = DIV_1         // USB PLL Input Divider (2x Divider)
#pragma config UPLLEN = OFF              // USB PLL Enable (Enabled)
#pragma config FPLLODIV = DIV_2         // System PLL Output Clock Divider (PLL Divide by 2)

// DEVCFG1
#pragma config FNOSC = PRIPLL           // Oscillator Selection Bits (Primary Osc w/PLL (XT+,HS+,EC+PLL))
#pragma config FSOSCEN = ON             // Secondary Oscillator Enable (Enabled)
#pragma config IESO = ON                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = XT             // Primary Oscillator Configuration (XT osc mode)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FPBDIV = DIV_8           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/8)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Clock Switch Disable, FSCM Disabled)
#pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable (Watchdog Timer is in Non-Window Mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Disabled (SWDTEN Bit Controls))
#pragma config FWDTWINSZ = WINSZ_25     // Watchdog Timer Window Size (Window Size is 25%)

// DEVCFG0
#pragma config JTAGEN = OFF             // JTAG Enable (JTAG Disabled)
#pragma config ICESEL = ICS_PGx3        // ICE/ICD Comm Channel Select (Communicate on PGEC3/PGED3)
#pragma config PWP = OFF                // Program Flash Write Protect (Disable)
#pragma config BWP = OFF                // Boot Flash Write Protect bit (Protection Disabled)
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

#define SO		LATBbits.LATB9
#define SETHI	TRISBbits.TRISB9 = 1
#define SETLO	TRISBbits.TRISB9 = 0

#define BITOUT(b)\
	if (b & 0x80) {\
		SETHI;\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
		SETLO;\
		Nop();\
        Nop();\
        Nop();\
        Nop();\
		Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        b <<= 1;\
	} else {\
		SETHI;\
		Nop();\
        Nop();\
        Nop();\
        Nop();\
		Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
		SETLO;\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
        Nop();\
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


/* i.e. uint16_t <variable_name>; */
inline void WriteRGB (unsigned char r, unsigned char g, unsigned char b) {
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

void Reset () {
	int x = 1800000;
	SETLO;				// RGB SO output
	while (x > 0) {
		Nop(); x--;
	}	
}

void main(void) {
	// init ports
	ANSELB = 0;			// All digital I/O
	SO = 0;				// Set output low

	char cnt;
	for (;;) {
		Reset();
		for (cnt = 0; cnt < 11; cnt++) {
			char red, green, blue;
			red = rand() % 256;
			green = rand() % 256;
			blue = rand() % 256;
			WriteRGB(red, green, blue);
		}
	}
	return;
}
