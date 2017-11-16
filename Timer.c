/*
 * File:   Timer.c
 * Author: Nick
 *
 * Created on November 7, 2017, 6:13 PM
 */


#include <xc.h>
#include "PinDef.h"
#include "Functions.h"
#include "Vars.h"


void T1_Setup(void){
    T1CONbits.TON = 1;
    T1CONbits.TSIDL = 0;
    T1CONbits.TCS = 1;
    //T1CONbits.TSYNC = 1;
    T1CONbits.TCKPS = 0b11; // Prescaler set 1:256
    
}

void T2_Setup(void){
    T2CONbits.TON = 1;
    T2CONbits.TSIDL = 0;
    T2CONbits.TCS = 0;
    T2CONbits.TCKPS = 0b11; // Prescaler set 1:256
    TMR2 = 0x0000;
    
    //Chip
    PR2 = 0x1234;  // Have to double check with rules and schematic
    

}


void T3_Setup(void){
    T3CONbits.TON = 1;
    T3CONbits.TSIDL = 0;
    T3CONbits.TCS = 0;
    T3CONbits.TCKPS = 0b11; // Prescaler set 1:256
    TMR3 = 0x0000;
    
    //Chip
    PR3 = 0x1234;  // Have to double check with rules and schematic
    

}

void T5_Setup(void){
    T5CONbits.TON = 1;
    T5CONbits.TSIDL = 0;
    T5CONbits.TCS = 0;
    T5CONbits.TCKPS = 0b11; // Prescaler set 1:256
    TMR5 = 0x0000;
    
    //Chip
    PR5 = 0x1234;  // Have to double check with rules and schematic
    

}


/*
 * 
 *  Not sure if we should have and branch where we develop interrupts 
 * and a branch where we develop timers 
 * 
 */

void __attribute__((interrupt, auto_psv)) T2Interrupt(void){
    
    IFS0bits.T2IF = 0;
    LED_Port = !LED_Port;         // Amber indication turns on and off status LED
    
}

void __attribute__((interrupt, auto_psv)) T3Interrupt(void){
    plausCheck = 1;
    TMR5 = 0;
    IFS0bits.T3IF = 0; //Clear interrupt flag
}

void __attribute__((interrupt, auto_psv)) T5Interrupt(void){
    IFS1bits.T5IF = 0; //Clear interrupt flag
}