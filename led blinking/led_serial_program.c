/***************************************************************/
/* Author          : Murugan M                                 */
/* Date            : 21/9/2022                                 */
/* File name       : led_serial_program                        */
/* Description     : Using for loop and bitwise operator       */
/***************************************************************/







#include <htc.h>
#define _XTAL_FREQ 20000000
__CONFIG (FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);

void main()
{
	int i;
	TRISB = 0;
	int a,b,c;
    
    a = 0b00000001;
	
for(i=0; i<8; i++)
    {
         PORTB = a;
         __delay_ms(100);
	     a = a<<1;                  //bitwise operator shift left
   	}
		__delay_ms(800);

    a = 0X80;
   
for(i=0; i<8; i++)
    {
         PORTB = a;
         __delay_ms(100);
         a = a>>1;                  //bitwise operator shift right
    }
     __delay_ms(800);
	
for(i=0; i<8; i++)
    {
        PORTB = 0X01;
        __delay_ms(200);

        PORTB = 0X02;
        __delay_ms(200);

        PORTB = 0X04;
        __delay_ms(200);
	
        PORTB = 0X08;
        __delay_ms(200);
    }
    __delay_ms(800);

for(i=0; i<8; i++)
    {
        PORTB = 0X10;
        __delay_ms(200);
        
        PORTB = 0X20;
        __delay_ms(200);

        PORTB = 0X40;
        __delay_ms(200);
       
        PORTB = 0X80;
        __delay_ms(200);
    }
    __delay_ms(800); 



for(i=0; i<8; i++)
    {
        PORTB = 0X80;
        __delay_ms(200);
        
        PORTB = 0X40;
        __delay_ms(200);

        PORTB = 0X20;
        __delay_ms(200);
       
        PORTB = 0X10;
        __delay_ms(200);
    }
    __delay_ms(800); 

for(i=0; i<8; i++)
    {
        PORTB = 0b00000001;
        __delay_ms(200);
        PORTB = 0b00000011;
        __delay_ms(200);
        PORTB = 0b00000111;
        __delay_ms(200);
        PORTB = 0b00001111;
        __delay_ms(200);
    
        PORTB = 0b00010000;
        __delay_ms(200);
        PORTB = 0b00110000;
        __delay_ms(200);
        PORTB = 0b01110000;
        __delay_ms(200);
        PORTB = 0b11110000;
        __delay_ms(200);
     }
     __delay_ms(800);
 
for(i=0; i<8; i++)
    {
	    PORTB = 0X81;
	    __delay_ms(200);
	    
	    PORTB = 0X42;
	    __delay_ms(200);
	    
	    PORTB = 0X24;
      __delay_ms(200);

      PORTB = 0X18;
      __delay_ms(200);   
	  }	
     __delay_ms(800);

for(i=0; i<8; i++)
    {
        PORTB = 0XF0;
        __delay_ms(200);
        PORTB = 0X70;
        __delay_ms(200);
        PORTB = 0X30;
        __delay_ms(200);
        PORTB = 0X10;
        __delay_ms(200);
    
        PORTB = 0X0F;
        __delay_ms(200);
        PORTB = 0X07;
        __delay_ms(200);
        PORTB = 0X03;
        __delay_ms(200);
        PORTB = 0X01;
        __delay_ms(200);
     }
     __delay_ms(800);

for(i=0; i<8; i++)
    {
	    PORTB = 0X18;
	    __delay_ms(200);
	    
	    PORTB = 0X24;
	    __delay_ms(200);
	    
	    PORTB = 0X42;
        __delay_ms(200);

      PORTB = 0X81;
      __delay_ms(200);   
	   }	
      __delay_ms(800);
    
a = 0b01010101;
b = 0b10101010;
     
for(i=0; i<8; i++)
     {
        PORTB = a;
        __delay_ms(200);
        
        PORTB = b;
        __delay_ms(200);
        
        c = a^b;                        //bitwise operator xor
        c = a<<1;                       //bitwise operator shift left
        
        PORTB = c;
        __delay_ms(200);
        c = a>>1;                       //bitwise operator shift right
     }
 
     __delay_ms(800);
     
a = 0b11111111;
b = 0b00000000;

for(i=0; i<8; i++)
     {
	     PORTB = a;
	     __delay_ms(200);
	     
	     PORTB = b;
	     __delay_ms(200);
	     
	     c = a|b;
	     
	     PORTB = c;
	     __delay_ms(200);
	 }
	 __delay_ms(800);
}