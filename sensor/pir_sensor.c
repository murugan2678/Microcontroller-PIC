/*******************************************************************/
/* Auther       : Murugan M                                   	   */
/* Date         : 16/11/2022                                 	   */
/* File name    : PIR_sensor                          			   */
/* Description  : PIR-passive infrared sensor object crossing      */
/*                means detector led blink                         */
/*******************************************************************/








#include<htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);

#define PIR RD1                  //declare pir sensor rd1
void main()
{
	TRISD1 = 1;                 //rd1 pin connect with dout pin connect pir sensor
	TRISC0 = 0;                 //rc0 pin connect with led pin
	
 while(1)
  { 
    if(RD1 == 1)                //object detector means led on 
    {
	    RC0 = 1;                //object detector means led on 
	  }
	  else
	  {
		  RC0 = 0;              //no object means led off
	  }
  }
} 