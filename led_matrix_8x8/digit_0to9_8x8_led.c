/******************************************************************************/
/* Auther       : Murugan M                                                   */
/* Date         : 6/9/2023                                                    */
/* File name    : led_matrix 8x8, printing digit 0to9                         */
/* Description  : Using array and for loop and void function                  */
/******************************************************************************/


#include <htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x1f7a);

void digit_print(char digit[8],int sec);  // declare the function void digit_print(char digit[8],int sec) sec means mile seconds set 

// digit 0to9 
char digit0[8]={0X3E,0X22,0X22,0X22,0X22,0X22,0X22,0X3E};  // 0  totally 64 led there arr 8 row and 8 cloumn which want blink that select address binary value convert to hexa-decimal value, each 1 row give address 0x3E,2 row give address 0x22, using array inside how many elements there, totally 8 elements are there this store in 1 array, I want to character for 1 byte char digit0[8] 
char digit1[8]={0X08,0X18,0X28,0X08,0X08,0X08,0X08,0X3E};
char digit2[8]={0X3E,0X02,0X02,0X02,0X3E,0X20,0X20,0X3E};
char digit3[8]={0X3E,0X02,0X02,0X02,0X3E,0X02,0X02,0X3E};
char digit4[8]={0X20,0X28,0X28,0X28,0X3E,0X08,0X08,0X08};
char digit5[8]={0X3E,0X20,0X20,0X20,0X3E,0X02,0X02,0X3E};
char digit6[8]={0X3E,0X20,0X20,0X20,0X3E,0X22,0X22,0X3E};
char digit7[8]={0X3E,0X02,0X02,0X02,0X02,0X02,0X02,0X02};
char digit8[8]={0X3E,0X22,0X22,0X22,0X3E,0X22,0X22,0X3E};
char digit9[8]={0X3E,0X22,0X22,0X22,0X3E,0X02,0X02,0X3E};


int main()
{
  TRISC=0;     // TRISC=0 TRIS 	means try state, TRISC=0 select output mode
  TRISD=0;     // TRISD=0 TRIS 	means try state, TRISD=0 select output mode
  int i,j;
  while(1)     // while 1 give means condition true only, keep on running this loop
  {
     digit_print(digit0,1);   // calling the array one bye one calling array into function
     digit_print(digit1,1);
     digit_print(digit2,1);
     digit_print(digit3,1);
     digit_print(digit4,1);
     digit_print(digit5,1);
     digit_print(digit6,1);	
     digit_print(digit7,1);	
     digit_print(digit8,1);
     digit_print(digit9,1);
   }
   while(1);	// this while(1); while loop end of the ; semicolon using for stop
}
void digit_print(char digit[8],int sec)
{
   int i,j;
   for(i=0;i<60*sec;i++)    // for loop using 60*sec second in 100ms mile second 
   {
     for(j=0;j<8;j++)
     {
        PORTD=((unsigned char)(0x01<<j));  // this for unsigned character (0x01<<j) this << left shifting 0th address one by one shifting address 	 
        PORTC=digit[j];             // array address from portc data sending
        __delay_ms(1);              // __delay_ms(1) mile second
        PORTC=0;
     }
   }
}
