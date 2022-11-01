/****************************************************************/
/* Author          : Murugan M                                  */
/* Date            : 21/10/2022                                 */
/* File name       : Timer 1-16 bit controller 100milliseconds  */
/* Description     : Using  Timer 1                             */
/****************************************************************/











#include <htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);

		
void delay();
				
int main()
{	
	TRISB1 = 0;
	RB1 = 1;
	__delay_ms(1000);
	RB1 = 0;
	__delay_ms(1000);
	
}

void delay()
{
	TMR1CS  = 0;                  //timer 1 clock source select bits
	T1CKPS0 = 1;                  //timer 1 ps0 and ps1 input clock prescaler select bits
	T1CKPS1 = 1;
	
	TMR1H = 0X0B;                 //this 8 bit high
	TMR1L = 0XDC;                 //this 8 bit low total 16 bit for timer1
	TMR1ON = 1;                   //timer 1 on
	while(!TMR1IF);
	       TMR1IF = 0;
	TMR1ON = 0;                   //timer 1 off
}
