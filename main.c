// Multiplexed_SSD.C

/*
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	//Array holding Patterns of digits from 0 to 9 for common cathode SSD	
	unsigned int digit[10]={0XFC,0X60,0XDA,0XF2,0X66,0XB6,0XBE,0XE0,0XFE,0XF6};
		
	DDRD=0XFF;				//Defines all pins of D as Output (For SSD Data)
	DDRC=0b0011110;			//Defines PC1, PC2, PC3, PC4 as Output (for selection lines)
	while(1)
	{
		PORTC=0b0011100;	//First SSD Selected (SL1=0)		
		PORTD=digit[1];		//Pattern Send to First SSD		
		_delay_ms(1);
		
		PORTC=0b0011010;	//Second SSD Selected (SL2=0)		
		PORTD=digit[2];		//Pattern Send to Second SSD		
		_delay_ms(1);

		PORTC=0b0010110;	//Third SSD Selected (SL3=0)	
		PORTD=digit[3];		//Pattern Send to Third SSD		
		_delay_ms(1);

		PORTC=0b0001110;	//Fourth SSD Selected (SL4=0)		
		PORTD=digit[4];		//Pattern Send to Fourth SSD		
		_delay_ms(1);
	}
}
*/


// Multiplexed_SSD.C


#include <avr/io.h>
#include <util/delay.h>

#define SSDPORT PORTD
#define SLPORT PORTC
#define SL1 PC1
#define SL2 PC2
#define SL3 PC3
#define SL4 PC4

int main(void)
{
	unsigned int digit[10]={0XFC,0X60,0XDA,0XF2,0X66,0XB6,0XBE,0XE0,0XFE,0XF6};
	
	DDRD=0XFF;
	DDRC=0b0011110;
	
	while(1) 
    {
		
	SLPORT=(1<<SL4)|(1<<SL3)|(1<<SL2);	//First SSD Selected
	SSDPORT=digit[1];					//Pattern Send to First SSD			  
	_delay_ms(1);
	
	SLPORT=(1<<SL4)|(1<<SL3)|(1<<SL1);	//Second SSD Selected
	SSDPORT=digit[2];					//Pattern Send to Second SSD		
	_delay_ms(1);		

	SLPORT=(1<<SL4)|(1<<SL2)|(1<<SL1);	//Third SSD Selected
	SSDPORT=digit[3];					//Pattern Send to Third SSD			 
	_delay_ms(1);

	SLPORT=(1<<SL3)|(1<<SL2)|(1<<SL1);	//Fourth SSD Selected
	SSDPORT=digit[4];					//Pattern Send to Fourth SSD			
	_delay_ms(1);
	}
}
