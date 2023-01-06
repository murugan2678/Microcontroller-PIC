/**************************************************************************/
/* Auther       : Murugan M                                               */
/* Date         : 3/1/2023                                                */
/* File name    : usart receiver traffic led                              */
/* Description  : universal synchronous asynchronous receiver transmitter */
/**************************************************************************/









#include<htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x1F7A);

#define RS RD5                        //Register select pin
#define RW RD6                        //Read and Write pin
#define EN RD7                        //Enable pin

void lcd_cmd(unsigned char cmd)       //unsigned means + value only print
{
	RS = 0;                           //Register select this cmd 0 off
	RW = 0;                           //Read and Write this cmd 0 off
	EN = 1;                           //Enable on
	PORTB = cmd;                      //portb lcd command set function
	__delay_ms(100);
	EN = 0;                           //Enable off
}
void lcd_data(unsigned char data)     //unsigned means + value only print
{
	RS = 1;                           //Register select this data 1 means on
	RW = 0;                           //Read and Write this data 0 off
	EN = 1;                           //Enable on 
	PORTB = data;                     //portb lcd data going for lcd
	__delay_ms(100);
	EN = 0;                           //Enable off
}
void uart_init()                      
{                    
    TRISA0 = 0;                       //TRISA0 led enable     TRIS means try state = input and output special function             
    TRISA1 = 0;                       //TRISA1 led enable
    TRISA2 = 0;                       //TRISA2 led enable
	TRISC7 = 1;                       //TRISC7 HIGH 26 pin RCT/RX/CK
	RCSTA = 0X90;                     //SPEN = 1 Serial port enable,CREN = 1 continous receive enable bit 
	SPBRG = 31;	                      //SPBRG Serial port baud rate generator register (Address 99h) 
    TXIF = 0;
    RCIF = 0;
}    

int main()                            //main function
{
 	  
    TRISA0 = 0;      
    TRISA1 = 0;
    TRISA2 = 0;
    TRISC = 0X00;                     //TRISC 8 pin enable
    TRISB = 0X00;                     //TRISB 8 pin enable
    TRISD = 0X00;                     //TRISD 8 pin enable
 
    unsigned char R,Y,G;              //declared unsigned character means + value TRAFFIC LED
    unsigned char data;               //declared unsigned character data
    uart_init();                      //uart init function declared for lcd
	lcd_cmd(0X38);                    //init 5X8-2 line RET HOME
	lcd_cmd(0X0F);                    //display on,en_cursor,en_blink
	lcd_cmd(0X0C);                    //display on,en_cursor,en_blink
	lcd_cmd(0X02);                    //Return to home
	lcd_cmd(0X06);                    //set DDRACM
	lcd_cmd(0X80);                    
    __delay_ms(100);
    lcd_cmd(0X01);                    //clear disply
   
  while(1)
   { 
        while(RCIF == 0);             //set receiver inter flag
        RA0 = 0;                      //led off 
        data = RCREG;                 //data receiver register
        lcd_data(data);               //lcd data priniting charater
        RA0 = 1;                      //led on red colour
        __delay_ms(500);

        while(RCIF == 0);             //set receiver inter flag
        RA1 = 0;                      
        data = RCREG;
        lcd_data(data);               //lcd data priniting charater
        RA1 = 1;                      //led on yellow colour
        __delay_ms(500);
  
        while(RCIF == 0);             //set receiver inter flag
        RA2 = 0;
        data = RCREG;
        lcd_data(data);               //lcd data priniting charater
        RA2 = 1;                      //led on green colour
        __delay_ms(500);

        while(RCIF == 0);
        data = RCREG;               
        lcd_data(data);               
        __delay_ms(500);
   }
}

