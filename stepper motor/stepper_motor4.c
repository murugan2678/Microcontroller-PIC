/******************************************************************************/
/* Auther       : Murugan M                                   	  	      */
/* Date         : 6/12/2022                                 	              */
/* File name    : stepper motor led blink forward and reverse,half all route  */
/* Description  : using for loop                                              */
/******************************************************************************/





#include<htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_OFF & LVP_ON);

int i,j,k,m,n,l,p,q,r,s,t,y,z,a,b,c,f;
char arr[] = {0X07,0X03,0X0B,0X09,0X0D,0X0C,0X0E,0X06};

int main()
{
    TRISC = 0;
    PORTC = 0X00;
    TRISD = 0;
	
  while(1)
  {
	 
	 for(k=0; k<=12; k++)                     //forward route stepper motor
	  {
		for(i=0; i<=8; i++)
		{
			RD5 = 1;                  //first led 1 means on 
			RD4 = 0;                  //0 means off
			RD3 = 0;
			RD2 = 0;
			PORTC = arr[i];
			__delay_ms(30);
		}
	  }
	  __delay_ms(1000);
	  
	  for(k=0; k<=12; k++)
	  {
		 for(j=7; j>=0; j--)              //reverse route stepper motor
		 {
			RD5 = 1;                  //first led 1 means on
			RD4 = 0;                  //0 means off    
			RD3 = 0;
			RD2 = 0;
			PORTC = arr[j];
			__delay_ms(30);
		 }
	   }
           __delay_ms(1000);
	 
	  for(k=0; k<50; k++)
	  { 
		  for(m=0; m<8; m++)              //forward route stepper motor
		  {
			RD5 = 1;                  //first led on 
			RD4 = 0;
			RD3 = 0;
			RD2 = 0;
			PORTC = arr[m];
			__delay_ms(30);
		 }
	   } 
	   __delay_ms(1000);	 
	  
	  for(k=0; k<50; k++)
	  { 
		  for(n=7; n>=0; n--)            //reverse route stepper motor
		  {
			RD5 = 1;                 //first led 1 means on
			RD4 = 0;                 //0 means off
			RD3 = 0;
			RD2 = 0;
			PORTC = arr[n];
			__delay_ms(30);
		 }
	   } 
	   __delay_ms(1000);	 
	  
	  for(k=0; k<=12; k++)
	  {
		  for(p=0; p<=8; p++)            //forward route stepper motor
		  {
			RD5 = 0;
			RD4 = 1;                 //second led on
			RD3 = 0;
			RD2 = 0;
			PORTC = arr[p];
			__delay_ms(30);
		  }
	   }
	   __delay_ms(1000);
		
	  for(k=0; k<=12; k++)                  //reverse route stepper motor
	  {
		  for(q=7; q>=0; q--)
		  {
			RD5 = 0;
			RD4 = 1;                //second led on
			RD3 = 0;
			RD2 = 0;
			PORTC = arr[q];
			__delay_ms(30);
		  }
	  }
          __delay_ms(1000);
         
         for(k=0; k<50; k++)
	  { 
		  for(r=0; r<8; r++)
		  {
			RD5 = 0;
			RD4 = 1;
			RD3 = 0;
			RD2 = 0;
			PORTC = arr[r];
			__delay_ms(30);
		   }
	  } 
	  __delay_ms(1000);	 
	  
	  for(k=0; k<50; k++)
	  { 
		  for(s=7; s>=0; s--)
		  {
			RD5 = 0;
			RD4 = 1;
			RD3 = 0;
			RD2 = 0;
			PORTC = arr[s];
			__delay_ms(30);
		 }
	   } 
	  __delay_ms(1000);	 
        	
	  for(k=0; k<=13; k++)
	  {
		  for(t=0; t<=8; t++)
		  {
			RD5 = 0;
			RD4 = 0;
			RD3 = 1;
			RD2 = 0;
			PORTC = arr[t];
			__delay_ms(30);
		   }
	   }
	   __delay_ms(1000);
		
	  for(k=0; k<=13; k++)
	  {
		  for(y=7; y<=0; y--)
		  {
			RD5 = 0;
			RD4 = 0;
			RD3 = 1;
			RD2 = 0;
			PORTC = arr[y];
			__delay_ms(30);
		  }
	  }
	  __delay_ms(1000);
		
	  for(k=0; k<50; k++)
	  {
		  for(z=0; z<8; z++)
		  {
			RD5 = 0;
			RD4 = 0;
			RD3 = 1;
			RD2 = 0;
			PORTC = arr[z];
			__delay_ms(30);
		   }
	  }
	  __delay_ms(1000);
		
	  for(k=0; k<50; k++)
	  {
		  for(a=7; a<=0; a--)
		  {
			RD5 = 0;
			RD4 = 0;
			RD3 = 1;
			RD2 = 0;
			PORTC = arr[a];
			__delay_ms(30);
		  }
	  }
	  __delay_ms(1000);
				
	 for(k=0; k<=13; k++)
	 {
		 for(b=0; b<=8; b++)
		 {
		        RD5 = 0;
		        RD4 = 0;
			RD3 = 0;
			RD2 = 1;
			PORTC = arr[b];
		        __delay_ms(30);
		  }
	}
	__delay_ms(1000);
		
	for(k=0; k<=13; k++)
	{
		 for(c=7; c>=0; c--)
		  {
			RD5 = 0;
			RD4 = 0;
			RD3 = 0;
			RD2 = 1;
			PORTC = arr[c];
			__delay_ms(30);
		  }
	}
	__delay_ms(1000);
		
	for(k=0; k<=50; k++)
	{
		for(l=0; l<=8; l++)
		{
			RD5 = 0;
			RD4 = 0;
			RD3 = 0;
			RD2 = 1;
			PORTC = arr[l];
			__delay_ms(30);
		}
	}
	__delay_ms(1000);
		
	for(k=0; k<=50; k++)
	{
		for(f=7; f>=0; f--)
		{
			RD5 = 0;
			RD4 = 0;
			RD3 = 0;
			RD2 = 1;
			PORTC = arr[f];
			__delay_ms(30);
		}
	}
	__delay_ms(3000);
	}
}		
