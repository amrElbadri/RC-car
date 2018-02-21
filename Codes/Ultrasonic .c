

#include <avr/io.h>

//header to enable data flow control over pins

#define F_CPU 1000000

//telling controller crystal frequency attached

#include <util/delay.h>

//header to enable delay function in program
static volatile int pulse = 0;//interger  to access all though the program

static volatile int i = 0;// interger  to access all though the program
ISR(INT0_vect)//interrupt service routine when there is a change in logic level

{

	if (i==1)//when logic from HIGH to LOW

	{

		TCCR1B=0;//disabling counter

		pulse=TCNT1;//count memory is updated to integer

		TCNT1=0;//resetting the counter memory

		i=0;

	}

	if (i==0)//when logic change from LOW to HIGH

	{

		TCCR1B|=(1<<CS10);//enabling counter

		i=1;

	}

}

int main(void)
{
	DDRD=0x01;
	_delay_ms(50);//giving delay of 50ms
	GICR|=(1<<INT0);//enabling interrupt0

	MCUCR|=(1<<ISC00);//setting interrupt triggering logic change

	int16_t COUNTA = 0;//storing digital output
    while (1) 
    {
		PORTD|=(1<<PIND0);

		_delay_us(15);///triggering the sensor for 15usec

		PORTD &=~(1<<PIND0);

		COUNTA = pulse/58;//getting the distance based on formula on introduction

    }
}
