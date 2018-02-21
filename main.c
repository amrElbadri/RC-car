#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL
int main(void)

{    DDRA = 0b10000000;
	while(1)
	{
		PORTA = 0b10000000;
		_delay_ms(500);
		PORTA = 0b00000000 ;
		_delay_ms(1500);
		
		
	}
	return 0;
}