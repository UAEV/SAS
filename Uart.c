/*
 * File:   UART.c
 * Author: Nick
 *
 * Created on November 12, 2017, 6:44 PM
 */


#include "xc.h"
#include "UART.h"
#include "ADC.h"

void UART_Init(){
    int temp = ((FCY/BRATE)/16) - 1;
    U1BRG = temp;
    
    // U1MODE Register settings
    U1MODEbits.UARTEN = 1;
    U1MODEbits.USIDL = 0;
    U1MODEbits.IREN = 0;
    U1MODEbits.RTSMD = 0;
    U1MODEbits.UEN = 0b00;
    U1MODEbits.WAKE = 0;
    U1MODEbits.LPBACK = 0;
    U1MODEbits.ABAUD = 0;
    U1MODEbits.URXINV = 0;
    U1MODEbits.BRGH = 0;
    U1MODEbits.PDSEL = 0b00;
    U1MODEbits.STSEL = 0;
    
    U1STAbits.URXISEL = 0b00;
    U1STAbits.UTXINV = 0;
    U1STAbits.UTXBRK = 0;
    U1STAbits.UTXEN = 1;
    U1STAbits.URXISEL = 0b00;
    U1STAbits.ADDEN = 0;
    U1STAbits.OERR = 0;
    
    
    
    
}

void UARTSend(Speed *data[]){
    U1TXREG[0] = data[0]->speedH;
    U1TXREG[1] = data[0]->speedL;
    U1TXREG[2] = data[1]->speedH;
    U1TXREG[3] = data[1]->speedL;
    
    }

