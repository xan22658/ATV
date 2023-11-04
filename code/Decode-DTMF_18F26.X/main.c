/*
 * File:   main.c
 * Author: romain.lepron
 *
 * Created on 04/11/2023
 */

#include "pic18f26k83.h"
#include "Configuration.h"
#include "timer0.h"
#include "common.h"
#include "Drv_Adc.h"
#include "dtmf.h"

#define LED_DTMF    PORTBbits.RB4
#define LED_DTMFOK  PORTBbits.RB5

void InitSysteme(void);
void LED_DTMF_LightOn(void);
void LED_DTMF_LightOff(void);
void LED_DTMFOK_LightOn(void);
void LED_DTMFOK_LightOff(void);

Uint8_t ui8Compteur = 0;
Uint8_t test = 0;
Uint32_t Temperature = 0;
Uint32_t test_temp = 0;

void main(void) {
    
InitSysteme(); 

    
Temperature = 3;
while (1) 
    {     
       if (ui8Compteur % 2 == 0)
          {  
         // LATBbits.LATB0 = 0 ; 
            // Drv_Adc_Read_Temp_Ext(); 
             
             test_temp = Drv_Adc_Read_Temp_Ext();
          }
          else
          {
          //LATBbits.LATB0 = 1 ; 
          }
//       if (Temperature > 22)
//            {
//                LATBbits.LATB1 = 0 ;
//            }
//            else
//            {
//                LATBbits.LATB1 = 1 ;
//            }  
// Boucle de mesure de la temperature : 
        
      // Drv_Adc_Read_Temp_Ext(); // Appel de la fonction de mesure de la température 
    } 
}

void InitSysteme(void)
{
     
TRISBbits.TRISB4 = 0; // Port LED en sortie
TRISBbits.TRISB5 = 0; // Port LED en sortie

void LED_DTMF_LightOn();
void LED_DTMFOK_LightOn();

TMR0_Initialize();      // Initialisation du Timer0
Drv_Adc_Configure();    // Initialisation ADC 
dtmf_Configure();     // Initialisation DTMF
dtmf_InitInterrupt();

void LED_DTMF_LightOff();
void LED_DTMFOK_LightOff();

    
}
  
void LED_DTMF_LightOn()
{
    LED_DTMF = 0;
}

void LED_DTMF_LightOff()
{
    LED_DTMF = 1;
}

void LED_DTMFOK_LightOn()
{
    LED_DTMFOK = 0;
}

void LED_DTMFOK_LightOff()
{
    LED_DTMFOK = 1;
}