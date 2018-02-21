#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "MACROS.h"
int main(void)
{
   DDRA=0X3F;
    while (1) 
    {
		forward();
		_delay_ms(10000);
		backward();
		_delay_ms(10000);
		right();
		_delay_ms(100);
		left();
		_delay_ms(100);
		stop();
		_delay_ms(100);
    }
}

