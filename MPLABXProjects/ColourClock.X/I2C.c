/* Copyright (c) 2005 Solinst Canada Ltd */

#include <xc.h>         /* XC8 General Include File */
#include "I2C.h"

/* Software I2C implementation for use with microcomputers without any
   I2C hardware. */

#define SCL		PORTAbits.RA4			/* Clock  */
#define SCLDIR	TRISAbits.TRISA4
#define SCLIN	SCLDIR = 1
#define SCLOUT	SCLDIR = 0
#define SDA		PORTAbits.RA5			/* Data  */
#define SDADIR  TRISAbits.TRISA5
#define SDAIN	SDADIR = 1
#define SDAOUT	SDADIR = 0

TCHAR I2C_device;

static BOOLEAN Ack(void)
{ 
   BOOLEAN ack;
	
   SCLIN;				/* set SCL as an input so SCL goes high */
   
   /* assume SDA is input */
   ack = (SDA == 0);	/* sample SDA acknowledge */
   Nop();				/* delay clock */
   SCLOUT;				/* set SCL to an output so SCL goes low */
   return ack;
} /* end Ack() */


static void SendByte(TCHAR b)
{
   TCHAR cnt = 8;
	
   while (cnt--) {  
      if (b&0x80) SDAIN; 	/* set SDA as input -> goes high */
      else SDAOUT;			/* set SDA as output -> goes low */
      SCLIN;				/* set SCL as input -> goes high */
      b <<= 1; 		 	 	/* shift left 1 bit (part of delay) */			 
      SCLOUT;				/* set SCL as output -> goes low */    
   } /* end while */
   Nop();					/* delay for data hold */
   SDAIN;					/* leave SDA high for acknowledge */
} /* end SendByte() */


static BOOLEAN SendByteAck(TCHAR b)
{
   SendByte(b);
   return Ack();
} /* end SendByteAck() */


static TCHAR ReceiveByte(void)
{
   TCHAR cnt = 8;
   TCHAR lb = 0;
	
   while (cnt--) {
      lb<<=1;			/* shift left 1 bit position */   	
      SCLIN;			/* set SCL as input -> goes high */   	  
      if (SDA) lb|=1;	/* set LSB of byte */
      SCLOUT;			/* set SCL as output -> goes low */    
   } /* end while */  
   return lb;	
} /* end ReceiveByte() */


static TCHAR ReceiveByteAck(void)
{
   TCHAR lb = ReceiveByte();
   SDAOUT;		 /* leave SDA low for acknowledge */    
   Ack();
   SDAIN;		 /* set SDA high again */   
   return lb;
} /* end ReceiveByteAck() */


static void DoStart(void)
{
	/* do start bit */
	SDAIN; SCLIN;		/* set SCL, SDA as inputs -> go high */	
	SDAOUT;				/* set SDA as output -> goes low */ 
	SCLOUT;				/* set SCL as output -> goes low */ 
} /* end DoStart() */


extern void I2C_Power(BOOLEAN TurnOn, BOOLEAN Count)
{
   /* turn on/off memory power switch */
//   if (TurnOn) {
//   	sbit(MPOWER, P6OUT);	/* Power on */
//   	Timers_Delay(1);	/* Stabilize power */
//   } else {
//   	cbit(MPOWER, P6OUT);	/* Power off */
//   } 	
}

static void Start(TCHAR b, LONGINT adr)
{
   I2C_Power(TRUE, FALSE);	/* Power on memories */
//   di();			/* Disable interrupts */
   DoStart(); 

   /* start sending the data */
   SendByteAck(b);
   SendByteAck((TCHAR)(adr>>8));	/* output remainder of address */
   SendByteAck((TCHAR)(adr));  
} /* end Start() */


static void Stop(void)
{
   /* do stop bit */
   SDAOUT;		/* set SDA as output -> goes low */
   SCLIN;       /* set SCL as input -> goes high */ 	 
   SDAIN;       /* set SDA as input -> goes high */
//   ei();			/* Enable interrupts */   
} /* end Stop() */	

static void I2C_Init(void)
{
   /* set up registers for I2C communication */
   SDAIN; SCLIN;			/* set SDA and SCL as inputs */
   SDA = 0; SCL = 0;		/* set SDA/SCL low, Power off */
   I2C_Power(FALSE, FALSE);	/* initially turn off I2C power */ 
   I2C_device = 0xDEu;		/* default is the RTC chip */  	
}
	

extern void I2C_GetBuf(LONGINT adr, TCHAR buf[], CARDINAL size)
{
   CARDINAL ind;
   
   Start(I2C_device, adr);	/* output start bit and device address */
   
   /* do start bit again */
   DoStart();     
   SendByteAck(I2C_device+1);
   for (ind=0; ind<size-1; ind++) {
      buf[ind] = ReceiveByteAck(); /* receive data buffer */
   } /* end for */
   buf[size-1] = ReceiveByte();
   Stop();
} /* end GetBuf() */


extern TCHAR I2C_Get(LONGINT adr)
{
   TCHAR ch;
	
   Start(I2C_device, adr);	/* output start bit and device address */
   
   /* do start bit */
   DoStart();     
   SendByteAck(I2C_device+1);	/* send device address -- read mode */
   ch = ReceiveByte();		/* receive byte */
   Stop();			/* output stop bit */
   return ch;
} /* end Get() */


extern BOOLEAN I2C_GetAck(void)
{
   TCHAR ch;
   BOOLEAN ack;

   /* do start bit */
   DoStart();   
   ack = SendByteAck(I2C_device+1); /* send device address -- read mode */
   ch = ReceiveByte();				/* receive current address */
   Stop();							/* output stop bit */
   return ack;
} /* end GetAck() */


extern void I2C_SendBuf(LONGINT adr, TCHAR buf[], CARDINAL size)
{
   CARDINAL ind;

   Start(I2C_device, adr);	/* output start bit and device address */
   for (ind=0; ind<size-1; ind++) {
      SendByteAck(buf[ind]); 	/* output data buffer */
   } /* end for */
   SendByteAck(buf[size-1]);
   Stop();
} /* end SendBuf() */


extern BOOLEAN I2C_Device_Present(void)
{
    // Check for device twice before giving up
    if (I2C_GetAck()) return TRUE;
    return (I2C_GetAck());         
}


extern void I2C_Send(LONGINT adr, TCHAR byte)
{
   Start(I2C_device, adr);	/* output start bit and device address */
   SendByteAck(byte); 		/* output data */
   Stop();			/* output stop bit */
} /* end Send() */

extern void I2C_BEGIN(void)
{  
   I2C_Init();
}

