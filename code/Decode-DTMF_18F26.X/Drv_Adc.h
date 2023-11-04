#ifndef DRV_ADC_H
#define	DRV_ADC_H

#include "common.h"

/* Configure the ADC interface */
void Drv_Adc_Configure(void);

/* Measure the voltage in millivolts */
Uint32_t Drv_Adc_Read_Temp_Ext(void);

#endif

