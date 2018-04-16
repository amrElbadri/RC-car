#include "MACROS.h"
#include <avr/io.h>
void Initpwm()
{
	
	TCCR0=0b11110101;
	TIMSK=0b00000000;
	//OCR0=200; // Set OCR0 to 255 so that the duty cycle is initially 0 and the motor is not rotating
}
void Initpwm1()
{
	
	TCCR2=0b11110101;
	TIMSK=0b00000000;
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
	OCR0=100;
	OCR2=100;
}
void leftt()
{
	CLR_BIT(PORTA,mRP);
	SET_BIT(PORTA,mRN);
	CLR_BIT(PORTA,mLN);
	SET_BIT(PORTA,mLP);
	OCR0=100;
	OCR2=100;
}