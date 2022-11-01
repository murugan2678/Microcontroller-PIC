
/***************************************************************/
/* Author          : Murugan M                                 */
/* Date            : 21/9/2022                                 */
/* File name       : lcd_ddram_tim hours                       */
/* Description     : using while and for loop                  */
/***************************************************************/









#include <htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_OFF & LVP_OFF);


#define RS RD0
#define RW RD1
#define EN RD2

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
	__delay_ms(2);
	EN = 0;
}
void lcd_data(unsigned char data)
{
	RS = 1;
	RW = 0;
	EN = 1;
	PORTC = data;
	__delay_ms(2);
	EN = 0;
}

int main()
{
    TRISD0 = 0;
    TRISD1 = 0;
    TRISD2 = 0;
    TRISC = 0;
    PORTC = 0X00;


    int i,j,l,m,k,p,r,s,t;
    lcd_cmd(0X38);
    lcd_cmd(0X0C);
    lcd_cmd(0X01);
    lcd_cmd(0X02);
    lcd_cmd(0X06);
    lcd_cmd(0X80);

    while(1)
    {

	  for(i=0; i<6; i++)
	    {
		    lcd_cmd(0X80);                     // first line ddram address 80 for 1st cross 16x2
		  	lcd_data(i+0X30);                  //0 means 0x30 means 0 
		  	__delay_ms(1);
		
	  for(j=0; j<10; j++)
	   	{
			  lcd_cmd(0X81);                  //first line ddram address 81 for 1st cross 16x2
		  	lcd_data(j+0X30);
			  __delay_ms(1);
			  lcd_cmd(0X82);                  //first line ddram address 82 for 1st cross 16x2
	    	lcd_data(':');                    //data declare
	
	  
	  for(l=0; l<6; l++)
		  {
			  lcd_cmd(0X83);
				lcd_data(l+0X30);
				__delay_ms(1);
		
   	for(m=0; m<10; m++)
			{
		 		lcd_cmd(0X84);
		 		lcd_data(m+0X30);
				 __delay_ms(1);
		 		lcd_cmd(0X85);
		 		lcd_data(':');
		
	  for(p=0; p<6; p++)
			{
				lcd_cmd(0X86);
		 		lcd_data(p+0X30);
		 		__delay_ms(1);
			
    for(r=0; r<10; r++)
			{
		        lcd_cmd(0X87);
		 		lcd_data(r+0X30);
		 		__delay_ms(1);
				lcd_cmd(0X88);
				lcd_data(':');
		
	  for(s=0; s<6; s++)
			{
		 	 	lcd_cmd(0X89);
		  	    lcd_data(s+0X30);
		  	    __delay_ms(1);
			
	  for(t=0; t<10; t++)
			{
		 		lcd_cmd(0X8A);
		  	    lcd_data(t+0X30);
				__delay_ms(1);
			
		  	    lcd_cmd(0X8B);
		  	    lcd_data('A');
		  	    lcd_cmd(0X8C);
		  	    lcd_data('M');
		 	}
		 }  
	    }
	   }
	  }
     }
    }
   }
 }
} 
