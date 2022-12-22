/**************************************************************************************/
/* Auther       : Murugan M                                   	                      */
/* Date         : 15/12/2022                                 	                      */
/* File name    : uart_universal asynchronous receiver transmitter                    */
/* Description  : using sparg and txen,spen interrupt flag set this one transmitter   */
/**************************************************************************************/








#include<htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(0X1F7A);

unsigned char uart_rx(void);
void uart_init(void);
void uart_init()
{
	TRISC6 = 1;         //high 25 pin RC6/TX/CK TX-means transmitter CK-means clock wise 
	TRISC7 = 0;         //low 26 pin RC7/RX/DT 
	TXSTA = 0X00;       //TX Transmit status & control registor.(Address 98h)
	RCSTA = 0X00;       //RX Receive status & control registor.(Address 18h)
	SPBRG = 31;         //SPBRG Serial port baud rate gernertor registor.(Address 99h) 
	TXEN = 1;           //TXEN Transmit enable bit
	SPEN = 1;           //SPEN Serial port enable bit; 1=configures RC7/RX/DT 0=serial port and RC6/TX/CK pins a serial port pins;
	TXIF = 0;
	RCIF = 0;
}
void uart_tx(unsigned char val)
{
	TXREG = val;        //TX Transmit Buffer 
	while(TXIF == 0);   //TX Transmit Buffer  TX1F = 0;
	TXIF = 0;           //TX Transmit IF Interrupt flag set
}
void main()
{
	uart_init();
	uart_tx('S');
	__delay_ms(100);
	uart_tx('L');
	__delay_ms(100);
	uart_tx(' ');
	__delay_ms(100);
	uart_tx('D');
	__delay_ms(100);
	uart_tx('P');
	__delay_ms(100);
	uart_tx('I');
	__delay_ms(100);
	
	while(1);
}
