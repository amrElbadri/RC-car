/*
 * uart.c
 *
 * Created: 13/02/2018 20:57:10
 * Author : A
 */ 
#define F_CPU 16000000
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
void stop()
{
	PORTA=0;
}
int main(void)
{
	DDRA = 0b00001111;
	uint16_t UBRRValue = 103;
	UBRRL = (uint8_t)UBRRValue;
	UBRRH = (uint8_t)(UBRRValue>>8);
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC|= (3<<UCSZ0);
    /* Replace with your application code */
    while (1) 
    {
		while(!(UCSRA&(1<<RXC)));
		//PORTC=UDR;
		//if(UDR=='a')
		//forward();
		
		switch(UDR)
		{
			case 'W':forward(); break;
		case 'S': backward(); break;
		case 'D':right(); break;
		case'A': left();  break;
		default : stop(); break;
		}
		UDR=0;
		
    }
return 0;
}

