
#include <avr/io.h>
#define GET_BIT(reg,Index)  ((reg>>Index)&0x01)

int main(void)
{
    DDRD=0x00;
	DDRA=0xff;
    while (1) 
    {
		int f=PIND;
		for(int i=0; i<(f*4); i++)
		{
			PORTA=0x01;
		}
		PORTA=0x00;
    }
}

