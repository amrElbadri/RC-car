/*
 * Pushbutton + LED.c
 *
 * Created: 4/10/2018 2:40:08 AM
 * Author : Galal
 */ 
#define F_CPU 10000000UL //clock speed is 1MHz
#include <avr/io.h>


int main(void)
{
	DDRA |=  (1<<0) ; //Make pin 0 of port A as a output
	DDRB &= ~(1<<0) ; //Make pin 0 of port B as a input
	PORTB |= (1<<0);  //Enable the pull-up on PB0

    /* Replace with your application code */
    while (1) 
    {
		if(PINB & (1<<0) ) //if PIN0 of port B is high
		{
			PORTA |= (1<<0) ; //PIN0 of port A is high
		}
		else
		{
			PORTD &= ~(1<<0) ; //PIN0 of port A will remain low
		}
    }
}

