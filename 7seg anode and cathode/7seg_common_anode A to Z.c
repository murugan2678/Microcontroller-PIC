/***************************************************************/
/* Author          : Murugan M                                 */
/* Date            : 3/10/2022                                 */
/* File name       : 7segment_common_anode A to Z              */
/* Description     : Using while                               */
/***************************************************************/









#include <htc.h>
#include <stdio.h>
#define _XTAL_FREQ 20000000
__CONFIG (FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);

void main()
{
	TRISB = 0;
	PORTB = 0;
	
		 	
	while(1)
	{
		PORTB = 0X88;
		__delay_ms(500); 
		
		PORTB = 0X80;
		__delay_ms(200);
		
		PORTB = 0XC6;
		__delay_ms(400);
		
		PORTB = 0XC0;
		__delay_ms(200);
		
		PORTB = 0X86;
		__delay_ms(400);
		
		PORTB = 0X8E;
		__delay_ms(200);
		
		PORTB = 0X89;
		__delay_ms(400);
		
		PORTB = 0XC7;
		__delay_ms(400);
		
  	    PORTB = 0XC8;
		__delay_ms(200);
		
		PORTB = 0XC0;
		__delay_ms(400);
		
		PORTB = 0X8C;
		__delay_ms(300);
		
		PORTB = 0X88;
		__delay_ms(200);
		
		PORTB = 0X92;
		__delay_ms(400);
		
		PORTB = 0XC1;
		__delay_ms(200);
		
		PORTB = 0X91;
		__delay_ms(200);
		
	}
	
}