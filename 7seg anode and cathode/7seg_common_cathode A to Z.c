/***************************************************************/
/* Author          : Murugan M                                 */
/* Date            : 3/10/2022                                 */
/* File name       : 7segment_common_cathode  A to Z           */
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
		PORTB = 0X77;
		__delay_ms(500); 
		
		PORTB = 0X7F;
		__delay_ms(200);
		
		PORTB = 0X39;
		__delay_ms(400);
		
		PORTB = 0X79;
		__delay_ms(200);
		
	    PORTB = 0X71;
		__delay_ms(400);
		
		PORTB = 0X76;
		__delay_ms(200);
		
		PORTB = 0X38;
		__delay_ms(400);
		
		PORTB = 0X37;
		__delay_ms(400);
		
   	    PORTB = 0X3F;
		__delay_ms(200);
		
		PORTB = 0X73;
		__delay_ms(400);
		
		PORTB = 0X77;
		__delay_ms(300);
		
		PORTB = 0X6D;
		__delay_ms(200);
		
		PORTB = 0X3E;
		__delay_ms(400);
		
		PORTB = 0X6E;
		__delay_ms(200);
		
	}
	
}