/***************************************************************/
/* Author          : Murugan M                                 */
/* Date            : 3/11/2022                                 */
/* File name       : lcd_CGRAM_character drogan jumping         */
/* Description     : using while and for loop                  */
/***************************************************************/













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
	int i,j;

  unsigned char obj[8]   = {0X06,0X05,0X16,0X16,0X1A,0X0C,0X0C,0X0C};
 
	TRISD  = 0;           //8bit to communicate LCD DB0-DB7
	TRISC0 = 0;           //RS PIN
	TRISC1 = 0;           //RW PIN
	TRISC2 = 0;           //EN PIN
	TRISB1 = 1;
	RB1 = 1;
	
	PORTD = 0X00;
	
    lcd_cmd(0X38);        //init 5X8-2 line RET home
 // lcd_cmd(0X0F);        //display on, EN_cursor, EN_blink
    lcd_cmd(0X0C);        // display on, display_cursor, display_blink
	lcd_cmd(0X01);        //clear display
	lcd_cmd(0X02);        //return to home
	lcd_cmd(0X06);        //cursor ++
 //	lcd_cmd(0X80);        //set DDRAM
	
	
	
	  lcd_cmd(0X40);      //set CGRAM
	  __delay_ms(500); 
 
 

	  for(i=0; i<8; i++)
	    lcd_data(obj[i]);
          
        __delay_ms(500); 
        lcd_cmd(0XC0);    //set DDRAM second line lcd display
	      
	   
	  while(1)
	  {
		if(RB1 == 0)
		  {
			lcd_cmd(0X01);
			lcd_cmd(0XC0);
			__delay_ms(100);
			lcd_data(0);
		  	__delay_ms(100);
			
			lcd_cmd(0X01);
			lcd_cmd(0X81);
			__delay_ms(100);
			lcd_data(0);
		  	__delay_ms(100);
		  	
		  	lcd_cmd(0X01);
			lcd_cmd(0XC2);
			__delay_ms(100);
		  	lcd_data(0);
			__delay_ms(100);
			  
			lcd_cmd(0X01);
			lcd_cmd(0X83);
			__delay_ms(100);
			lcd_data(0);
		  	__delay_ms(100);
		  	
		  	lcd_cmd(0X01);
			lcd_cmd(0XC4);
			__delay_ms(100);
			lcd_data(0);
		  	__delay_ms(100);
		  	
		  	lcd_cmd(0X01);
			lcd_cmd(0X85);
			__delay_ms(100);
			lcd_data(0);
		  	__delay_ms(100);
		     
		    lcd_cmd(0X01);
			lcd_cmd(0XC6);
			__delay_ms(100);
			lcd_data(0);
		  	__delay_ms(100); 
		  	
		  	lcd_cmd(0X01);
			lcd_cmd(0X87);
			__delay_ms(100);
			lcd_data(0);
		  	__delay_ms(100);
		  	
		  	lcd_cmd(0X01);
			lcd_cmd(0XC8);
			__delay_ms(100);
			lcd_data(0);
		  	__delay_ms(100);
		  	
		  	lcd_cmd(0X01);
			lcd_cmd(0X89);
			__delay_ms(100);
			lcd_data(0);
		  	__delay_ms(100);
		  	
		  	lcd_cmd(0X01);
			lcd_cmd(0XCA);
			__delay_ms(100);
			lcd_data(0);
		  	__delay_ms(100);
		  	
		  	lcd_cmd(0X01);
			lcd_cmd(0X8B);
			__delay_ms(100);
			lcd_data(0);
		  	__delay_ms(100);
		  	
		  	lcd_cmd(0X01);
			lcd_cmd(0XCC);
			__delay_ms(100);
			lcd_data(0);
		  	__delay_ms(100);
		  	
		  	lcd_cmd(0X01);
			lcd_cmd(0X8D);
			__delay_ms(100);
			lcd_data(0);
		  	__delay_ms(100);
		  	
		  	lcd_cmd(0X01);
			lcd_cmd(0XCE);
			__delay_ms(100);
			lcd_data(0);
		  	__delay_ms(100);
		  	
		  	lcd_cmd(0X01);
			lcd_cmd(0X8F);
			__delay_ms(100);
			lcd_data(0);
		  	__delay_ms(100);
		  }
	  } 
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