
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
    DDRA=0x01;
    while (1) 
    {
		PORTA|=(1<<0);
		_delay_ms(500);
		PORTA&=(~(1<<0));
		_delay_ms(2000);
    }
}

