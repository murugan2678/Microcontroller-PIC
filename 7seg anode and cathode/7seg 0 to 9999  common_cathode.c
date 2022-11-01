/*********************************************************************/
/* Auther       : Murugan M                                          */
/* Date         : 10/10/2022                                         */
/* File name    : 7seg 0 to 9999 common_cathode work from pic board  */
/* Description  : Using array and for loop                           */
/*********************************************************************/



#include <htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);



int i,j,k,l,m;

char arr[] =  {0XFC,0X60,0XDA,0XF2,0X66,0XB6,0XBE,0XE0,0XFE,0XF6};


int main()
{
	TRISD0 = 0;
	TRISD1 = 0;
	TRISD2 = 0;
	TRISD3 = 0;
	TRISC = 0;
	
	while(1)
	{
		for(i=0; i<10; i++)
		   for(j=0; j<10; j++)
		      for(l=0; l<10; l++)
		         for(m=0; m<10; m++)
		          for(k=0; k<100; k++)
		           {
			           RD0 = 0;
			           RD1 = 0;
			           RD2 = 0;
			           RD3 = 1;
			           PORTC = arr[m];
			           __delay_ms(3);
			         
			           
			           RD0 = 0;
			           RD1 = 0;
			           RD2 = 1;
			           RD3 = 0;
			           PORTC = arr[l];
			           __delay_ms(3);
			         
			         
			           RD0 = 0;
			           RD1 = 1;
			           RD2 = 0;
			           RD3 = 0;
			           PORTC = arr[j];
			           __delay_ms(3);
			           
			          
			           RD0 = 1;
			           RD1 = 0;
			           RD2 = 0;
			           RD3 = 0;
			           
			           PORTC = arr[i];
			           __delay_ms(3);
			       
			           
			         }
	    }
}	
