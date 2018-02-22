#define F_CPU 1000000UL
#include <avr/io.h> 
#include <avr/delay.h>
int main(void) 
{
	DDRA=0B11110000;
	while(1)
	{
		PORTA=0b10000000;
		_delay_ms(500);
		PORTA=0b01000000;
		_delay_ms(500);
		PORTA=0b00100000;
		_delay_ms(500);
		PORTA=0b00010000;
		_delay_ms(500);
	}
	return 0 ;
} 