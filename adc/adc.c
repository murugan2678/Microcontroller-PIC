// ADC program for PIC16F877A

#include <htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x1f7a);

void port_config(void);
void adc_connfig(void);
unsigned int adc_read(void);
void uart_tx_config(void);
void uart_tx(unsigned char data);

void port_config(void)
{
	// PORTC 6th pin for uart tx pin, select 0 for output mode set
	TRISC6 = 0;
	
	// PORTA 0th pin for analog pin, select 1 for input mode set
	TRISA0 = 1;
}
void adc_config(void)
{	
	// (ADCON1) register
	// step1 : A/D port configuration control bits
	PCFG0 = 0;
	PCFG1 = 0;
	PCFG2 = 0;
	PCFG3 = 0;
	
	// step2 : A/D result format select bit, (ADCON1)
	// 1 = Right justified. six(6) most significant bits of ADRESH are read as '0'  
	ADFM  = 1;  
	
	// (ADCON0) register
	// step3 : analog channel select bits, 0th channel select
	CHS0 = 0;
	CHS1 = 0;
	CHS2 = 0;
	
	// step4 : A/D conversion clock select bit, (ADCON0)register
	ADCS0 = 1;
	ADCS1 = 0;
	ADCS2 = 0;	
		
	// A/D on bit, turn on A/D module, (ADCON0)register
	ADON = 1;	
} 

unsigned int adc_read(void)
{		
	// wait the required aquistion time.
	__delay_ms(30);
	
	// A/D conversion status bit, set GO/DONE bit (ADCON0).
	GO_DONE = 1;
	
	// wait for A/D conversion to complete by either.
	// polling for the GO/DONE bit to be cleared (interrupts disabled).
	while(GO_DONE == 0);
	
	// read A/D result register pair (ADRESH : ADRESL). clear bit ADIF if required.
	return ((ADRESH<<8)| ADRESL);
	
	// celar bit ADIF if required.
 	ADIF = 0;	
}

void uart_tx_config(void)
{
	// port c select for TX transmission, TXC6 6th pin output set
	TRISC6 = 0;
	
	// Baud rate value set.
	SPBRG = 31;
	
	// Enable the asynchronous serial port by clearing bit SYNC and setting bit SPEN.
	// SPEN serial port enable bit (configures RC7/RX/DT and RC6/TX/CK) pins as serial port pins).
	SPEN = 1;
	
	// enable the transmission by setting bit TXEN,
	TXEN = 1;
	
	// if interrupts are desired, then set enable bit TXIE.
	TXIE = 0;
	
	// which will also set bit TXIF.
	TXIF = 0;
}

void uart_tx(unsigned char data)
{	   
	// load data to the TXREG register (starts transmission).
    TXREG = data;
	
	// interrupt set 
	while(TXIF == 0);
	
	// clear interrupt
	TXIF = 0;
}

int main()
{	
	port_config();
	uart_tx_config(); // here function call from uart_tx_config.
	adc_config();     // function call from adc_config.

	__delay_ms(50); // some delay given.
	while(1)
	{
		unsigned int data = adc_read(); // here adc_read function pass to data.
		for(int i=0; i<8; i++)  // character for 1byte 8-bit data send 0 to 7. 
	    {
		    if(data & 1<<i)     // data check from 1<<i left shift use one by one shifting.
			{
	 		   uart_tx('1'); // In joystick x axis move in up means 11111111 for high signal.
		    }
		    else
		    {
			   uart_tx('0'); // In joystick x axis move in slow down means 00000000 for low signal.
		    }
		}
        uart_tx('\r'); // carriage return in cursor get next line
        uart_tx('\n'); // new line
        __delay_ms(500);
    }   
}


/* void adc_config(void)
{
	// TRIS --> try state input and output.
	// TRISA0 --> PORTA 0th pin set input mode. 
	TRISA0 = 1;
	
	// select A/D conversion clock (ADCON0). 6th bit and 7th bit 
    // i select for 01 FOSC/8. frequency divided by 8 bit. 
	// turn on A/D module (ADCON0). ADON 0th bit select 1. 
	// 1 for A/D convert module is powered up.
	ADCON0 = 0x41; //41;
	
	// 7th bit --> ADFM : A/D result format select bit.
	// 1 = right justified six 6 most significant bits for ADRESH are read as 0.
	// 7th bit set 1.
	// 6th bit --> A/D conversion clock select bit
	ADCON1 = 0xC0;    //C0; or 80;
} */