/**********************************************************/
/*  Author            : Murugan M                         */
/*  Date              : 26/9/2022                        */
/*  File name         : all push button                   */
/*  Description       : Using while and if condition      */
/**********************************************************/










#include <htc.h>
#include <stdio.h>
#define _XTAL_FREQ 20000000
__CONFIG (FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);

void main()
{
    TRISB = 0X00;
    TRISD = 0X00;
    int i = 0;
	while(1)
	{
      if(i==0)
      {
		if(RD0 == 0)
		{
	     		PORTB = 0X01;
				__delay_ms(100);
				PORTB = 0X00;
				__delay_ms(200);
         }
         if(RD1 == 0)
         {
             PORTB = 0X02;
             __delay_ms(100);
             PORTB = 0X00;
             __delay_ms(200);
         }
         if(RD2 == 0)
         {
             PORTB = 0X04;
             __delay_ms(100);
             PORTB = 0X00;
             __delay_ms(200);
         }
         if(RD3 == 0)
         {
             PORTB = 0X08;
             __delay_ms(100);
             PORTB = 0x00;
             __delay_ms(200);
         } 
         if(RD4 == 0)
         {
             PORTB = 0X10;
             __delay_ms(100);
             PORTB = 0X00;
             __delay_ms(200);
         } 
         if(RD5 == 0)
         {
             PORTB = 0X20;
             __delay_ms(100);
             PORTB = 0X00;
             __delay_ms(200);
         }
         if(RD6 == 0)
         {
             PORTB = 0X40;
             __delay_ms(100);
             PORTB = 0X00;
             __delay_ms(200);
         }
         if(RD7 == 0)
         {
             PORTB = 0X80;
             __delay_ms(100);
             PORTB = 0X00;
             __delay_ms(200);
         } 
       }  
     }    
 }            
