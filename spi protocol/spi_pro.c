/********************************************************************/
/* Auther       : Murugan M                                         */
/* Date         : 1/3/2023                                          */
/* File name    : SPI serial peripheral interface protocol          */
/* Description  : SSPSTAT status register, SSPCON1 control register */
/********************************************************************/







#include<htc.h>               //hi-tech c compiler .h header file
#include<stdio.h>             //standard input output .h header file
#define _XTAL_FREQ 20000000   //frequency 20MHZ
__CONFIG(0X1F7A);             //configuration 

#define ss RA5
void spi_init(void);
unsigned char spi_trans(unsigned char);
void delay(void);

int main()
{
	spi_init();
	ss = 1;
	__delay_ms(10);
	ss = 0;
	spi_trans(0X06); //set the write enable data
	ss = 1;
	ss = 0;
	spi_trans(0X02); //write data to memory array begining
	spi_trans(0X00); //select 16 bit address first
	spi_trans(0X08); //select 16 bit address second
	spi_trans('M');
	spi_trans('S');
	ss = 1;
	while(1);
}
void spi_init()
{ 
	TRISC3 = 0;      //SCK serial clock-RC3/SCK/SCL
	TRISC4 = 1;      //SDI serial data in-RC4/SDI/SDA 
	TRISC5 = 0;      //SDO serial data out-RC5/RD0
	TRISC1 = 0;
        TRISA5 = 0;      //slave select
	SSPCON = 0X10;   //clock polarity select bit
	SSPSTAT = 0X00;
	SSPIE = 0;
	SSPIF = 0;
	SSPBUF = 0;
	SSPEN = 1;       //synchrnonous serial port enable bit
}
unsigned char spi_trans(unsigned char data)
{
	SSPBUF = data;      //set buffer
	while(SSPIF == 0);  //interrupt flag set
	SSPIF = 0;
}

	
	
