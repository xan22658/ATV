/*
 * File:   dtmf.c
 * Author: Romain
 *
 * Created on 4 novembre 2023, 11:44
 */

#include "pic18f26k83.h"
#include "dtmf.h"
#include "common.h"


void dtmf_Configure(void)
{
TRISBbits.TRISB0 = 1; // Port xx en entrée D1
TRISBbits.TRISB1 = 1; // Port xx en entrée D2
TRISBbits.TRISB2 = 1; // Port xx en entrée D3
TRISBbits.TRISB3 = 1; // Port xx en entrée D4

}

void dtmf_InitInterrupt(void)
{
    //creer l'interruption 
}