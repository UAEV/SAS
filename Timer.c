/*
 * File:   Timer.c
 * Author: Nick
 *
 * Created on November 7, 2017, 6:13 PM
 */


#include "xc.h"
#include "ADC.h"

int main(void) {
    return 0;
}

void T1_Setup(void){
    T1CONbits.TON = 1;
    T1CONbits.TSIDL = 0;
    T1CONbits.TCS = 1;
    //T1CONbits.TSYNC = 1;
    T1CONbits.TCKPS = 0b11; // Prescaler set 1:256
    
}

void T5_Setup(void){
    T5CONbits.TON = 1;
    T5CONbits.TSIDL = 0;
    T5CONbits.TCS = 1;
    T1CONbits.TCKPS = 0b11; // Prescaler set 1:256
}


/*
 * 
 *  Not sure if we should have and branch where we develop interrupts 
 * and a branch where we develop timers 
 * 
 */

void __attribute__((interrupt, auto_psv)) T5Interrupt(void){
    
    IFS1bits.T5IF = 0;
    readyToSample = 1;
    
}