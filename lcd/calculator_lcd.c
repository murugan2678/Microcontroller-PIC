/*************************************************************/
/* Auther       : Murugan M                                  */
/* Date         : 5/11/2022                                  */
/* File name    : calculator from lcd                        */
/* Description  : Using if condition and CGRAM               */
/*************************************************************/














#include<htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);

#define RS RB1
#define RW RB2
#define EN RB3

#define row_1 RD0
#define row_2 RD1
#define row_3 RD2
#define row_4 RD3

#define col_1 RD4
#define col_2 RD5
#define col_3 RD6
#define col_4 RD7


void delay();
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char data);

void delay()
{
	TMR1CS = 0;
	T1CKPS0 = 1;
	T1CKPS1 = 1;
	TMR1H = 0X0B;
	TMR1L = 0XDC;
	TMR1ON = 1;
	while(TMR1IF == 0);
	      TMR1IF = 0;
	      TMR1ON = 0;
}
void lcd_cmd(unsigned char cmd)
{
	RS = 0;
	RW = 0;
	EN = 1;
	PORTC = cmd;
	delay();
	EN = 0;
}
void lcd_data(unsigned char data)
{
	RS = 1;
	RW = 0;
	EN = 1;
	PORTC = data;
	delay();
	EN = 0;
}


int main()
{
	  
      TRISC = 0;
      TRISB1 = 0;
      TRISB2 = 0;
      TRISB3 = 0;
      TRISD = 0;
      TRISD = 0XF0;
      PORTC = 0X00;
      
      
      lcd_cmd(0X38);                 // init 5X8-2 line RET home
      lcd_cmd(0X0C);                 // display on, display_cursor, display_blink
      lcd_cmd(0X01);                 // clear display
      lcd_cmd(0X02);                 // return to home
      lcd_cmd(0X06);                 // cursor ++
      
      lcd_cmd(0X40);                 // set CGRAM 
     
      
      
      lcd_data('6');                 // set data
      lcd_data('+');
      lcd_data('2');
      lcd_data('=');
      lcd_data('8');
    
    
      
	while(1)
	{
	    row_1 = 0;
		row_2 = 1;
		row_3 = 0;
		row_4 = 0;
		
		
		if(PORTD == 0X42)
		{  
			 lcd_cmd(0X80);                   // set DDRAM first line lcd display
			 lcd_cmd(col_2 == 1);             // set column
			 lcd_data('6');                   // set data
			 __delay_ms(100);
	    }	 	

		row_1 = 0;
		row_2 = 0;
		row_3 = 1;
		row_4 = 0;
		
		
		if(PORTD == 0X24)
		{  
			 lcd_cmd(0X80);
			 lcd_cmd(col_3 == 1);
			 lcd_data('2');
			 __delay_ms(100);
		}
		
		row_1 = 0;
		row_2 = 0;
		row_3 = 0;
		row_4 = 1;
		
		if(PORTD == 0X88)
		{  
			 
			 lcd_cmd(0X80);
			 lcd_cmd(col_4 == 1);
			 lcd_data('+');
			 __delay_ms(100);
	    }
			 
		row_1 = 0;
		row_2 = 0;
		row_3 = 0;
		row_4 = 1;
		
	    if(PORTD == 0X48)
		{  
			 lcd_cmd(0X01);
			 lcd_cmd(0X80);
			 lcd_cmd(col_4 == 1);
			 lcd_data('8');
			 __delay_ms(100);
		}
			 
		row_1 = 0;
		row_2 = 0;
		row_3 = 0;
		row_4 = 1;
		
  	    if(PORTD == 0X18)
		{  
			 lcd_cmd(0x01);                   // clear display
			 lcd_cmd(0X80);
			 lcd_cmd(col_4 == 1);
			 __delay_ms(100);
		}
	}
}	    