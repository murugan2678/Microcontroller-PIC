/******************************************************************************/
/* Auther       : Murugan M                                                   */
/* Date         : 6/9/2023                                                    */
/* File name    : led_matrix 8x8, printing digit 0to9 and characters A to Z   */
/* Description  : Using array and for loop and void function                  */
/******************************************************************************/



#include <htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(0x1f7a);

void digit_print(char digit[8],int sec);    // declare the function void digit_print(char digit[8],int sec) sec means mile seconds set 

// digit 0 to 9
char digit0[8]={0X3E,0X22,0X22,0X22,0X22,0X22,0X3E,0X00};  // 0  totally 64 led there arr 8 row and 8 cloumn which want blink that select address binary value convert to hexa-decimal value, each 1 row give address 0x3E,2 row give address 0x22, using array inside how many elements there, totally 8 elements are there this store in 1 array, I want to character for 1 byte char digit0[8]     
char digit1[8]={0X08,0X18,0X28,0X08,0X08,0X08,0X3E,0X00};  // 1
char digit2[8]={0X3E,0X02,0X02,0X3E,0X20,0X20,0X3E,0X00};  // 2
char digit3[8]={0X3E,0X02,0X02,0X3E,0X02,0X02,0X3E,0X00};  // 3
char digit4[8]={0X20,0X28,0X28,0X3E,0X08,0X08,0X08,0X00};  // 4
char digit5[8]={0X3E,0X20,0X20,0X3E,0X02,0X02,0X3E,0X00};  // 5
char digit6[8]={0X3E,0X20,0X20,0X3E,0X22,0X22,0X3E,0X00};  // 6
char digit7[8]={0X3E,0X02,0X02,0X02,0X02,0X02,0X02,0X00};  // 7
char digit8[8]={0X3E,0X22,0X22,0X3E,0X22,0X22,0X3E,0X00};  // 8
char digit9[8]={0X3E,0X22,0X22,0X3E,0X02,0X02,0X3E,0X00};  // 9

// characters A to Z
char digit10[8]={0X1C,0X22,0X22,0X22,0X3E,0X22,0X22,0X00};  // A
char digit11[8]={0X3C,0X22,0X22,0X3C,0X22,0X22,0X3C,0X00};  // B
char digit12[8]={0X1C,0X22,0X20,0X20,0X20,0X22,0X1C,0X00};  // C
char digit13[8]={0X38,0X24,0X22,0X22,0X22,0X24,0X38,0X00};  // D 
char digit14[8]={0X3E,0X20,0X20,0X3C,0X20,0X20,0X3E,0X00};  // E
char digit15[8]={0X3E,0X20,0X20,0X3C,0X20,0X20,0X20,0X00};  // F 
char digit16[8]={0X1C,0X22,0X20,0X2E,0X22,0X22,0X1E,0X00};  // G
char digit17[8]={0X22,0X22,0X22,0X3E,0X22,0X22,0X22,0X00};  // H
char digit18[8]={0X3E,0X08,0X08,0X08,0X08,0X08,0X3E,0X00};  // I
char digit19[8]={0X1E,0X04,0X04,0X04,0X04,0X24,0X18,0X00};  // J
char digit20[8]={0X22,0X24,0X28,0X10,0X28,0X24,0X22,0X00};  // K
char digit21[8]={0X20,0X20,0X20,0X20,0X20,0X20,0X3E,0X00};  // L 
char digit22[8]={0X22,0X36,0X2A,0X22,0X22,0X22,0X22,0X00};  // M
char digit23[8]={0X22,0X22,0X32,0X2A,0X26,0X22,0X22,0X00};  // N
char digit24[8]={0X1C,0X22,0X22,0X22,0X22,0X22,0X1C,0X00};  // O
char digit25[8]={0X3C,0X22,0X22,0X3C,0X20,0X20,0X20,0X00};  // P
char digit26[8]={0X1C,0X22,0X22,0X22,0X2A,0X24,0X1A,0X00};  // Q 
char digit27[8]={0X3C,0X22,0X22,0X3C,0X28,0X24,0X22,0X00};  // R 
char digit28[8]={0X1E,0X20,0X20,0X1C,0X02,0X02,0X3C,0X00};  // S  
char digit29[8]={0X3E,0X08,0X08,0X08,0X08,0X08,0X08,0X00};  // T  
char digit30[8]={0X22,0X22,0X22,0X22,0X22,0X22,0X1C,0X00};  // U 
char digit31[8]={0X22,0X22,0X22,0X22,0X22,0X14,0X08,0X00};  // V  
char digit32[8]={0X22,0X22,0X22,0X2A,0X2A,0X2A,0X14,0X00};  // W 
char digit33[8]={0X22,0X22,0X14,0X08,0X14,0X22,0X22,0X00};  // X 
char digit34[8]={0X22,0X22,0X22,0X14,0X08,0X08,0X08,0X00};  // Y  
char digit35[8]={0X3E,0X02,0X04,0X08,0X10,0X20,0X3E,0X00};  // Z
int main()
{
   TRISC=0;
   TRISD=0;
   int i,j;
   while(1)              // while 1 give means condition true only, keep on running this loop
   {
       // digit 0 to 9
       digit_print(digit0,1);  // calling the array one bye one calling array into function
       digit_print(digit1,1);
       digit_print(digit2,1);
       digit_print(digit3,1);
       digit_print(digit4,1);
       digit_print(digit5,1);
       digit_print(digit6,1);	
       digit_print(digit7,1);	
       digit_print(digit8,1); 
       digit_print(digit9,1); 
	
       // characters A to Z
       digit_print(digit10,1);
       digit_print(digit11,1);
       digit_print(digit12,1);
       digit_print(digit13,1);
       digit_print(digit14,1);
       digit_print(digit15,1);
       digit_print(digit16,1);
       digit_print(digit17,1);
       digit_print(digit18,1);
       digit_print(digit19,1);
       digit_print(digit20,1);
       digit_print(digit21,1); 
       digit_print(digit22,1);
       digit_print(digit23,1); 
       digit_print(digit24,1);
       digit_print(digit25,1);
       digit_print(digit26,1);
       digit_print(digit27,1); 
       digit_print(digit28,1); 
       digit_print(digit29,1); 
       digit_print(digit30,1); 
       digit_print(digit31,1); 
       digit_print(digit32,1); 
       digit_print(digit33,1); 
       digit_print(digit34,1); 
       digit_print(digit35,1);
    }
    while(1);	// this while(1); while loop end of the ; semicolon using for stop
}
void digit_print(char digit[8],int sec)
{
  int i,j;
  for(i=0;i<60*sec;i++)  // for loop using 60*sec second in 100ms mile second 
  {
    for(j=0;j<8;j++)
    {
       PORTD=((unsigned char)(0x01<<j));   // this for unsigned character (0x01<<j) this << left shifting 0th address one by one shifting address 	
       PORTC=digit[j];   // array address from portc data sending
       __delay_ms(1);    // __delay_ms(1) mile second 
       PORTC=0;
    }
  }
}
