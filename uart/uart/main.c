/*
 * uart.c
 *
 * Created: 13/02/2018 20:57:10
 * Author : A
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


void forward()
{
	PORTA=0b00000101;
}
void backward()
{
	PORTA=0b00001010;
}
void right()
{
	PORTA=0b00001001;
}
void left()
{
	PORTA=0b00000110;
}

int main(void)
{
	DDRA = 0b00001111;
    /* Replace with your application code */
    while (1) 
    {
		forward();
		_delay_ms(1000);
		backward();
		_delay_ms(1000);
		right();
		_delay_ms(1000);
		left();
		_delay_ms(1000);
    }

}

