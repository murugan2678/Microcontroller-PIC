/*************************************************************************/
/* Auther       : Murugan M                                   	  	 */
/* Date         : 5/12/2022                                 	         */
/* File name    : stepper motor half route and reverse route led blink   */
/* Description  : using for loop                                         */
/*************************************************************************/



#include<htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_OFF & LVP_ON);

int i,j,k,m,n,l;
char arr[] = {0X07,0X03,0X0B,0X09,0X0D,0X0C,0X0E,0X06};

int main()
{
	TRISC = 0;
	PORTC = 0X00;
  TRISD = 0;
	
	while(1)
	{
	  for(k=0; k<=12; k++)                       //half route 
	  {
		for(i=0; i<=8; i++)
		{
		     RD5 = 1;                        //first led blink 
		     RD4 = 0;
		     RD3 = 0;
		     RD2 = 0;
		     PORTC = arr[i];
		     __delay_ms(30);
		}
	   }
	   __delay_ms(1000);
	    
	  for(k=0; k<=12; k++)
	  {
		for(j=0; j<=8; j++)
		{
		     RD5 = 0;
		     RD4 = 1;                        //second led blink
	             RD3 = 0;
		     RD2 = 0;
		     PORTC = arr[j];
		     __delay_ms(30);
		}
	   }
	   __delay_ms(1000);
		
	   for(k=0; k<=13; k++)
	   {
		for(m=0; m<=8; m++)
	        {
		     RD5 = 0;
		     RD4 = 0;
		     RD3 = 1;                        //third led blink
		     RD2 = 0;
		     PORTC = arr[m];
		     __delay_ms(30);
		}
	   }
	   __delay_ms(1000);
		
	   for(k=0; k<=13; k++)
	   {
	         for(n=0; n<=8; n++)
		 {
		      RD5 = 0;
		      RD4 = 0;
		      RD3 = 0;
		      RD2 = 1;                       //fourth led blink
		      PORTC = arr[n];
		      __delay_ms(30);
		  }
	    }
	    __delay_ms(3000);
	}
}
		
