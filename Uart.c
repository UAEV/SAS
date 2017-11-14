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
    U1MODEbits.UARTEN = 1; //Enable UART1
    U1MODEbits.USIDL = 0; //Continue during idle
    U1MODEbits.IREN = 0; //IrDA encoder/decoder disable
    U1MODEbits.RTSMD = 0; //U1RTS in flow control mode
    U1MODEbits.UEN = 0b00; //U1TX and U1RX are enabled and used. UxCTS and UxRTS/BCLK pins controlled by port latches
    U1MODEbits.WAKE = 0; //No wake-up enabled
    U1MODEbits.LPBACK = 0;
    U1MODEbits.ABAUD = 0;
    U1MODEbits.URXINV = 0;
    U1MODEbits.BRGH = 0; //16x baud clock
    U1MODEbits.PDSEL = 0b00; //8bit data - no parity
    U1MODEbits.STSEL = 0;
    
    U1STAbits.URXISEL = 0b00;   //Interrupt when a character is transferred to the Transmit Shift register (this implies there is at least one character open in the transmit buffer)
    U1STAbits.UTXINV = 0;       //0 = UxTX Idle state is ?1?
    U1STAbits.UTXBRK = 0;
    U1STAbits.UTXEN = 1;    //Transmit enable bit
    U1STAbits.URXISEL = 0b00;
    U1STAbits.ADDEN = 0; //Address detect bit
    U1STAbits.OERR = 0;  //Overrun Error Status Bit
    
    
    
    
}

//Change
//Will need to send up for one byte at a time for now
void UARTSend(Speed *data[]){
    requestToSend = 0;
    U1TXB[0] = data[0]->speedH;
    U1TXB[1] = data[0]->speedL;
    U1TXB[2] = data[1]->speedH;
    U1TXB[3] = data[1]->speedL;
    
    }

