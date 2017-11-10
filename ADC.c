/*
 * File:   ADC.c
 * Author: Nick
 *
 * Created on November 8, 2017, 8:53 PM
 */


#include "xc.h"




/*
 *Turn on ADC in 10 bit four channel mode and returns integers
 *dspic33fj data sheet page 257 and up for control registers 
 */
void ADC_Init(void){
    
    //AD1CON1 Register set
    AD1CON1bits.ADON = 1;
    AD1CON1bits.ADSIDL = 0;
    AD1CON1bits.ADDMABM = 1;
    AD1CON1bits.AD12B = 0;
    AD1CON1bits.FORM = 0b00;
    AD1CON1bits.SSRC = 0b100;
    AD1CON1bits.SIMSAM = 1;
    AD1CON1bits.ASAM = 0;
    AD1CON1bits.SAMP = 0;
    AD1CON1bits.DONE = 0;
    
    //AD1CON2 Register set
    AD1CON2bits.VCFG 0b000;
    AD1CON2bits.CSCNA = 0; //SCAN????? Only two analog signals will be taken in 
    AD1CON2bits.CHPS = 0b01;
    AD1CON2bits.SMPI = 0b0000; //??????
    AD1CON2bits.BUFM = 0;
    AD1CON2bits.ALTS = 0; //?????
    
    //AD1CON3 Register set
    AD1CON3bits.ADRC = 0;
    AD1CON3bits.ADCS = 0x00;
    
    //AD1CON4 Register set
    AD1CON4bits.DMABL = 0b000;
    
    //AD1CHS123 Register set
    //AD1CHS123bits.CH123NB = 0b00; //Not needed?
    AD1CHS123bits.CH123NA = 0b00; //?????
    //AD1CHS123bits.CH123SB = 0b11; //Not needed?
    AD1CHS123bits.CH123SA = 0; //??????
    
    /*
     * Not sure how channel 0 works yet
     */
    //AD1CHS0 Register
    //AD1CHS0 //
    
    /*
     * AD1CSSL Have to compare with schematic to see
     * what ADC inputs are being used
     */
    //AD1CSSL
    
    /*
     * AD1PCFGL Register
     */
}

void ADC_Samp(){
    AD1CON1bits.SAMP = 1;
}





