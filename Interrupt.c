/*
 * File:   Interrupt.c
 * Author: Nick
 *
 * Created on November 10, 2017, 6:58 PM
 */


#include <xc.h>
#include "PinDef.h"
#include "Functions.h"
#include "Vars.h"

    /*
     *  Enable all used interrupts and set priority
     */
void Interrupt_Set(void){
    
    // CPU Priority Level
    SRbits.IPL = 000;
    CORCONbits.IPL3 = 0;
    
    
    // INTCON1 Register
    
    INTCON1bits.NSTDIS = 1;  // Nesting Disabled
    
    
    
    
}


// Initialize ADC Conversion complete interrupt
//void ADC_Int(void){
  //  IEC0bits.AD1IE = 1;
    // ID1IP = 0b111;
//}


// Initalize 

