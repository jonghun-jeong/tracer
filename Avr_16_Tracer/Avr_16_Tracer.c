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
#include "USART.h"
#include "TIMER.h"
volatile int time=0;
volatile unsigned char data='a';
volatile int usart_time = 0;

void main(void)
{

	sei();
	INIT_IO();
	INIT_USART();
	INIT_TIMER();
	
	
	while(1)
	{
		;
	}

}
SIGNAL(TIMER0_COMP_vect)
{
	time++;
	usart_time++;
	if(time<8)
	{
		PORTC=0x00;
	}
	else if(time==16)
	{
		time=0;
	}
	else
	{
		PORTC=0xff;
	}
	
	if(usart_time > 10)
	{
		usart_time = 0;
		USART_TEST();
	}
}
SIGNAL(INT0_vect)
{
	led0();
	OCR1B=0;
	OCR1A=60; 
	
}
SIGNAL(INT1_vect)
{
	led1();
	OCR1B=60;
	OCR1A=0;
}
