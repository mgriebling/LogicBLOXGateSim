/**
  @Generated Pin Manager Header File

  @Company:
	Microchip Technology Inc.

  @File Name:
	pin_manager.h

  @Summary:
	This is the Pin Manager file generated using MPLAB� Code Configurator

  @Description:
	This header file provides implementations for pin APIs for all pins selected in the GUI.
	Generation Information :
		Product Revision  :  MPLAB� Code Configurator - v2.25.2
		Device            :  PIC12F1572
		Version           :  1.01
	The generated drivers are tested against the following:
		Compiler          :  XC8 v1.34
		MPLAB             :  MPLAB X v2.35 or v3.00
 */

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set X5 aliases
#define X5_TRIS               TRISA0
#define X5_LAT                LATA0
#define X5_PORT               RA0
#define X5_WPU                WPUA0
#define X5_ANS                ANSA0
#define X5_SetHigh()    do { LATA0 = 1; } while(0)
#define X5_SetLow()   do { LATA0 = 0; } while(0)
#define X5_Toggle()   do { LATA0 = ~LATA0; } while(0)
#define X5_GetValue()         RA0
#define X5_SetDigitalInput()    do { TRISA0 = 1; } while(0)
#define X5_SetDigitalOutput()   do { TRISA0 = 0; } while(0)

#define X5_SetPullup()    do { WPUA0 = 1; } while(0)
#define X5_ResetPullup()   do { WPUA0 = 0; } while(0)
#define X5_SetAnalogMode()   do { ANSA0 = 1; } while(0)
#define X5_SetDigitalMode()   do { ANSA0 = 0; } while(0)
// get/set X4 aliases
#define X4_TRIS               TRISA1
#define X4_LAT                LATA1
#define X4_PORT               RA1
#define X4_WPU                WPUA1
#define X4_ANS                ANSA1
#define X4_SetHigh()    do { LATA1 = 1; } while(0)
#define X4_SetLow()   do { LATA1 = 0; } while(0)
#define X4_Toggle()   do { LATA1 = ~LATA1; } while(0)
#define X4_GetValue()         RA1
#define X4_SetDigitalInput()    do { TRISA1 = 1; } while(0)
#define X4_SetDigitalOutput()   do { TRISA1 = 0; } while(0)

#define X4_SetPullup()    do { WPUA1 = 1; } while(0)
#define X4_ResetPullup()   do { WPUA1 = 0; } while(0)
#define X4_SetAnalogMode()   do { ANSA1 = 1; } while(0)
#define X4_SetDigitalMode()   do { ANSA1 = 0; } while(0)
// get/set X1 aliases
#define X1_TRIS               TRISA2
#define X1_LAT                LATA2
#define X1_PORT               RA2
#define X1_WPU                WPUA2
#define X1_ANS                ANSA2
#define X1_SetHigh()    do { LATA2 = 1; } while(0)
#define X1_SetLow()   do { LATA2 = 0; } while(0)
#define X1_Toggle()   do { LATA2 = ~LATA2; } while(0)
#define X1_GetValue()         RA2
#define X1_SetDigitalInput()    do { TRISA2 = 1; } while(0)
#define X1_SetDigitalOutput()   do { TRISA2 = 0; } while(0)

#define X1_SetPullup()    do { WPUA2 = 1; } while(0)
#define X1_ResetPullup()   do { WPUA2 = 0; } while(0)
#define X1_SetAnalogMode()   do { ANSA2 = 1; } while(0)
#define X1_SetDigitalMode()   do { ANSA2 = 0; } while(0)
// get/set Shake aliases
#define Shake_TRIS               TRISA3
#define Shake_PORT               RA3
#define Shake_WPU                WPUA3
#define Shake_GetValue()         RA3
#define Shake_SetDigitalInput()    do { TRISA3 = 1; } while(0)
#define Shake_SetDigitalOutput()   do { TRISA3 = 0; } while(0)

#define Shake_SetPullup()    do { WPUA3 = 1; } while(0)
#define Shake_ResetPullup()   do { WPUA3 = 0; } while(0)
// get/set X2 aliases
#define X2_TRIS               TRISA4
#define X2_LAT                LATA4
#define X2_PORT               RA4
#define X2_WPU                WPUA4
#define X2_ANS                ANSA4
#define X2_SetHigh()    do { LATA4 = 1; } while(0)
#define X2_SetLow()   do { LATA4 = 0; } while(0)
#define X2_Toggle()   do { LATA4 = ~LATA4; } while(0)
#define X2_GetValue()         RA4
#define X2_SetDigitalInput()    do { TRISA4 = 1; } while(0)
#define X2_SetDigitalOutput()   do { TRISA4 = 0; } while(0)

#define X2_SetPullup()    do { WPUA4 = 1; } while(0)
#define X2_ResetPullup()   do { WPUA4 = 0; } while(0)
#define X2_SetAnalogMode()   do { ANSA4 = 1; } while(0)
#define X2_SetDigitalMode()   do { ANSA4 = 0; } while(0)
// get/set X3 aliases
#define X3_TRIS               TRISA5
#define X3_LAT                LATA5
#define X3_PORT               RA5
#define X3_WPU                WPUA5
#define X3_SetHigh()    do { LATA5 = 1; } while(0)
#define X3_SetLow()   do { LATA5 = 0; } while(0)
#define X3_Toggle()   do { LATA5 = ~LATA5; } while(0)
#define X3_GetValue()         RA5
#define X3_SetDigitalInput()    do { TRISA5 = 1; } while(0)
#define X3_SetDigitalOutput()   do { TRISA5 = 0; } while(0)

#define X3_SetPullup()    do { WPUA5 = 1; } while(0)
#define X3_ResetPullup()   do { WPUA5 = 0; } while(0)

/**
 * @Param
	none
 * @Returns
	none
 * @Description
	GPIO and peripheral I/O initialization
 * @Example
	PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize(void);

/**
 * @Param
	none
 * @Returns
	none
 * @Description
	Interrupt on Change Handling routine
 * @Example
	PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);

#endif // PIN_MANAGER_H
/**
 End of File
 */