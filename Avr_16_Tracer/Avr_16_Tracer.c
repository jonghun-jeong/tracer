/*
 * Avr_16_Tracer.c
 *
 * Created: 2014-11-21 afternoon 5:29:34
 *  Author: jjh
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include "Avr_16_Tracer.h"
#include "IO_PORT.h"
void usart(void);
volatile int echo;
void main(void)
{

	sei();
	
	INIT_PORTC;
	OUT_PORTC_0;
	OUT_PORTC_1;
	DDRA= 0x00;
	PORTC=0xff;
	UCSRA=0x02;
	UCSRB=0x18;
	UCSRC=0x06;
	UBRRH=0x00;
	UBRRL=0x19;
	MCUCR= 0x0A;
	GICR = 0xC0;
	PORTC=0x00;
	usart();
	

}

SIGNAL(INT0_vect)
{
	led0();
}
SIGNAL(INT1_vect)
{
	led1();
}
void usart()
{
	while(1)
	{
		while((UCSRA&0x20)!=0x20);
		UDR=echo;
		
	}
}