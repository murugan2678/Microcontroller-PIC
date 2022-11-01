/***************************************************************/
/* Author          : Murugan M                                 */
/* Date            : 3/10/2022                                 */
/* File name       : 7segment_0to9_common_cathode            */
/* Description     : Using for loop 0 t0 9                     */
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
		PORTC = 0X3F;
		__delay_ms(500);
		
		PORTC = 0X06;
		__delay_ms(300);
		
		PORTC = 0X5B;
		__delay_ms(300);
		
		PORTC = 0X4F;
		__delay_ms(300);
		
		PORTC = 0X66;
		__delay_ms(300);
		
		PORTC = 0X6D;
		__delay_ms(300);
		
		PORTC = 0X7D;
		__delay_ms(200);
		
		PORTC = 0X07;
		__delay_ms(200);
		
		PORTC = 0X7F;
		__delay_ms(200);
		
		PORTC = 0X6F ;
		__delay_ms(200);
	}
}
		