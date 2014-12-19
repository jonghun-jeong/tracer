/*
 * TIMER.c
 *
 * Created: 2014-12-19 오후 3:36:51
 *  Author: 정종훈
 */ 
#include "TIMER.h"
void INIT_TIMER(void)
{
	//TCCR0
	TCCR0_Phase_Correct_PWM	;
	TCCR0_Clk_128;
	
	
	//TCCR1
	Fast_PWM_8bit;
	TOP1_Fast_PWM_A;
	TOP1_Fast_PWM_B;
	Clk_8;
	
	TIMSK=0x02; 
	
	
	SET_OCR0;
	
}