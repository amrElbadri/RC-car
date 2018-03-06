
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	//Selecting the PA pins as outputs
	DDRA = 0xFF;
	
	while (1)
	{
		//Red LED is ON for 6 seconds 
		//The green & the yellow LEDs are OFF
		PORTA|=0b00000001;
		_delay_ms(6000);		
		//Yellow LED is ON for 1 second
		//The red & the green LEDs are OFF
		PORTA|=0b00000010;
		_delay_ms(1000);		
		//Green LED is ON for 3 seconds
		//The red & the yellow LEDs are OFF
		PORTA|=0b00000100;
		_delay_ms(3000);
		
	}
	return 0;
}

