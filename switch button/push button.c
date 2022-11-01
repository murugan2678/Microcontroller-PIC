/***************************************************************/
/* Author          : Murugan M                                 */
/* Date            : 25/9/2022                                 */
/* File name       : push button from led blink                */
/* Description     : Using  while and if condition             */
/***************************************************************/










#include<htc.h>
#include<stdio.h>
#define _XTAL_FREQ 20000000
__CONFIG (FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);

void main()
{
		TRISD0 = 1;
		TRISB0 = 0;
		RB0 = 0;

       
 while(1)
 {
  if(RD0 == 0)
  {
  	__delay_ms(100);
	
    if(RD0 == 0)
    {
	    RB0 = 1;
		  __delay_ms(100);
		
		  RB0 = 0;
		  __delay_ms(100);
	   }
   }
  }
}
