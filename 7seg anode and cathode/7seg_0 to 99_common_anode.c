/***************************************************************************/
/* Author          : Murugan M                                             */
/* Date            : 6/10/2022                                             */
/* File name       : 7seg 0 to 99 common anode this work proteus           */
/* Description     : Using array and for loop                              */                       
/***************************************************************************/












#include <htc.h>
#define _XTAL_FREQ 20000000
__CONFIG (FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);

int i,j,k;
char arr[] = {0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
	
int main()
{
		TRISD2 = 0;
		TRISD3 = 0;
		TRISB = 0;
		
		while(1)
		{
		  for(i=0; i<10; i++)
	       for(j=0; j<10; j++)
	         for(k=0; k<100; k++)
	            {
		             RD3   =   1;
		             __delay_ms(3);
		             RD2   =   0;
		             
		             PORTB = arr[j];
		       
		             RD2   =   1;
		             __delay_ms(3);
		             RD3   =   0;
		            
		             PORTB = arr[i];
		             
	
		          }
		      
	  }
}		
		
	