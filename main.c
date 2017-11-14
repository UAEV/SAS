/*
 * File:   main.c
 * Author: TylerMatthews
 *
 * Created on November 6, 2017, 6:47 PM
 */


#include <xc.h>
#include <stdio.h>
#include "PinDef.h"
#include "ADC.h"
#include "Timer.h"
#include "UART.h"

//#include "UART.h"


Speed speed[];

void main(void) {
    
    /*
     * Main Setup
     */
    //T5_Setup(void);
    //ADC_Init(void);
    //UART_Init();
    setup(void);
   // while(!UARTTest);
    
    
    
    
    
    /*
     * Main loop for SAS board
     */
    while(1){
        
    
    
    
 /*
  * 
  * Read inputs from potentiometers for gas pedal
  */
        //if(readyToSample){
        //    ADC_Samp;
            //ADC1BUF0bits
        //}
        if(!IFS0bits.AD1IF){
            ADCval[0] = *ADCPtr;
            ADCval[1] = *(ADCPtr++);
            IFS0bits.AD1IF = 0;
            loadSpeed(&speed, &ADCval);
            readyToSend = 1;
            //tempADCval2 = Ad1BUF0[1];
            
            
        }
        
        
        if(readyToSend){
            readyToSend = 0;
            UARTSend(&speed);
        }
        
        //if(TransmitReady){
            
        //}
    
    
    }

}
