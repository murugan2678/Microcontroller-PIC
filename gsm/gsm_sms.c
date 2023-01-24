
/**************************************************************************/
/* Auther       : Murugan M                                               */
/* Date         : 15/1/2023                                               */
/* File name    : gsm sms for message for another number                  */
/* Description  : gsm-global system for mobile communication using usart  */
/**************************************************************************/



















#include<htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x1f7a);

#define RS RD5                        //Register select pin
#define RW RD6                        //Read and Write pin
#define EN RD7                        //Enable pin

void lcd_cmd(unsigned char cmd);      //unsigned means + value only print
void lcd_data(unsigned char data);    //unsigned means + value only print
void uart_tx(unsigned char val);      //uart transmitter character value
unsigned char uart_rx(void);          //uart reciever 
void uart_init(void);                 //uart_initialization
void uart_init();
void config_init();
char AT[]="AT\r\n";                   //AT-Attension AT comments for gsm
char sms_mode[]="AT+CMGF=1\r\n";      //sms sending mode AT+CMGF=1, \r\n - this means for new line enter
char mobile_number[]="AT+CMGS=\"9487855450\"\r\n";   //send new sms this mobile number
char set_msg[]="hi\032\r\n";          //set msg for hi ,032 this value for ASCII table 032 this vaule is octal number 
                                      //character Z means ctrl+Z this command automatic generator
char call_number[]="ATD9487855450;\r\n";


void lcd_cmd(unsigned char cmd)       //unsigned means + value only print    
{
	RS = 0;                           //Register select this cmd 0 off
	RW = 0;                           //Read and write this cmd 0 off
	EN = 1;                           //Enable off
	PORTB = cmd;                      //portable lcd command set function
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
}
void lcd_init()
{
	TRISB  = 0X00;                    //TRISB 8 pin enable send data
	TRISD5= 0;                        //TRISD5 pin enable send data
	TRISD6= 0;                        //TRISD6 pin enable send data   
	TRISD7= 0;                        //TRISD7 pin enable send data
	
	lcd_cmd(0X38);                    //init 5X8-2 line RET HOME
	lcd_cmd(0X0F);                    //display on,en_cursor,en_blink
	lcd_cmd(0X0C);                    //display on,en_cursor,en_blink
	lcd_cmd(0X02);                    //Ret to home
	lcd_cmd(0X06);                    //cursor ++
	lcd_cmd(0X80);                    //set DDRAM
	__delay_ms(100);
	lcd_cmd(0X01);                    //clear display
}
void uart_init()
{
	TRISC6 = 0;                       //Low 25 pin RC6/TX/DT   TX-transmitter DT-data
	TRISC7 = 1;                       //HIGH 26 pin RC7/RX/CK  RX-receiver CK-clock wise
	TXSTA  = 0X20;                    //data bit 5 TXEN = 1   data bit 5 enable for transmitter
	RCSTA  = 0X90;                    //data bit 7 SPEN = 1 bit 4 CREN =1   data bit 7 and 4 enable SPEN=1 serial port enable CREN = 1 continous receiver enable bit 
	SPBRG  = 31;                      //SPBRG serial port baud rate generator register(address 99h)
	TXIF = 0;                         //TXIF transmitter inter flag set
	RCIF = 0;                         //RCIF receiver inter flag set
}
void uart_tx(unsigned char val)       //transmitter unsigned means + value only print
{
    TXREG = val;                      //transmitter register
    while(TXIF == 0);                 //transmitter buffer TXIF = 0
    TXIF = 0;                         //transmit IF means inter flag set
}
unsigned char uart_rx(void)           //receiver unsigned means + value only print
{
    while(RCIF == 0);                 //poll is RCIF is empty RCIF-receiver inter flag
    RCIF = 0;                         
    return RCREG;                     //RCREG - receiver register
}
void uart_print(unsigned char *str)   //sring using char *strstr(const char *haystack, const char *needle)
{
    while(*str)                      
    {
       uart_tx(*str++);               //functions first occurence of the substring needle in the string haystack
    }                                 //the terminating 0 characters are not compared
}
/*void lcd_print(unsigned char *str)  //lcd data print
{
    while(*str)
    {
       lcd_init(*str++);
    }
}*/
int main()
{
    lcd_init();
    uart_init();
	{
		uart_print(AT);               //attension first start
        __delay_ms(1000);     

        uart_print(sms_mode);         //sms sending mode AT+CMGF=1, \r\n - this means for new line enter
        __delay_ms(1000);

        uart_print("AT+CMGS=\"6384419563\"\r\n");   //send new sms this mobile number
        __delay_ms(1000);
       
        uart_print("hi\032\r\n");     //set msg for hi ,032 this value for ASCII table 032 this vaule is octal number
        __delay_ms(3000);             //character Z means ctrl+Z this command automatic generator
		
       // uart_print(call_number);
       // __delay_ms(3000);    
        
    while(1);
	}
   
   
}