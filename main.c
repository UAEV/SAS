/*
 * File:   main.c
 * Author: TylerMatthews
 *
 * Created on November 6, 2017, 6:47 PM
 */


#include <xc.h>
#include <stdio.h>
<<<<<<< HEAD
#include <pindef.h>


void main(void) {

=======
#include "ADC.h"



void main(void) {
    
    /*
     * Main loop for SAS board
     */
    while(1){
        
    
    
    
 /*
  * 
  * Read inputs from potentiometers for gas pedal
  */
        if(readyToSample){
            ADC_Samp;
            //ADC1BUF0bits
        }
        if(ADCReady){
            //ADCVaulue = AD1BUF0
        }
        
        //if(TransmitReady){
            
        //}
    
    
    }
>>>>>>> 1c05aac93fb86685fc3b425f555d5b5d7603f1de
}
