#define  F_CPU 16000000UL
#define get_bit(reg,index)  ((reg>>index)&0x01)
#include <avr/io.h>
#include <util/delay.h>
static volatile double pulse = 0;
int main(void)
{
	DDRC=0b11011111;
	while (1)
{
	PORTC|=(1<<6);
	_delay_ms(1000);
	PORTC &=~(1<<6);
	_delay_ms(1000);
}