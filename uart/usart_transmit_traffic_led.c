/**************************************************************************/
/* Auther       : Murugan M                                               */
/* Date         : 3/1/2023                                                */
/* File name    : usart transmitter traffic led                           */
/* Description  : universal synchronous asynchronous receiver transmitter */
/**************************************************************************/









#include<htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x1F7A);

unsigned char uart_rx (void);
void uart_init(void);

void uart_init()
{
	TRISC6 = 0;	            //Low 25 pin RC6/TX/CK
	TXSTA = 0X00;           //Transmit status and control Register Address 98h
	RCSTA = 0X00;           //Receiver status and control Register Address 18h
	SPBRG = 31;             //Serial port baud rate generator register 99h
    TXEN = 1;               //Transmit enable bit
    SPEN = 1;               //Serial port enable bit
	TXIF = 0;              
	   
}
void uart_tx(unsigned char val)
{
    TXREG = val;            //Transmit buffer 
	while(TXIF == 0);       //Transmit buffer TXIF = 0
	TXIF = 0;               //Transmit IF means inter flag set
}
void main()
{
	uart_init();
	uart_tx('R');           //data
	__delay_ms(500);
	uart_tx('Y');
	__delay_ms(500);
	uart_tx('G');
	__delay_ms(500);
    uart_tx(' ');
    __delay_ms(500);

    while(1);
   
}	