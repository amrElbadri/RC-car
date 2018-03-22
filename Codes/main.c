#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
static volatile int pulse = 0;
int ultra (int echo)
{
	PORTC |=(1<<0);
	PORTC &=~(1<<0);
	float m;
	while(echo != 0)
	{	
		
	TCCR1B|=(1<<CS10);//enabling counter
	
	}
	_delay_us(12);
	PORTC &=~(1<<0);
	TCCR1B=0;
	pulse=TCNT1;//count memory is updated to integer
	m=340*pulse*0.03125*0.000001;
	if(m<5)
	{
		return 1 ;
	}
	else
	return 0 ;
	TCNT1=0;//resetting the counter memory
}

int main(void)
{
	DDRC=0b11011111;
	int max ;
    /* Replace with your application code */
    while (1) 
    {
		max=ultra(PINC5);
		if(max==1)
		{
			PORTC |=(1<<6);
		}
		
    }
}

