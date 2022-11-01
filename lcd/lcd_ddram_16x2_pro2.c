/***********************************************************/
/* Auther       : Murugan M                                */
/* Date         : 26/10/2022                               */
/* File name    : lcd_ddram_16x2 first line second line    */
/* Description  : Using DDRAM address and timer 1          */
/***********************************************************/














#include <htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_OFF & LVP_OFF);


#define RS RC0
#define RW RC1
#define EN RC2

void delay();
void lcd_cmd(unsigned char cmd);          
void lcd_data(unsigned char data);

int main()
{
	TRISD = 0;            //8bit to communicate LCD DB0-DB7
	TRISC0 = 0;           //RS PIN
	TRISC1 = 0;           //RW PIN
	TRISC2 = 0;           //EN PIN
	PORTD = 0X00;


	
  lcd_cmd(0X38);          //init 5X8-2 line RET home
	lcd_cmd(0X0F);        //display on, EN_cursor, EN_blink
   	lcd_cmd(0X01);        //clear display
	lcd_cmd(0X02);        //return to home
	lcd_cmd(0X06);        //cursor ++
	
	lcd_cmd(0X80);        //set DDRAM  first line display
 
		
	lcd_data('U');
	delay();
	lcd_data('N');
	delay();
	lcd_data('I');
	delay();
	lcd_data('X');
	
	lcd_data(' ');
	delay();
	
	lcd_data('i');
	delay();
	lcd_data('s');
	delay();
	
	lcd_data(' ');
	delay();
	
	lcd_data('s');
	delay();
	lcd_data('i');
	delay();
	lcd_data('m');
	delay();
	lcd_data('p');
	delay();
	lcd_data('l');
	delay();
	lcd_data('e');
	delay();
	

	lcd_cmd(0XC0);           //second line display 
	
	lcd_data(' ');
	delay();
	lcd_data(' ');
	delay(); 
	
	lcd_data('i');
	delay();
	lcd_data('t');
	delay();
	
	lcd_data(' ');
	delay();
	
	lcd_data('j');
	delay();
	lcd_data('u');
	delay();
	lcd_data('s');
	delay();
	lcd_data('t');
	delay();
	
	lcd_data(' ');
	delay();
	
	lcd_data('t');
	delay();
	lcd_data('a');
	delay();
	lcd_data('k');
	delay();
	lcd_data('e');
	delay();
	lcd_data('s');
	delay();
	lcd_cmd(0X1C);              //shifting left to right
	lcd_cmd(0X1C); 
	lcd_cmd(0X1C); 
	lcd_cmd(0X1C); 
	lcd_cmd(0X1C); 
	lcd_cmd(0X1C); 
	lcd_cmd(0X1C); 
	lcd_cmd(0X1C); 

	lcd_cmd(0X01);              //clear display
	delay();
	lcd_cmd(0X80);              //first line display
	delay();
	
	lcd_data(' ');
	delay();
	lcd_data(' ');
	delay();
    lcd_data(' ');
	delay();
    
    lcd_data('a');
	delay();
	
	lcd_data(' ');
	delay();
	
	lcd_data('g');
	delay();
	lcd_data('e');
	delay();
	lcd_data('n');
	delay();
	lcd_data('i');
	delay();
	lcd_data('u');
	delay();
	lcd_data('s');
	delay();
	
	lcd_data(' ');
	delay();
	
	lcd_data('t');
	delay();
	lcd_data('o');
	delay();
	
	
	lcd_cmd(0XC0);
	delay();
	lcd_data(' ');
	delay();
	lcd_data(' ');
	delay();
	lcd_data(' ');
	delay();
	lcd_data('u');
	delay();
	lcd_data('n');
	delay();
	lcd_data('d');
	delay();
	lcd_data('e');
	delay();
	lcd_data('r');
	delay();
	lcd_data('s');
	delay();
	lcd_data('t');
	delay();
	lcd_data('a');
	delay();
	lcd_data('n');
	delay();
	lcd_data('d');
	delay();
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

	
	lcd_cmd(0X01);
	delay();
	lcd_cmd(0X80);
	delay();
	
	lcd_data(' ');
	delay();
	lcd_data('i');
	delay();
	lcd_data('t');
	delay();
	lcd_data('s');
	delay();
	
	lcd_data(' ');
	
	lcd_data('s');
	delay();
	lcd_data('i');
	delay();
	lcd_data('m');
	delay();
	lcd_data('p');
	delay();
	lcd_data('l');
	delay();
	lcd_data('i');
	delay();
	lcd_data('c');
	delay();
	lcd_data('i');
	delay();
	lcd_data('t');
	delay();
	lcd_data('y');
	delay();
	
	lcd_cmd(0XC0);
	delay();
	
	lcd_data('D');
	delay();
	lcd_data('e');
	delay();
	lcd_data('n');
	delay();
	lcd_data('n');
	delay();
	lcd_data('i');
	delay();
	lcd_data('s');
	delay();
	
	lcd_data(' ');
	delay();
	
	lcd_data('R');
	delay();
	lcd_data('i');
	delay();
	lcd_data('t');
	delay();
	lcd_data('c');
	delay();
	lcd_data('h');
	delay();
	lcd_data('i');
	delay();
	lcd_data('e');
	delay();
	lcd_cmd(0X1C); 
	lcd_cmd(0X1C); 
	lcd_cmd(0X1C); 
	lcd_cmd(0X1C); 
	lcd_cmd(0X1C); 
	lcd_cmd(0X1C); 
	lcd_cmd(0X1C); 
	lcd_cmd(0X1C); 
	
	
	lcd_cmd(0X01);
	delay();
	lcd_cmd(0X80);
	delay();
	lcd_data(' ');
	delay();
	lcd_data(' ');
	delay();
	

	
	lcd_data('C');
	delay();
	
	lcd_data(' ');
	delay();
	
	lcd_data('P');
	delay();
	lcd_data('r');
	delay();
	lcd_data('o');
	delay();
	lcd_data('g');
	delay();
	lcd_data('r');
	delay();
	lcd_data('a');
	delay();
	lcd_data('m');
	delay();
	lcd_data('m');
	delay();
	lcd_data('i');
	delay();
	lcd_data('n');
	delay();
	lcd_data('g');
	delay();
	
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
	PORTD = cmd;
	delay();
	EN = 0;
}
void lcd_data(unsigned char data)
{
	RS = 1;
	RW = 0;
	EN = 1;
	PORTD = data;
	delay();
	EN = 0;
}

	
	