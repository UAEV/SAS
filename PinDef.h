/* 
 * File:   PinDef.h
 * Author: Tyler Matthews
 * Last Updated: 11/7/17
 * Pre-Compiler Pin Definitions
 * 
 * Format: "#Define" "Name" "Value" "//Description"
 */

#ifndef PINDEF_H
#define	PINDEF_H


///////////////Misc Definitions copied from old code. May or may not be useful, keeping them for now///////////////
#define ON              0
#define OFF             1

#define TALK            1
#define LISTEN          0

#define INPUT           1
#define OUTPUT          0

#define WEAK_PULL_UP    1
//////////////////////////////////////////////End of Misc Definitions//////////////////////////////////////////////

//LED
#define LED_Tris        TRISBbits.TRISB9    //LED IO
#define LED_Lat         LATBbits.LATB9      //LED OutPut 
#define LED_Port        PORTBbits.RB9       //LED Input

//External Watchdog
#define WDI_TRIS        TRISBbits.TRISB12   //WDI (External Watchdog) IO
#define WDI_Lat         LATBbits.LATB12     //WDI (External Watchdog) Output
#define WDI_Port        PORTBbits.RB12      //WDI (External Watchdog) Input

//RS485 Enable Pin: Output data when high, receive data when low
#define U13_Tris        TRISCbits.TRISC8    //U13 (RS485 differential driver enable) IO
#define U13_Lat         LATCbits.LATC8      //U13 (RS485 differential driver enable) Ouput
#define U13_Port        PORTCbits.RC8       //U13 (RS485 differential driver enable) Input

//RS485(1) Receive Pin
#define RX1_Tris    TRISCbits.TRISC6        //RX1 IO
#define RX1_Lat     LATCbits.LATC6          //RX1 Output
#define RX1_Port    PORTCbits.RC6           //RX1 Input
#define RX1_Pin_Map     RPINR18bits.U1RXR   //Used to set UART1 Recieve to corresponding pin
#define RP22   RPOR11bits.RP22R             //Setting RP22 Peripherial Pin output Function
#define RX1_PIN_SET     22                  //Used to set UART1 Recieve to RP22

//RS485(1) Transmit Pin
#define TX1_Tris    TRISCbits.TRISC7        //TX1 IO
#define TX1_Lat     LATCbits.LATC7          //TX1 Output
#define TX1_Port    PORTCbits.RC7           //TX1 Input
#define RP23   RPOR11bits.RP23R             //Setting RP23 Peripherial Pin output Function
#define TX1_OUTPUT      3                   //RPn tied to UART1 Transmit (Use this to set RP23 to Uart1 TX)

//RS485(2) Receive Pin - FTDI
#define RX2_Tris    TRISBbits.TRISB7        //RX2 IO
#define RX2_Lat     LATBbits.LATB7          //RX2 Output
#define RX2_Port    PORTBbits.RB7           //RX2 Input
#define RX2_Pin_Map     RPINR18bits.U1RXR   //Used to set UART2 Recieve to corresponding pin
#define RP7   RPOR11bits.RP7R               //Setting RP7 Peripherial Pin output Function
#define RX2_PIN_SET     7                   //Used to set UART2 Recieve to RP7

//RS485(2) Transmit Pin - FTDI
#define TX2_Tris    TRISBbits.TRISB8        //TX2 IO
#define TX2_Lat     LATCBits.LATB8          //TX2 Output
#define TX2_Port    PORTBbits.RB8           //TX2 Input
#define RP8    RPOR4bits.RP8R               //Setting RP8 Peripherial Pin output Function
#define TX2_OUTPUT      7                   //RPn tied to UART2 Transmit (Use this to set RP8 to Uart2 TX)         


#endif	/* PINDEF_H */

