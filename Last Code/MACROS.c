#include "MACROS.h"
#include <avr/io.h>
#include <util/delay.h>
void Initpwm()
{
	
	TCCR0=0b11110101;
    //TCCR0|= (1<<WGM00)|(1<<WGM01)|(1<<CS00)|(1<<COM01);
	DDRB|=1<<PINB3;
	//TIMSK=0b00000000;
	//OCR0=200; // Set OCR0 to 255 so that the duty cycle is initially 0 and the motor is not rotating
}
void Initpwm1()
{
	
	TCCR2=0b11110101;
	//TCCR2|= (1<<WGM20)|(1<<WGM21)|(1<<CS20)|(1<<COM21);
	DDRD|=(1<<PIND7);
	//TIMSK=0b00000000;
	//OCR2=200; // Set OCR0 to 255 so that the duty cycle is initially 0 and the motor is not rotating
}
void forward()
{
	SET_BIT(PORTA,mRP);
	CLR_BIT(PORTA,mRN);
	CLR_BIT(PORTA,mLN);
	SET_BIT(PORTA,mLP);
	
}
void backward()
{
	CLR_BIT(PORTA,mRP);
	SET_BIT(PORTA,mRN);
	SET_BIT(PORTA,mLN);
	CLR_BIT(PORTA,mLP);
}
void right()
{
	SET_BIT(PORTA,mRP);
	CLR_BIT(PORTA,mRN);
	SET_BIT(PORTA,mLN);
	CLR_BIT(PORTA,mLP);
}
void left()
{
	CLR_BIT(PORTA,mRP);
	SET_BIT(PORTA,mRN);
	CLR_BIT(PORTA,mLN);
	SET_BIT(PORTA,mLP);
}
void SlightLeft()
{
	CLR_BIT(PORTA,mRP);
	CLR_BIT(PORTA,mRN);
	CLR_BIT(PORTA,mLN);
	SET_BIT(PORTA,mLP);
}
void SlightRight()
{
	SET_BIT(PORTA,mRP);
	CLR_BIT(PORTA,mRN);
	CLR_BIT(PORTA,mLN);
	CLR_BIT(PORTA,mLP);
}
void stop()
{
	CLR_BIT(PORTA,mRP);
	CLR_BIT(PORTA,mRN);
	CLR_BIT(PORTA,mLN);
	CLR_BIT(PORTA,mLP);
}
void forwardd()
{
	SET_BIT(PORTA,mRP);
	CLR_BIT(PORTA,mRN);
	CLR_BIT(PORTA,mLN);
	SET_BIT(PORTA,mLP);
	OCR0=208;
	OCR2=208;
}
void backwardd()
{
	CLR_BIT(PORTA,mRP);
	SET_BIT(PORTA,mRN);
	SET_BIT(PORTA,mLN);
	CLR_BIT(PORTA,mLP);
	OCR0=208;
	OCR2=208;
}
void rightt()
{
	SET_BIT(PORTA,mRP);
	CLR_BIT(PORTA,mRN);
	SET_BIT(PORTA,mLN);
	CLR_BIT(PORTA,mLP);
	OCR0=120;
	OCR2=120;
}
void leftt()
{
	CLR_BIT(PORTA,mRP);
	SET_BIT(PORTA,mRN);
	CLR_BIT(PORTA,mLN);
	SET_BIT(PORTA,mLP);
	OCR0=120;
	OCR2=120;
}
void Distance( float x)
{
	float counter =0;
	int arr[2];
	forward();
	while(counter < x)
	{

		for(int i=0; i<2; i++)
		{
			arr[i]=GET_BIT(PINC,4);
		}
		if(arr[0]!=arr[1])
		{
			counter+= 1.7;
		}
	}
	stop();
	
}
void rotate (float n)
{
	OCR0=120;
	OCR2=120;
	float counter =0;
	int arr[2];
	while(counter<n)
	{
		right();
		for(int i=0; i<2; i++)
		{
			arr[i]=GET_BIT(PINC,4);
		}
		if(arr[0]!=arr[1])
		{
			counter+= 2.2;
		}
	}
	stop();
}
void squaree ()
{
	OCR0=150;
	OCR2=150;
	for(int i=0;i<4;i++)
	{
	Distance(150);
	_delay_ms(500);
	rotate(90);
	}
}
void circlee1(float x)
{
	OCR0=0;
	OCR2 = 240;
	Distance(x);
}
void cir (float x)
{
	OCR0=0;
	OCR2=210;
	Distance(x);
}
void circlee2 (float x)
{
	OCR2=0;
	OCR0 = 240;
	Distance(x);
}
void infinity(float x)
{
	OCR2=150;
	OCR0=150;
	Distance(150);
	circlee1(x);
	OCR2=150;
	OCR0=150;
	Distance(150);
	circlee2(400);
	
}