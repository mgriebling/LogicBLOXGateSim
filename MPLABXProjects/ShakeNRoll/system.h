/******************************************************************************/
/* System Level #define Macros                                                */
/******************************************************************************/

#include "mcc_generated_files/mcc.h"

/* Microcontroller MIPs (FCY) */
#define SYS_FREQ        _XTAL_FREQ
#define FCY             (SYS_FREQ/4)

#define ON  (TRUE)
#define OFF (FALSE)
#define TRUE  (1)
#define FALSE (0)
#define TCHAR unsigned char
#define LONGINT long
#define LONGCARD unsigned long
#define CARDINAL LONGCARD
#define BOOLEAN unsigned char

#define Nop()	NOP()

/******************************************************************************/
/* System Function Prototypes                                                 */
/******************************************************************************/

