/*
 * File:   ADC.c
 * Author: Nick
 *
 * Created on November 8, 2017, 8:53 PM
 */


//#include <p33FJ128GP804.h>


#include <xc.h>
#include "Functions.h"






//void ADC_Ch0_Init(int mask){
  //  AD1PCFGL = !mask;
    




void ADC_Samp(){
    AD1CON1bits.SAMP = 1;
}

void loadSpeed(char speed[], int val[]){
    int i = 0;
    while(i < 2){
        speed[i] = val[i] >>2;
        
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


int checkTPS(int val[]){
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

