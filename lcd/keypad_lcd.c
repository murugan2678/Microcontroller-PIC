/*************************************************************/
/* Auther       : Murugan M                                  */
/* Date         : 5/11/2022                                  */
/* File name    : keypad_display num for lcd                 */
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
      
      
      lcd_cmd(0X38);                   // init 5X8-2 line RET home
      lcd_cmd(0X0D);                   // display on, display_cursor, display_blink
      lcd_cmd(0X01);                   // clear display
      lcd_cmd(0X02);                   // return to home
      lcd_cmd(0X06);                   // cursor ++
      
      lcd_cmd(0X40);                   // set CGRAM
     
      lcd_data('0');                   // set data
      lcd_data('1');
      lcd_data('2');
      lcd_data('3');
      lcd_data('4');
      lcd_data('5');
      lcd_data('6');
      lcd_data('7');
      lcd_data('8');
      lcd_data('9');
      lcd_data('A');
      lcd_data('B');
      lcd_data('C');
      lcd_data('D');
      lcd_data('E');
      lcd_data('F');
      
      
	while(1)
	{
	    row_1 = 1;
		row_2 = 0;
		row_3 = 0;
		row_4 = 0;
		
		
		if(PORTD == 0X11)
		{  
			 lcd_cmd(0X01);                     // clear display
			 lcd_cmd(0X80);                     // set DDRAM first line lcd display first print
			 lcd_cmd(col_1 == 1);               // column
			 lcd_data('0');                     // set data 
			 __delay_ms(100);
		}
		if(PORTD == 0X21)
		{  
			 lcd_cmd(0X01);                     // clear display
			 lcd_cmd(0X81);                     // set DDRAM first line lcd display for second print 
			 lcd_cmd(col_1 == 1);               // column
			 lcd_data('1');                     // set data
			 __delay_ms(100);
		}
		if(PORTD == 0X41)
		{  
			 lcd_cmd(0X01);
			 lcd_cmd(0X82);
			 lcd_cmd(col_1 == 1);
			 lcd_data('2');
			 __delay_ms(100);
		}
		if(PORTD == 0X81)
		{  
			 lcd_cmd(0X01);
			 lcd_cmd(0X83);
			 lcd_cmd(col_1 == 1);
			 lcd_data('3');
			 __delay_ms(100);
		}
		
		row_1 = 0;
        row_2 = 1;
        row_3 = 0;
        row_4 = 0;
		
		if(PORTD == 0X12)
		{  
			 lcd_cmd(0X01);
			 lcd_cmd(0X84);
			 lcd_cmd(col_2 == 1);
			 lcd_data('4');
			 __delay_ms(100);
		}
		if(PORTD == 0X22)
		{  
			 lcd_cmd(0X01);
			 lcd_cmd(0X85);
			 lcd_cmd(col_2 == 1);
			 lcd_data('5');
			 __delay_ms(100);
		}
		if(PORTD == 0X42)
		{  
			 lcd_cmd(0X01);
			 lcd_cmd(0X86);
			 lcd_cmd(col_2 == 1);
			 lcd_data('6');
			 __delay_ms(100);
		}
		if(PORTD == 0X82)
		{  
			 lcd_cmd(0X01);
			 lcd_cmd(0X87);
			 lcd_cmd(col_2 == 1);
			 lcd_data('7');
			 __delay_ms(100);
		}
		
		row_1 = 0;
		row_2 = 0;
		row_3 = 1;
		row_4 = 0;
		
			if(PORTD == 0X14)
		{  
			 lcd_cmd(0X01);
			 lcd_cmd(0X88);
			 lcd_cmd(col_3 == 1);
			 lcd_data('8');
			 __delay_ms(100);
		}
		if(PORTD == 0X24)
		{  
			 lcd_cmd(0X01);
			 lcd_cmd(0X89);
			 lcd_cmd(col_3 == 1);
			 lcd_data('9');
			 __delay_ms(100);
		}
		if(PORTD == 0X44)
		{  
			 lcd_cmd(0X01);
			 lcd_cmd(0X8A);
			 lcd_cmd(col_3 == 1);
			 lcd_data('A');
			 __delay_ms(100);
		}
		if(PORTD == 0X84)
		{  
			 lcd_cmd(0X01);
			 lcd_cmd(0X8B);
			 lcd_cmd(col_3 == 1);
			 lcd_data('B');
			 __delay_ms(100);
		}
		
		row_1 = 0;
		row_2 = 0;
		row_3 = 0;
		row_4 = 1;
		
			if(PORTD == 0X18)
		{  
			 lcd_cmd(0X01);
			 lcd_cmd(0X8C);
			 lcd_cmd(col_4 == 1);
			 lcd_data('C');
			 __delay_ms(100);
		}
		if(PORTD == 0X28)
		{  
			 lcd_cmd(0X01);
			 lcd_cmd(0X8D);
			 lcd_cmd(col_4 == 1);
			 lcd_data('D');
			 __delay_ms(100);
		}
		if(PORTD == 0X48)
		{  
			 lcd_cmd(0X01);
			 lcd_cmd(0X8E);
			 lcd_cmd(col_4 == 1);
			 lcd_data('E');
			 __delay_ms(100);
		}
		if(PORTD == 0X88)
		{  
			 lcd_cmd(0X01);
			 lcd_cmd(0X8F);
			 lcd_cmd(col_2 == 1);
			 lcd_data('F');
			 __delay_ms(100);
		}
	}
}