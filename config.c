/*
 * File:   config.c
 * Author: TylerMatthews
 *
 * Created on November 7, 2017, 3:23 PM
 */


#include <xc.h>
#include <pindef.h>
void timerSetup(){
}


//(M2/N1*N1)
void oscSetup(){   
    OSCCONbits.COSC = 0b011; // External Crystal Oscillator 
    OSCCONbits.NOSC = 0b011;
    OSCCONbits.IOLOCK = 0;
    OSCCONbits.CLKLOCK = 1;
    CLKDIVbits.PLLPRE = 0; //N1 = 2
    CLKDIVbits.PLLPOST = 0; // N2 = 2
    PLLFBDbits.PLLDIV = 0x20; //M = 16
    
            
    
}

void setup(){
    oscSetup();
    timerSetup();
}
