/***************************************************************/
/* Author          : Murugan M                                 */
/* Date            : 4/11/2022                                 */
/* File name       : lcd_CGRAM_charger                         */
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
	int i;

  unsigned char obj[8]   = {0X0E,0X1B,0X11,0X11,0X11,0X11,0X1F,0X00};
  unsigned char obj1[8]  = {0X0E,0X1B,0X11,0X11,0X11,0X1F,0X1F,0X00};
  unsigned char obj2[8]  = {0X0E,0X1B,0X11,0X11,0X1F,0X1F,0X1F,0X00};
  unsigned char obj3[8]  = {0X0E,0X1B,0X11,0X1F,0X1F,0X1F,0X1F,0X00};
  unsigned char obj4[8]  = {0X0E,0X1B,0X1F,0X1F,0X1F,0X1F,0X1F,0X00};
 
	
	TRISD  = 0;           //8bit to communicate LCD DB0-DB7
	TRISC0 = 0;           //RS PIN
	TRISC1 = 0;           //RW PIN
	TRISC2 = 0;           //EN PIN
	TRISB1 = 1;
	RB1 = 1;
	
	PORTD = 0X00;
	
    lcd_cmd(0X38);        //init 5X8-2 line RET home
 //	lcd_cmd(0X0F);        //display on, EN_cursor, EN_blink
    lcd_cmd(0X0C); 
	  lcd_cmd(0X01);        //clear display
	  lcd_cmd(0X02);        //return to home
	  lcd_cmd(0X06);        //cursor ++
 // lcd_cmd(0X80);        //set DDRAM
	
	
	
	  lcd_cmd(0X40);        //set CGRAM 
	  __delay_ms(500); 
 
    for(i=0; i<8; i++)
	       lcd_data(obj[i]);
	 
	    
    for(i=0; i<8; i++)
	       lcd_data(obj1[i]);
	  
	  for(i=0; i<8; i++)
	       lcd_data(obj2[i]);
	       
	  for(i=0; i<8; i++)
	       lcd_data(obj3[i]); 
	       
	  for(i=0; i<8; i++)
	       lcd_data(obj4[i]);
	  
	  __delay_ms(500); 
    lcd_cmd(0XC0);
    			      
while(1)
	  {
		  if(RB1 == 0)
		  {
			  
			  lcd_cmd(0XC0);
			  __delay_ms(100);
			  lcd_data(0);
			  __delay_ms(100);
			
			  lcd_cmd(0XC0);
			  __delay_ms(100);
			  lcd_data(1);
			  __delay_ms(100);
			   
        lcd_cmd(0XC0);
			  __delay_ms(100);
			  lcd_data(2);
			  __delay_ms(100);
		  	
			  lcd_cmd(0XC0);
			  __delay_ms(100);
			  lcd_data(3);
			  
		  	__delay_ms(100);
		  	  
		  	lcd_cmd(0XC0);
			  __delay_ms(100);
			  lcd_data(4);
			  
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