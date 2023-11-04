/*
 * File:   Drv_Adc.c
 * Author: romain.lepron
 *
 * Created on 
 */

#include "pic18f26k83.h"
#include "Drv_Adc.h"
#include "common.h"

void Drv_Adc_Configure(void)
{
   
    ADCON0bits.ON = 0; // arret de l'adc 
    ADCON0bits.CONT = 0; // mode continue 
    ADCON0bits.FM = 1; // right jusify 
    ADPRELbits.ADPRE = 0xFF; //ADC PRECHARGE TIME CONTROL REGISTER
    ADPREHbits.ADPRE = 0b0011; //ADC PRECHARGE TIME CONTROL REGISTER
    ADACQLbits.ADACQ = 0xFF; // ADC ACQUISITION TIME CONTROL REGISTER
    ADACQHbits.ADACQ = 0b0111; //ADC ACQUISITION TIME CONTROL REGISTER
    ADCON1bits.PPOL = 0b1; // Précharge polarity 
    ADCON1bits.DSEN = 0; // Double sample enable bit 0=1 seule conversion
    ADCON0bits.CS = 0; // clock selection 0=Fosc
    ADCLKbits.CS = 0b111111;
    ADCON2bits.PSIS = 0b0; // ADC Previous Sample Input Select bits
    ADCON2bits.MD = 0b000; //ADC Operating Mode Selection bits 0= basic mode
    ADCON3bits.CALC = 0b000; //ADC Error Calculation Mode Select bits
    ADCON3bits.TMD = 0b000; //Threshold Interrupt Mode Select bits
    ADRPT = 0x00; 
    ADCNT = 0x00; 
    ADFLTRH = 0x00; 
    ADSTPTH = 0x00;
    ADSTPTL = 0x00;
    ADLTHH = 0x00;
    ADLTHL = 0x00;
    ADUTHL = 0x00;
    ADUTHH = 0x00;
    ADACT = 0b00000;
    ADCPbits.CPON = 0b0; //ADC CHARGE PUMP CONTROL 0= Off 
    ADREFbits.NREF = 0b0; //ADC REFERENCE SELECTION
    ADREFbits.PREF = 0b00; //ADC REFERENCE SELECTION
    ADCAP = 0x00;
    ADCON0bits.ON = 1; // mise en route de l'adc 
}

Uint32_t Drv_Adc_Read_Temp_Ext(void)
{
    Uint8_t l_counter = 0;
    Uint8_t l_adc_res_h = 0;
    Uint8_t l_adc_res_l = 0;
    Uint32_t l_temp_h = 0;
    Uint32_t l_temp_l = 0;
    Uint32_t l_result = 0;

   
//    TRISAbits.TRISA0 = 1; // Set A0 input 
//    ANSELAbits.ANSELA0 = 1; // Set A0 analog mode 
//    ADPCH = 0b000000; // selection du port d'entrée 
//    ADCON0bits.GO = 1; // demmarage de la conversion de l'adc

    TRISAbits.TRISA1 = 1; // Set A0 input 
    ANSELAbits.ANSELA1 = 1; // Set A0 analog mode 
    ADPCH = 0b000001; // selection du port d'entrée 
    ADCON0bits.GO = 1; // demmarage de la conversion de l'adc
    
    /*Read multiple times to make sure the correct value is read*/
    for (l_counter = 0; l_counter < 80; l_counter++)
    {
        l_adc_res_h = ADRESH;
        l_adc_res_l = ADRESL;
        l_temp_h = ((Uint32_t) l_adc_res_h) << 8;
        l_temp_l = ((Uint32_t) l_adc_res_l);
        l_result = l_temp_h + l_temp_l;
    }

    /* If the MCU indicates that the measure succeeded, compute the final value,
     * Otherwise that's an internal error, and return 0mV */
    if (ADCON0bits.GO == 0) { // arret de la conversion de l'adc  
        //l_result = l_result * 5000; // Valeur de tension de l'alimentation du PIC 
        //l_result = l_result / 4096;
        l_result = l_result * 1.22;
       l_result = l_result / 10.00;
        
       // l_result = l_result * 100;  // On multiplie par 100, car dans 5 volts (= 5000mV) il y a 100 fois 10mV (= 1°C).
       // l_result = l_result * (5.0 / 4096.0 * 100.0);
    } else {
        l_result = 0;
    }
    
    return l_result;
    //return l_temperature;
}

