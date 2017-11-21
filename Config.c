/*
 * File:   config.c
 * Author: TylerMatthews
 *
 * Created on November 7, 2017, 3:23 PM
 */

//Tells the PIC what the clock speed is (40MHz)

#include <xc.h>
#include "PinDef.h"
#include "Vars.h"
#include "Functions.h"

//Fosc = Fin * (M/N2*N1) = 48MHZ => 24Mips
//Fcy = 24MHz
void oscSetup(){   
    
    PLLFBDbits.PLLDIV = 0b11110; //M = 32
    CLKDIVbits.PLLPOST = 1; // N2 = 4
    CLKDIVbits.PLLPRE = 0; //N1 = 2

    // Clock switching to incorporate PLL
    __builtin_write_OSCCONH(0x03);  // Initiate Clock Switch to Primary
             // Oscillator with PLL (NOSC=0b011)
    __builtin_write_OSCCONL(0x01);  // Start clock switching
    while (OSCCONbits.COSC != 0b011); // Wait for Clock switch to occur
    // Wait for PLL to lock
    while(OSCCONbits.LOCK!=1);
            
    
}

void setup(){
    oscSetup();
    ADC_Init();
    T1_Setup();
    T5_Setup();
}
