

#include <avr/io.h>
#include <util/delay.h>
void LightBouncing()
{
	for(int i=4 ; i<8 ; i++)
	{
    PORTD|=(1<<i);
	_delay_ms(1000);
	PORTD&=(~(1<<i));
	}
	for(int j=7 ; j>3 ; j--)
	{
		PORTD|=(1<<j);
		_delay_ms(1000);
		PORTD&=(~(1<<j));
	}
}
int main(void)
{
    DDRD=0xF0;
    while (1) 
    {
		LightBouncing();
    }
}

