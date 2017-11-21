/*
 * File:   ADC.c
 * Author: Nick
 *
 * Created on November 8, 2017, 8:53 PM
 */


//#include <p33FJ128GP804.h>


#include <xc.h>
#include "PinDef.h"
#include "Vars.h"
#include "Functions.h"



/*
 *Turn on ADC in 10 bit four channel mode and returns integers
 *dspic33fj data sheet page 257 and up for control registers 
 */
void ADC_Init(void){
    
    // Select analog inputs
    AD1PCFGL = 0xffff; // Need to cross reference with schematic
    
    //AD1CON1 Register set
    
    AD1CON1bits.ADSIDL = 0;
    AD1CON1bits.ADDMABM = 1; //
    AD1CON1bits.AD12B = 0;
    AD1CON1bits.FORM = 0b00;  // ADC return Integer
    AD1CON1bits.SSRC = 0b100; // Timer 5 stops sample and starts conversion
    AD1CON1bits.SIMSAM = 1;   
    AD1CON1bits.ASAM = 1;
    //AD1CON1bits.SAMP = 0;     //ADC Sample when manually called
    //AD1CON1bits.DONE = 0;
    
    //AD1CON2 Register set
    AD1CON2bits.VCFG = 0b000;
    AD1CON2bits.CSCNA = 0; //SCAN????? Only two analog signals will be taken in 
    AD1CON2bits.CHPS = 0b01;
    AD1CON2bits.SMPI = 0b0000; //??????
    AD1CON2bits.BUFM = 0;
    AD1CON2bits.ALTS = 0; //?????
    
    //AD1CON3 Register set
    AD1CON3bits.ADRC = 0;              // Everything set by timer 5
    AD1CON3bits.SAMC = 0;
    AD1CON3bits.ADCS = 0x00;
    
    //AD1CON4 Register set
    AD1CON4bits.DMABL = 0b000;
    
    //AD1CHS123 Register set
    //AD1CHS123bits.CH123NB = 0b00;     //Not needed?
    AD1CHS123bits.CH123NA = 0b00;       // Using only channel A for conversions
                                        // CH1, CH2, CH3 negative input is Vref-
    
    //AD1CHS123bits.CH123SB = 0b11;     //Not needed?
    AD1CHS123bits.CH123SA = 0;          // Channel A
    
    AD1CHS0bits.CH0NA = 0;
    AD1CHS0bits.CH0SA = 0b00000;        // Have to cross reference with Schematic
    
    // No input scan we will read simultaneously 
    AD1CSSL = 0x0000;
    
    
    /* AD1PCFGL set input pins
     * Not sure if tris registers need to be set as inputs
     * 
     */
    
    
    
    
    AD1CON1bits.ADON = 1;
    
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

//void ADC_Ch0_Init(int mask){
  //  AD1PCFGL = !mask;
    




void ADC_Samp(){
    AD1CON1bits.SAMP = 1;
}

void loadSpeed(Speed *speed[], int *val[]){
    int i = 0;
    while(i < 2){
        speed[i]->speedL = *val[i] >>2;
        
        //Currently only using 8 most significant bits
        //Might use below code to utilize all data later
        /*speed[i]->speedL = val[i];
        val[i] >> 8;
        speed[i]->speedH = val[i];
        i++;
         */
    } 
    
}

char average(char val1, char val2){
    int temp = val1 + val2;
    return (char)(temp >> 1);
}


int checkTPS(int *val[]){
    int temp = (int) val[0];
    int temp2 = (int) val[1];
    int diff;
    if(temp >= temp2){
        diff = .1*temp;
        if(temp2 + diff < temp){
            return 1;
        }
        return 0;
    }else{
        diff = .1*temp2;
        if(temp + diff < temp2){
            return 1;
        }
        return 0;
    }
    
    
}


//void __attribute__((interrupt, auto_psv)) AD1Interrupt(void){
    

//}

