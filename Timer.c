/*
 * File:   Timer.c
 * Author: Nick
 *
 * Created on November 7, 2017, 6:13 PM
 */


#include <xc.h>
#include "PinDef.h"

int amberInd = 0;
int plausCheck = 0;
int plausCount = 0;

//Timer set for interrupt every 20ms
//Time = Fcy / (PR1 * TCKPS) = 24,000,000 / (256 * 1875) = 20 ms

/*
 * 
 * Not sure if we should have and branch where we develop interrupts 
 * and a branch where we develop timers 
 * 
 */

void __attribute__((interrupt, auto_psv)) _T1Interrupt(void){ 
    IFS0bits.T2IF = 0;     // Clear Interrupt Flag
    LED_Port = !LED_Port;  // Amber indication turns on and off status LED   
}

void __attribute__((interrupt, auto_psv)) _T2Interrupt(void){
    
    IFS0bits.T2IF = 0;
    LED_Port = !LED_Port;         // Amber indication turns on and off status LED 
}

void __attribute__((interrupt, auto_psv)) _T3Interrupt(void){
    plausCheck = 1;
    TMR3 = 0;
    IFS0bits.T3IF = 0; //Clear interrupt flag
}

void __attribute__((interrupt, auto_psv)) _T5Interrupt(void){
    IFS1bits.T5IF = 0; //Clear interrupt flag
    TMR5 = 0; //Probably irrelevant
}