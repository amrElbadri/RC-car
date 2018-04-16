#include "MACROS.h" 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include <avr/interrupt.h>
static volatile  long pulse = 0;
static volatile int i = 0;
int timerOverflow =0;

/*ISR(TIMER1_OVF_vect)
{
	timerOverflow++;
}*/
void UART_init(uint16_t baud_rate)
{
	uint16_t UBRRValue = (F_CPU/16/baud_rate)-1;
	UBRRL = (uint8_t)UBRRValue;
	UBRRH = (uint8_t)(UBRRValue>>8);
	UCSRA=(1<<RXC);
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UCSRC&=~(1<<UMSEL);
	UCSRC&=~(1<<USBS);
}
char receiveChar()
{
	while(!(UCSRA&(1<<RXC)));
	return UDR;
}
/*void ultra()
{
	while(receiveChar()=='A')
	{
		//_delay_ms(50);
		PORTC|=(1<<PINC0);
		_delay_us(10);
		PORTC&=~(1<<PINC0);
		_delay_ms(50);
		COUNTA=(double)pulse/932.944;
		if(COUNTA<10)
		{
			PORTC|=(1<<PINC6);
		}
		else{
			PORTC&=~(1<<PINC6);
		}
	}
}*/
int main(void)
{
	 Initpwm();
	 Initpwm1();
	UART_init(9600);
	DDRA = 0b00001111;
	DDRD|=(1<<PIND7);
	DDRB|=(1<PINB3);
	//TIMSK|=(1<<TOIE0);
	DDRC&=~(1<<7);//right line tracker
	DDRC&=~(1<<6);//left line tracker
	DDRC&=~(1<<5);//middle line tracker
	//GICR|=(1<<INT0);//enabling interrupt0
	//MCUCR|=(1<<ISC00);//setting interrupt triggering logic change
	//sei();
	//PORTC&=~(1<<PINC0);
	//PORTC&=~(1<<6);
	//double COUNTA=0 ; //storing digital output
	while(1)
	{
		switch(receiveChar())
		{
			case 'W':forward(); break;
			case 'S': backward(); break;
			case 'D':right(); break;
			case 'A': left();  break;
			case '0': {OCR0=255; OCR2=255; } break;
			case '1': {OCR0=240; OCR2=240; } break;
			case '2': {OCR0=210; OCR2=210; }break;
			case '3': {OCR0=180; OCR2=180; }break;
			case '4': {OCR0=150; OCR2=150; }break;
			case '5': {OCR0=120; OCR2=120; }break;
			case '6': {OCR0=90; OCR2=90; } break;
			case '7': {OCR0=60; OCR2=60; }break;
			case '8': {OCR0=30; OCR2=30; }break;
			case '9': {OCR0=0; OCR2=0; }break;
			case'M': {
				
              while (1)
				{
					
					if(GET_BIT(PINC,7)==1&&GET_BIT(PINC,6)==1&&GET_BIT(PINC,5)==0)
					{
						forwardd();
					}
				 else if (GET_BIT(PINC,7)==0&&GET_BIT(PINC,6)==1&&GET_BIT(PINC,5)==1)
				{
					while (GET_BIT(PINC,5)!=0)
					{
					    rightt();
					}
				}
				 else if (GET_BIT(PINC,7)==1&&GET_BIT(PINC,6)==0&&GET_BIT(PINC,5)==1)
				{
					
					while (GET_BIT(PINC,5)!=0)
					{
					leftt();
					}
				}
				 else if (GET_BIT(PINC,7)==0&&GET_BIT(PINC,6)==0&&GET_BIT(PINC,5)==0)
				{
					forwardd();
				}
				 else if (GET_BIT(PINC,7)==1&&GET_BIT(PINC,6)==0&&GET_BIT(PINC,5)==0)
				{
					leftt();
				}
				 else if (GET_BIT(PINC,7)==0&&GET_BIT(PINC,6)==1&&GET_BIT(PINC,5)==0)
				{
					rightt();
				}
				else if (GET_BIT(PINC,7)==1&&GET_BIT(PINC,6)==1&&GET_BIT(PINC,5)==1) //bug
				{
					forwardd();
				}
				 else if (GET_BIT(PINC,7)==0&&GET_BIT(PINC,6)==0&&GET_BIT(PINC,5)==1)
				{
					forwardd();
				}
					/*PORTC|=(1<<PINC0);
					_delay_us(10);
					PORTC&=~(1<<PINC0);
					_delay_ms(100);
					COUNTA=(double)pulse/932.944;
					if(COUNTA<7)
					{
					PORTC|=(1<<6);
					}
					else
					{
					PORTC&=~(1<<PINC6);
					}*/
					if (UDR=='A'||UDR=='W'||UDR=='S'||UDR=='D'||UDR=='X')
					{
						 break;
					}
				}
				
			
				     } break;
			default :stop();break;
		}
	
	}
	return 0;
}
/*ISR(INT0_vect)//interrupt service routine when there is a change in logic level

{

	if (i==1)//when logic from HIGH to LOW

	{

		TCCR1B=0;//disabling counter

		pulse=TCNT1;//+(65535*timerOverflow);//count memory is updated to integer

		TCNT1=0;//resetting the counter memory

		i=0;

	}

	if (i==0)//when logic change from LOW to HIGH

	{
       // timerOverflow=0;
		TCCR1B|=(1<<CS10);//enabling counter

		i=1;

	}
}*/