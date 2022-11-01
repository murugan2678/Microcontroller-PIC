/********************************************************/
/* Auther       : Murugan M                             */
/* Date         : 26/10/2022                            */
/* File name    : lcd_ddram_16x2                        */
/* Description  : Using DDRAM address and timer 1       */
/********************************************************/












#include <htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_OFF & LVP_OFF);


#define RS RD0
#define RW RD1
#define EN RD2

void delay();
void lcd_cmd(unsigned char cmd);                //cmd means 0
void lcd_data(unsigned char data);              //data means 1

int main()
{
	TRISC = 0;               //8bit to communicate LCD DB0-DB7 
	TRISD0 = 0;              //RS PIN
	TRISD1 = 0;              //RW PIN
	TRISD2 = 0;              //EN PIN
	PORTC = 0X00;
	
	  	
    lcd_cmd(0X38);         //init 5X8-2 line RET home
	lcd_cmd(0X0F);           //display on, EN_cursor, EN_blink
	lcd_cmd(0X01);           //clear display
	lcd_cmd(0X02);           //return to home
	lcd_cmd(0X06);           //cursor ++
	
  lcd_cmd(0X80);           //set DDRAM first line display
 
		
	lcd_data('L');
	delay();

	lcd_data('I');
	delay();
	
	lcd_data('N');
	delay();

	lcd_data('U');
	delay();

	lcd_data('S');
	delay();
	
	lcd_data(' ');
	delay();

	lcd_data('T');
	delay();
	
	lcd_data('O');
	delay();
	
	lcd_data('R');
	delay();
	
	lcd_data('V');
	delay();

	lcd_data('A');
	delay();

	lcd_data('L');
	delay();
	
	lcd_data('D');
	delay();
	
	lcd_data('S');
	delay();
	
	

  lcd_cmd(0xc0);           //second line c0 display
  
  lcd_data('C');
	delay();
	
	lcd_data('R');
	delay();
	
	lcd_data('E');
	delay();
	
	lcd_data('A');
	delay();
	
	lcd_data('T');
	delay();
	
	lcd_data('O');
	delay();
	
	lcd_data('R');
	delay();
	
	lcd_data(' ');
	delay();
	
	lcd_data('O');
	delay();
	
	lcd_data('F');
	delay();
	
	lcd_data(' ');
	delay();
	
	lcd_data('L');
	delay();
	
	lcd_data('I');
	delay();
	
	lcd_data('N');
	delay();
	
	lcd_data('U');
	delay(); 
	
	lcd_data('X');
	delay();
	
	lcd_cmd(0X1C);             //shifting left to right
	lcd_cmd(0x1C);
	lcd_cmd(0x1C);
	lcd_cmd(0X1C);
	lcd_cmd(0X1C);
	lcd_cmd(0X1C);
	lcd_cmd(0X1C);
	lcd_cmd(0X1C);
	lcd_cmd(0X1C);
	lcd_cmd(0X1C);
	lcd_cmd(0X1C);
	lcd_cmd(0X1C);
	lcd_cmd(0X1C);
	lcd_cmd(0X1C);
	lcd_cmd(0X1C);
	lcd_cmd(0X1C);
	
	while(1);
}

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