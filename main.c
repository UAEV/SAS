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
    setup(void);
    LED_Tris = 0;
    
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
        if(IFS0bits.AD1IF){
            ADCval[0] = *ADCPtr; //Buffer for first Acc Sensor
            ADCval[1] = *(ADCPtr++); //Buffer for second Acc Sensor
            IFS0bits.AD1IF = 0;
            loadSpeed(&speed, &ADCval);
            readyToSend = 1;
            TMR5 = 0;
            //tempADCval2 = Ad1BUF0[1];
            
            
        }
        
        
        if(readyToSend  && clearToSend){
            readyToSend = 0;
            UARTSend(&speed);
        }
        
        if(plausCheck){
            plausCheck = 0;
            int temp = plausCount;
            plausCount += checkTPS(&ADCval);
            if(temp == plausCount){
                plausCount = 0;
            }else if(plausCount > 10){
                // Kill Motor
            }
            
        }
        
        //if(TransmitReady){
            
        //}
    
    
    }

}
