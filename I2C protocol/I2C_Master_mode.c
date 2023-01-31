/**************************************************************************/
/* Auther       : Murugan M                                               */
/* Date         : 26/1/2023                                               */
/* File name    : I2C inter integrater circuit                            */
/* Description  : master_mode for I2C                                     */
/**************************************************************************/








#include<htc.h>                       //Hi-tech c compiler. header file
#define __XTAL_FREQ 20000000          //crastal frequency 20MHZ 
__CONFIG(0X1F7A);                     //config with (FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);

void uart_print(unsigned char data);  //uart print data 

void delay();
void i2c_init(void);                  //first i2c initilized declare 
void i2c_wait(void);                  //declare wait condition
void i2c_start(void);                 //declare start condition
void i2c_stop(void);                  //declare stop condition
void i2c_write(unsigned char data);   //declare wait condition
void uart_init();                     //declare uart_initilized condition
void print(unsigned char *d);         //declare the print

void delay(void)
{
	TMR1CS = 0;                //Timer1 clock source select bit
	T1CKPS0 = 1;               //Set prescale value
	T1CKPS1 = 1;               //set prescale value
	TMR1H = 0X0B;              //Timer value Load MSB 100ms
	TMR1L = 0XDB;              //Timer value Load LSB 100ms
	TMR1ON = 1;                //Timer ON
	while(!TMR1IF);            //interrupt flage bit set
	TMR1IF = 0;                //Timer interrupt flage bit clear
	TMR1ON = 0;                //Timer stop
}
void i2c_init()
{
	SSPCON = 0X28;             //Serial port enable bit,I2C master mode,clock=FOSC/(4*(SSPADD+1))
	SSPCON2 = 0X00;            //All bit are clear
	SSPSTAT = 0X00;            //All bit are clear
	SSPADD  = 0X3F;            //Slave device address

}
void i2c_wait(void)
{
	while(SSPCON2 & 0X1F || SSPSTAT & 0X04);  //MSSP control register and MSSP status Register
}
void i2c_start(void)
{
	i2c_wait();
	SEN = 1;                   //Start condition enable bit
}
void i2c_stop(void)
{
	i2c_wait();
	PEN = 1;                   //Stop condition Enable bit
}
void i2c_write(unsigned char data)
{
	i2c_wait();
	SSPBUF = data;             //value load in to buffer register
}
void uart_init()
{
    TRISC6 = 0;                //low 25 pin RC6/TX/DT
    TRISC7 = 1;                //HIGH 26 pin RC7/RX/CK
    TXSTA  = 0X20;             //bit 5 	TXEN = 1 
    RCSTA  = 0X90;             //bit 7 SPEN = 1 Serial port enable,CREN = 1 continous receive enable bit 
    SPBRG  = 31;               //SPBRG Serial port baud rate generator register (Address 99h) 
    TXIF = 0;
    RCIF = 0;
}
void uart_print(unsigned char data)
{
			TXREG = data;             //transmit data
			while(TXIF == 0);         //transmit buffer
			TXIF = 0;
}
    
int main()
{
	uart_init();               
	delay();                            //first delay set 
	print("usart initilized....\r\n");  //uart print
	i2c_init();                         //user value initiliase
	i2c_start();                        //start
	i2c_write(0X78);                    //this your address and data
	i2c_stop();                         //stop
    while(1);
}
void print(unsigned char *d)
{
	while(*d)
	{
		uart_print(*d++);               //pirnt uart character
	}
}
