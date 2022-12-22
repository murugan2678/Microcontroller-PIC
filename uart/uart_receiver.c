/*********************************************************************/
/* Auther       : Murugan M                                   	     */
/* Date         : 20/12/2022                                 	     */
/* File name    : uart universal asynchronous recevier transmitter   */
/* Description  : recevier only from lcd                             */
/*********************************************************************/








#include<htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(0X1F7A);
#define RS RD5
#define RW RD6
#define EN RD7

void lcd_cmd(unsigned char cmd);
void lcd_disp(unsigned char data);

void uart_init(void);
void lcd_init();

void lcd_cmd(unsigned char cmd)
{
	RS = 0;
	RW = 0;
	EN = 1;
	PORTB = cmd;
	__delay_ms(50);
	EN = 0;
	__delay_ms(50);
}
void lcd_disp(unsigned char data)
{
	RS = 1;
	RW = 0;
	EN = 1;
	PORTB = data;
	__delay_ms(50);
	EN = 0;
	__delay_ms(50);
}
void uart_init()
{
	TRISC6 = 0;              //low 26 pin RC7/RX/DT
	TRISC7 = 1;              //High 25 pin RC6/TX/CK
	TXSTA = 0X20;            //b5 TXEN = 1;
	RCSTA = 0X90;            //b7 SPEN = 1,b4 CREN = 1
	SPBRG = 31;              //SPBRG serial port baud rate generator register (Address 99h)
	TXIF = 0;
	RCIF = 0;
}
void lcd_init()
{
	TRISB =0X00;             //port-B is used as output port
	TRISD5 = 0;              //port-D pin #5 as output pin
	TRISD6 = 0;              //port-D pin #6 as output pin
	TRISD7 = 0;              //port-D pin #7 as output pin
	__delay_ms(50);  
	lcd_cmd(0X38);           //init 5X8-2 lin RETURN Home
	lcd_cmd(0X0F);		 //display on,en_cursor,en_blink
	lcd_cmd(0X0C);           //display on,en_cursor,en_blink
	lcd_cmd(0X02);           //Return to Home
	lcd_cmd(0X06);           //cursor++
	lcd_cmd(0X80);           //set DDRAM
	__delay_ms(50);
	lcd_cmd(0X01);		 //clear display
}
void main()
{
	unsigned char Rdata;
	lcd_init();
	uart_init();
	while(1)
	{
		while(RCIF == 0);     //poll if RCIF is Empty
		Rdata = RCREG;        //copy data from RCREG register to RData char variable
		lcd_disp(Rdata);      //Display receive data on lcd
	}
}	
