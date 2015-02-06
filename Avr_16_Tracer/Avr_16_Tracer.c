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
//volatile int time=0;
//volatile unsigned char data='a';

volatile unsigned char led_value[8];
volatile char j=0;
//volatile char wait=0;
volatile unsigned char led_average[8];
volatile unsigned char led_max[8]={0,0,0,0,0,0,0,0};
volatile unsigned char led_low[8]={255,255,255,255,255,255,255,255};
//volatile char calibrater=0;
volatile char calib_flg=1;
volatile char led_val[8];
volatile int all_sum=0;
volatile float position_temp;
volatile unsigned char position_L[8]={250,230,210,160,130,120,0,0};
volatile unsigned char position_R[8]={0,0,100,130,150,190,200,240};
volatile char position;
volatile unsigned char average[8];
//volatile char finish=0;	
/*void ADC_view(void);
void max_view(void);
void low_view(void);*/
void calibration(void);
void sensing(void);
void Catch_position(void);

void main(void)
{

	sei();
	INIT_IO();
	INIT_USART();
	INIT_TIMER();
	
	
	
	DDRB=0xff;
	DDRD=0x30;
	
	PORTB=0x06;
	PORTC=0xff;
	
	ADMUX=0x60;
	ADCSRA=0xcc;
	while(1)
	{
		
			
			while(calib_flg)
			{
				calibration();
			}
			
			
			sensing();
			Catch_position();
			OCR1A=position_R[position];
			OCR1B=position_L[position];
		
	}

}
/*SIGNAL(TIMER0_COMP_vect)
{
	wait++;
	time++;
	
	

	
	if(wait==32)
	{
		wait=0;
	}
	if(time==16)
	{
		time=8;
	}
	
	
	if(usart_time > 10)
	{
		usart_time = 0;
		USART_TEST();
	}
}*/
SIGNAL(INT0_vect)
{
	PORTC=0x00;
	calib_flg=0;
	
	
} 
/*SIGNAL(INT1_vect)
{
	PORTC=0x02;
	
}*/
SIGNAL(ADC_vect)
{
	led_value[j++]=ADCH;
	if(j==8)
	j=0;
	ADMUX=0x60+j;
	ADCSRA=0xcc;
}
/*void ADC_view(void)               									
{
	int i;
	if(wait>8
	)
	{
		
	
		for(i=0;i<8;i++)
		{
			while((UCSRA&0x20)!=0x20);
			UDR=(((int)(led_val[i]/1000))+'0');
			
			while((UCSRA&0x20)!=0x20);
			UDR=((int)((led_val[i]/100)%10)+'0');
			
			while((UCSRA&0x20)!=0x20);
			UDR=(((int)((led_val[i]/10)%10))+'0');
			while((UCSRA&0x20)!=0x20);
			UDR=((led_val[i]%10)+'0');
			while((UCSRA&0x20)!=0x20);
			UDR=' ';
		}
		while((UCSRA&0x20)!=0x20);
		UDR=0x0a;
		while((UCSRA&0x20)!=0x20);
		UDR=0x0b;
	}
	
	
	

}*/
void calibration (void)
{
	
	
			PORTC=0x01;
			
			int i;
			for(i=0;i<8;i++)
			{
				if(led_value[i]>led_max[i])
				{
					led_max[i]=led_value[i];
				}
			
				if(led_value[i]<led_low[i])
				{
					led_low[i]=led_value[i];
				
				}
				led_average[i]=led_max[i]-led_low[i];
				average[8]=((led_max[i]+led_low[i])/2);
			}
		
	
	
}
/*void max_view(void)
{
	int i;
	if(wait>8)
	{
		
		
		for(i=0;i<8;i++)
		{
			while((UCSRA&0x20)!=0x20);
			UDR=(((int)(led_max[i]/1000))+'0');
			
			while((UCSRA&0x20)!=0x20);
			UDR=((int)((led_max[i]/100)%10)+'0');
			
			while((UCSRA&0x20)!=0x20);
			UDR=(((int)((led_max[i]/10)%10))+'0');
			while((UCSRA&0x20)!=0x20);
			UDR=((led_max[i]%10)+'0');
			while((UCSRA&0x20)!=0x20);
			UDR=' ';
		}
		while((UCSRA&0x20)!=0x20);
		UDR= 0x0a;
		while((UCSRA&0x20)!=0x20);
		UDR=0x0b;
	}
}
void low_view(void)
{
	int i;
	if(wait>8)
	{
		
		
		for(i=0;i<8;i++)
		{
			while((UCSRA&0x20)!=0x20);
			UDR=(((int)(led_low[i]/1000))+'0');
			
			while((UCSRA&0x20)!=0x20);
			UDR=((int)((led_low[i]/100)%10)+'0');
			
			while((UCSRA&0x20)!=0x20);
			UDR=(((int)((led_low[i]/10)%10))+'0');
			while((UCSRA&0x20)!=0x20);
			UDR=((led_low[i]%10)+'0');
			while((UCSRA&0x20)!=0x20);
			UDR=' ';
		}
		while((UCSRA&0x20)!=0x20);
		UDR=0x0a;
		while((UCSRA&0x20)!=0x20);
		UDR=0x0b;

	}
}*/
void sensing()
{
	int i;
	all_sum = 0;
	for(i=0;i<8;i++)
	{
		if(led_value[i]>led_max[i])
		{
			led_max[i]=led_value[i];
		}
		
		if(led_value[i]<led_low[i])
		{
			led_low[i]=led_value[i];
			
		}
		led_average[i]=led_max[i]-led_low[i];
		led_val[i] = (unsigned char)(((led_value[i]-led_low[i])*100)/led_average[i]);
		if(led_val[i]>100)led_val[i] = 100;
		all_sum += led_val[i];
		
	}
}
void Catch_position(void)
{
	char i;
	position_temp = 0;
	
		for(i=0; i<8;i++)
		{
			 position_temp += (i+1)*led_val[i];
			
		}
		position_temp = position_temp/all_sum;
		
		position = position_temp;
		
}