
#define  F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define SET_BIT(reg,Index)  reg|=(1<<Index)
#define CLR_BIT(reg,Index)  reg&=(~(1<<Index))
#define mRP 0 // Right Postive
#define mRN 1 // Right Negative
#define mLP 2 // Left Postive
#define mLN 3 // Left Negative
static volatile  long pulse = 0;
static volatile int i = 0;
int timerOverflow =0;
	double COUNTA = 0;//storing digital output

void Initpwm()
{
	
	TCCR0=0b11110101;
	TIMSK=0b00000000;
	OCR0=255; // Set OCR0 to 255 so that the duty cycle is initially 0 and the motor is not rotating
}
void Initpwm1()
{
	
	TCCR0=0b11110101;
	TIMSK=0b00000000;
	OCR2=60; // Set OCR0 to 255 so that the duty cycle is initially 0 and the motor is not rotating
}
void forward()
{
	SET_BIT(PORTA,mRP);
	CLR_BIT(PORTA,mRN);
	SET_BIT(PORTA,mLN);
	CLR_BIT(PORTA,mLP);
	
	
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
ISR(TIMER1_OVF_vect)
{
timerOverflow++;	
}
void UART_initialize (uint16_t baud_rate)
{
	uint16_t UBRR_Value = ((F_CPU /16 /baud_rate)-1);
	UBRRL = (uint8_t) UBRR_Value;
	UBRRH = (uint8_t) (UBRR_Value>>8);
	UCSRA = (1<<RXC);
	UCSRB = (1<<RXEN)|(1<<TXEN)|(1<<RXCIE);
	UCSRC |= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	//UCSRC &=~(1<<UMSEL);
	//UCSRC &=~(1<<USBS);
}  
char recive_UART ()
{
	while (!(UCSRA&(1<<RXC)));
	return UDR;
}
int main(void)
{
	//DDRA=0xff;
//	UART_initialize(9600);
TIMSK|=(1<<TOIE0);
	DDRC|=(1<<PINC0)|(1<<PINC6);
//	DDRD&=~(1<<PIND2);
	GICR|=(1<<INT0)|(1<<INT1);//enabling interrupt0

	MCUCR|=(1<<ISC01)|(1<<ISC11)|(1<<ISC10);//setting interrupt triggering logic change
	sei();
	PORTC&=~(1<<PINC0);
	PORTC&=~(1<<PINC6);
	while (1)
	{
		
			/*switch(recive_UART())
			{
				case 'W':forward(); break;
				case 'S': backward(); break;
				case 'D':right(); break;
				case'A': left();  break;
				default : stop(); break;
			}*/

	PORTC|=(1<<PINC0);
		_delay_us(15);
		PORTC&=~(1<<PINC0);
		_delay_ms(50);	
	}
	return 0;
}
ISR(INT0_vect)//interrupt service routine when there is a change in logic level

{
		TCCR1B=0;//disabling counter

		pulse=(int)TCNT1+(65535*timerOverflow);//count memory is updated to integer
		COUNTA=(double)pulse/941.176;
		if(COUNTA<5)
		{
		PORTC|=(1<<PINC6);
		}
		else
		{
		PORTC&=~(1<<PINC6);	
		}
		TCNT1=0;//resetting the counter memory
}
ISR(INT1_vect)
{
			timerOverflow=0;
			TCCR1B|=(1<<CS10);//enabling counter
}
