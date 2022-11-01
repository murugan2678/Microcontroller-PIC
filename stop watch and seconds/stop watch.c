/*************************************************/
/* Auther       : Murugan M                      */
/* Date         : 9/10/2022                      */
/* File name    : stop watch                     */
/* Description  : Using array and for loop       */
/*************************************************/














#include <htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);

int i,j,k,l,m;
char arr[] = {0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};

	int main()
	{
		TRISD2 = 0;
		TRISD3 = 0;
		TRISD4 = 0;
		TRISD5 = 0;
		TRISB = 0;
		TRISD = 0X00;
		
		while(1)
		{
			for(i=0; i<10; i++)
			   for(j=0; j<10; j++)
			       for(l=0; l<10; l++)
			         for(m=0;  m<10; m++)
			            for(k=0; k<10; k++)
			              {
				              RD5 = 1;
				              __delay_ms(3);
				              RD4 = 0;
				              PORTB = arr[m];
				             
				              
				              RD4 = 1;
				              __delay_ms(3);
				              RD5 = 0;
				              PORTB = arr[i];
				             
				              
				              RD3 = 1;
				              __delay_ms(3);
				              RD2 = 0;
				              PORTB = arr[j];
				            
				              
				              RD2 = 1;
				              __delay_ms(3);
				              RD3 = 0;
				              PORTB = arr[l];
				            
                    }
          }
     } 
               