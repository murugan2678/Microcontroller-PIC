/*************************************************************/
/* Auther       : Murugan M                                  */
/* Date         : 28/10/2022                                 */
/* File name    : keypad_display num for 7segment            */
/* Description  : Using array and for loop                   */
/*************************************************************/








#include<htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);

#define row_1 RD0
#define row_2 RD1
#define row_3 RD2
#define row_4 RD3

#define col_1 RD4                   //keypad make rows as output/colum as input
#define col_2 RD5                   //7-segment connection PORTB as output 
#define col_3 RD6                   //RD0 as output for 7-segment
#define col_4 RD7

void main()
{
	TRISD = 0XF0;

	TRISB = 0;
	RBIF = 0;
	
	while(1)
	{
	    row_1 = 1;
		row_2 = 0;
		row_3 = 0;
		row_4 = 0;
		
		if(PORTD == 0X11)
		{
			PORTB = 0XC0;
			while(col_1 == 1);
		}
		
		if(PORTD == 0X21)
		{
			PORTB = 0XF9;
			while(col_1 == 1);
		}
		
		if(PORTD == 0X41)
		{
			PORTB = 0XA4;
			while(col_1 == 1);
		}
		
		if(PORTD == 0X81)
		{
			PORTB = 0XB0;
			while(col_1 == 1);
		}
    
    
    row_1 = 0;
    row_2 = 1;
    row_3 = 0;
    row_4 = 0;
    
    if(PORTD == 0X12)
    {
	    PORTB = 0X99;
	    while(col_2 == 1);
	  }
	  if(PORTD == 0X22)
	  {
		  PORTB = 0X92;
		  while(col_2 == 1);
		}
		if(PORTD == 0X42)
		{
			PORTB = 0X82;
			while(col_2 == 1);
		}
		if(PORTD == 0X82)
		{
			PORTB = 0XF8;
			while(col_2 == 1);
		}
	
	 
		row_1 = 0;
		row_2 = 0;
		row_3 = 1;
		row_4 = 0;
		
		if(PORTD == 0X14)
		{
			PORTB = 0X80;
			while(col_3 == 1);
		}
		if(PORTD == 0X24)
		{
			PORTB = 0X90;
			while(col_3 == 1);
		}
		if(PORTD == 0X44)
	  {
			PORTB = 0XC0;
			while(col_3 == 1);
		}
		if(PORTD == 0X84)
		{
			PORTB = 0XF9;
			while(col_3 == 1);
		} 
		
		
		row_1 = 0;
		row_2 = 0;
		row_3 = 0;
		row_4 = 1;
		
		if(PORTD == 0X18)
		{
			PORTB = 0XA4;
			while(col_4 == 1);
		}
		if(PORTD == 0X28)
		{
			PORTB = 0XB0;
			while(col_4 == 1);
		}
		if(PORTD == 0X48)
		{
			PORTB = 0X99;
			while(col_4 == 1);
		}
		if(PORTD == 0X88)
		{
			PORTB = 0X92;
			while(col_4 == 1);
		}
			
		else
		{
				PORTB = 0X00;
		}
 
	}
}