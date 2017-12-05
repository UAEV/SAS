/* 
 * File:   main.c
 * Author: TylerMatthews
 *
 * Created on December 4, 2017, 10:43 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <p33FJ128GP804.h>
#include "PinDef.h"
#include "Functions.h"
#include "Vars.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char speed[2];
    int ADCval[2];
    int readyToSend = 0;
    int clearToSend = 0;
    LED_Tris = 0; //Setting LED Pin to output
    
    setup(); //Initial Setup
    
    while(1){
        
        // Read inputs from potentiometers for gas pedal
        if(IFS0bits.AD1IF){
            ADCval[0] =  (ADCBUF0); //Buffer for first Acc Sensor
            //ADCval[1] =  *((&ADCBUF0)++); //Buffer for second Acc Sensor
            IFS0bits.AD1IF = 0;
            loadSpeed(speed, ADCval);
            readyToSend = 1;
            TMR5 = 0;
            //tempADCval2 = Ad1BUF0[1];
        }
        if(readyToSend  && clearToSend){
            readyToSend = 0;
            UARTSend(speed[0]);
        }
        
        if(plausCheck){
            plausCheck = 0; //Reset timer
            int temp = plausCount;
            plausCount += checkTPS(ADCval);
            if(temp == plausCount){
                plausCount = 0; //ADC Values within acceptable range
            }else if(plausCount > 10){ //100ms has passed and ADC values are still out of range
                // Kill Motor
            }
        }
    }    
    
    
    return (EXIT_SUCCESS);
}

