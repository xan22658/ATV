/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */
  
#ifndef DTMF_H
#define	DTMF_H

//#include <common.h> // include processor files - each processor file is guarded.  

#define DTMF_D1  PORTBbits.RB0
#define DTMF_D2  PORTBbits.RB1
#define DTMF_D3  PORTBbits.RB2
#define DTMF_D4  PORTBbits.RB3

/* Configure the dtmf interface */
void dtmf_Configure(void);

/* Configure DTMF Interrupt*/
void dtmf_InitInterrupt(void);

#endif