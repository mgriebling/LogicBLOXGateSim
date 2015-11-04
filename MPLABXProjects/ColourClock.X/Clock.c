
#include "Clock.h"
#include "I2C.h"

#define CONTROLREG	(0x07)
#define RTCSEC		(0x00)
#define RTCMIN		(0x01)
#define RTCHOUR		(0x02)

#define RTC_DEVICE	(0xDE)

TCHAR seconds, minutes, hours;

void Clock_ReadTime(void) {
	TCHAR buf[4];
	I2C_GetBuf(RTCSEC, buf, 3);		// Read the hours, minutes, seconds
	seconds = buf[0] & 0x7F;			// Ignore oscillator enable bit
	minutes = buf[1];
	hours  = buf[2];
}

void Clock_BEGIN(void) {
	// Initialize the clock I2C bus pins via I2C_BEGIN
	I2C_BEGIN();
	
	// Initialize the clock chip
	I2C_SetDevice(RTC_DEVICE);
	BOOLEAN ok = I2C_Device_Present();
	I2C_Send(CONTROLREG, 0b01000000);	// 1Hz output
	I2C_Send(RTCMIN, 0x00);
	I2C_Send(RTCHOUR, 0x00);
	I2C_Send(RTCSEC, 0b10000000);		// Enable oscillator & clear seconds
}
