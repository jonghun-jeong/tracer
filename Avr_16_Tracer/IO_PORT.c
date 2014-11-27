/*
 * IO_PORT.c
 *
 * Created: 2014-11-26 afternoon 11:22:12
 *  Author: jjh
 */ 
#include "IO_PORT.h"

void led0()
{
	static int switch_0=0;
	switch_0++;
	if((switch_0%2)==0)
	PORTC_0_OFF;
	else if((switch_0%2)==1)
	PORTC_0_ON;
}
void led1()
{
	static int switch_1=0;
	switch_1++;
	if((switch_1%2)==0)
	PORTC_1_OFF;
	else if((switch_1%2)==1)
	PORTC_1_ON;
}