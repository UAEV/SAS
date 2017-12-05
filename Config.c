/*
 * File:   config.c
 * Author: TylerMatthews
 *
 * Created on November 7, 2017, 3:23 PM
 */

//Tells the PIC what the clock speed is (40MHz)

#include <xc.h>
#include "Functions.h"

//Fosc = Fin * (M/N2*N1) = 48MHZ => 24Mips
//Fcy = 24MHz

void setup(){
    oscSetup();
    ADC_Init();
    T1_Setup();
    T5_Setup();
}

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

void T1_Setup(void){
    T1CON = 0;
    T1CONbits.TSIDL = 0;
    T1CONbits.TCS = 0;
    //T1CONbits.TSYNC = 1;
    T1CONbits.TCKPS = 0b11; // Prescaler set 1:256  
    IEC0bits.T1IE = 1;
    PR1 = 1875;
    T1CONbits.TON = 1;
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
