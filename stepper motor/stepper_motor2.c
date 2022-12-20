/********************************************************************/
/* Auther       : Murugan M                                   	  	*/
/* Date         : 4/12/2022                                 	    */
/* File name    : stepper motor off forward route and reverse route */
/* Description  : using for loop                                    */
/********************************************************************/








#include<htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);


int i,j,k,m,n;
char arr[] = {0X07,0X03,0X0B,0X09,0X0D,0X0C,0X0E,0X06};

int main()
{
	TRISC = 0;
	PORTC = 0X00;
	
	while(1)
	{
		for(k=0; k<=25; k++)      		//off route forward 
		{
			for(i=0; i<=8; i++)         //8 coil there for stepper motor forward route
			{
				PORTC = arr[i];         //array take for variable in looping
				__delay_ms(30);
			}
		}
		__delay_ms(1000);
		
		for(k=0; k<=25; k++)       
		{
			for(j=7; j>=0; j--)        //off route reverse
			{
				PORTC = arr[j];
				__delay_ms(30);
			}
		}
		__delay_ms(1000);
		
		for(k=0; k<50; k++)           //step by step full route for stepper motor total 50 step
		{
			for(m=0; m<8; m++)
			{
				PORTC = arr[m];
				__delay_ms(30);
			}
		}
		__delay_ms(1000);
		
		for(k=0; k<50; k++)      
		{
			for(n=7; n>=0; n--)      //full route reverse 
			{
				PORTC = arr[n];
				__delay_ms(30);
			}
		}
		__delay_ms(1000);
	}
}