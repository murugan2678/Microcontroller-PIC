/***************************************************************/
/* Author          : Murugan M                                 */
/* Date            : 3/10/2022                                 */
/* File name       : 7segment_0to9_common_anode                */
/* Description     : Using for while                           */
/***************************************************************/









#include <htc.h>
#include <stdio.h>
#define _XTAL_FREQ 20000000
__CONFIG (FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);

void main()
{
	TRISC = 0;
	PORTC = 0X00;
	
	
	
	 
	
	while(1)
	{
		PORTC = 0XC0;
		__delay_ms(600);
		
		PORTC = 0XF9;
		__delay_ms(300);
		
		PORTC = 0XA4;
		__delay_ms(300);
		
		PORTC = 0XB0;
		__delay_ms(300);
		
		PORTC = 0X99;
		__delay_ms(300);
		
		PORTC = 0X92;
		__delay_ms(300);
		
		PORTC = 0X82;
		__delay_ms(300);
		
		PORTC = 0XF8;
		__delay_ms(300);
		
		PORTC = 0X80;
		__delay_ms(300);
		
		PORTC = 0X90;
		__delay_ms(300);
	}
}
		