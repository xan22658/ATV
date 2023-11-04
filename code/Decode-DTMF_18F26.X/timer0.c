/*
 * File:   timer0.c
 * Author: romain.lepron
 *
 * Created on 19 janvier 2022, 09:03
 */


#include "pic18f26k83.h"
#include "timer0.h"
#include "common.h"

extern Uint8_t ui8Compteur; // Variable Compteur pour Timer0 

void TMR0_Initialize(void) // Configuration du Timer0 
{
    /**********************TIMER 0 INIT*******************************************/
	INTCON0bits.GIEH = 0;
    INTCON0bits.GIEL = 0;
    INTCON0bits.IPEN = 0;
    IVTBASEU = 0x00;
    IVTBASEH = 0x00;
    IVTBASEL = 0x08;
    INTCON0bits.GIEH = 1;
    INTCON0bits.GIEL = 1;
    INTCON0bits.IPEN = 1;

    /*Configure the timer to call App_Private_Cmd_Execute_Periodic_Task each 20ms*/
    T0CON0bits.EN = 0;
    T0CON0bits.MD16 = 1;
    TMR0L = 0xF6; // 49911
    TMR0H = 0xC2; //

    T0CON0bits.OUTPS = 0b0000; // Ne pas utiliser ! 
    T0CON1bits.CS = 0b010;
    T0CON1bits.ASYNC = 1;
    T0CON1bits.CKPS = 0b0111; //1:128 Prescaler 
    PIR3bits.TMR0IF = 0;
    IPR3bits.TMR0IP = 0;
    PIE3bits.TMR0IE = 1;
    T0CON0bits.EN = 1;
    
}
 
void __interrupt(irq(IRQ_TMR0)) App_Private_Cmd_Execute_Periodic_Task (void)
{
    if ( PIR3bits.TMR0IF  == 1)
    {
    ui8Compteur++;
    /* Clear the timer interruption flag */
    PIR3bits.TMR0IF = 0;   
    }
    
}

//Calcul du timer : 
// Ttimer = Thorloge×prescaler×(autoreload+1)