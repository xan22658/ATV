#ifndef CONFIGURATION_H
#define	CONFIGURATION_H

#pragma config FEXTOSC = 0b010
#pragma config RSTOSC = 0b111

#pragma config FCMEN = OFF
#pragma config CSWEN = OFF
#pragma config PR1WAY = OFF
#pragma config CLKOUTEN = OFF

#pragma config BOREN = OFF
#pragma config LPBOREN = OFF 
#pragma config IVT1WAY = ON
#pragma config MVECEN = ON
#pragma config PWRTS = PWRT_64
#pragma config MCLRE = EXTMCLR

#pragma config XINST = OFF
#pragma config DEBUG = OFF
#pragma config STVREN =ON
#pragma config PPS1WAY =OFF
#pragma config ZCD = OFF
#pragma config BORV = VBOR_2P45

#pragma config WDTE = OFF
#pragma config WDTCCS = MFINTOSC
#pragma config WDTCPS = WDTCPS_5
#pragma config WDTCWS = WDTCWS_7

#pragma config BBSIZE = BBSIZE_512
#pragma config BBEN = OFF
#pragma config SAFEN = OFF
#pragma config WRTAPP = ON
#pragma config WRTB = OFF
#pragma config WRTC = ON
#pragma config WRTD = ON
#pragma config WRTSAF = OFF
#pragma config LVP = ON

#pragma config CP = ON
#endif	

