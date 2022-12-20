/********************************************************************/
/* Auther       : Murugan M                                   	  	*/
/* Date         : 3/12/2022                                 	    */
/* File name    : stepper motor forward route and reverse route     */
/* Description  : using for loop                                    */
/********************************************************************/








#include<htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);

int a,i,j,k,m,n;
char arr[] = {0X07,0X03,0X0B,0X09,0X0D,0X0C,0X0E,0X06};

int main()
{
	TRISC =0;
	PORTC =0X00;
	TRISD =0;

while(1)
{		
	for(k=0; k<50; k++)            //step by step route for stepper motor total 50 step
	{
		for(i=0; i<8; i++)         //8 coil there for stepper motor forward route
		{	
			RD2 = 0;               //led off
			RD3 = 1;               //led on forward route
		    PORTC = arr[i];        //array take for variable in looping
		    __delay_ms(30);
		}
	}
	__delay_ms(500); 
		
	for(k=0; k<50; k++)  
	{
		for(j=7; j>=0; j--)        //8 coil there for stepper motor reverse route
		{
			RD3 = 0;               //led off
			RD2 = 1;               //led on reverse route
			PORTC = arr[j];        //array take for variable in looping
			__delay_ms(30);
		}
	}
 }
}