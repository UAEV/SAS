/*
 * File:   DMA.c
 * Author: Nick
 *
 * Created on November 10, 2017, 5:19 PM
 */


#include "xc.h"

void DMA_Setup(void){
    
    // DMA1CON Register
    DMA1CONbits.CHEN = 1;
    DMA1CONbits.SIZE = 0;
    DMA1CONbits.DIR = 0;
    DMA1CONbits.NULLW = 0;
    
    // DMA1REQ Register
    DMA1REQbits.FORCE = 0;
    DMA1REQbits.IRQSEL = 0b0001101;
    
    
    // DMA1STA Register
    DMA1STA = 0x0000;
    DMA1STB = 0x0000;
    
    
}