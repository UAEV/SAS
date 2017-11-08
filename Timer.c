/*
 * File:   Timer.c
 * Author: Nick
 *
 * Created on November 7, 2017, 6:13 PM
 */


#include "xc.h"

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
