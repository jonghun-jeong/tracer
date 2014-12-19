/*
 * TIMER.h
 *
 * Created: 2014-12-04 오전 3:52:33
 *  Author: 정종훈
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include<avr/io.h>
#define BIT_ON(mPORT, index)	mPORT |= (0x01 << index)
#define BIT_OFF(mPORT, index)	mPORT &= ~(0x01 << index)

//Mode
#define Phase_Correct_PWM_8bit						BIT_ON(TCCR1A,0)
#define Phase_Correct_PWM_9bit						BIT_ON(TCCR1A,1)
#define Phase_Correct_PWM_10bit						BIT_ON(TCCR1A,0);BIT_ON(TCCR1A,1)
#define CTC_Mode									BIT_ON(TCCR1B,3)
#define Fast_PWM_8bit								BIT_ON(TCCR1B,3);BIT_ON(TCCR1A,0)
#define Fast_PWM_9bit								BIT_ON(TCCR1B,3);BIT_ON(TCCR1A,1)
#define Fast_PWM_10bit								BIT_ON(TCCR1B,3);BIT_ON(TCCR1A,0);BIT_ON(TCCR1A,1)


//Fast PWM
#define TOP1_Fast_PWM_A							BIT_ON(TCCR1A,7)
#define TOP1_Fast_PWM_B							BIT_ON(TCCR1A,5)
#define TOP0_Fast_PWM_A							BIT_ON(TCCR1A,7);BIT_ON(TCCR1A,6)
#define TOP0_Fast_PWM_B							BIT_ON(TCCR1A,5);BIT_ON(TCCR1A,4)



//	Phase Correct PWM					
#define Upper0_Phase_Correct_PWM_A							BIT_ON(TCCR1A,7)
#define Upper0_Phase_Correct_PWM_B							BIT_ON(TCCR1A,5)
#define Upeer1_Phase_Correct_PWM_A							BIT_ON(TCCR1A,7);BIT_ON(TCCR1A,6)
#define Upper1_Phase_Correct_PWM_B							BIT_ON(TCCR1A,5);BIT_ON(TCCR1A,4)


//Clk
#define Clk_1												BIT_ON(TCCR1B,0)
#define Clk_8												BIT_ON(TCCR1B,1)
#define Clk_64												BIT_ON(TCCR1B,0);BIT_ON(TCCR1B,1)
#define Clk_256												BIT_ON(TCCR1B,2)
#define Clk_1024											BIT_ON(TCCR1B,2);BIT_ON(TCCR1B,0)
 

//TIMISK
#define TIMSK_Timer_Counter1_Input_Capture_Interrupt_Enable						BIT_ON(TIMSK,5)
#define TIMSK_Timer_Counter1_Output_Compare_Match_A_Enable						BIT_ON(TIMSK,4)
#define TIMSK_Timer_Counter1_Output_Compare_Match_B_Enable						BIT_ON(TIMSK,3)
#define TIMSK_Timer_Counter1_Overflow_Interrupt_Enable							BIT_ON(TIMSK,2)



//TCCR0	
#define TCCR0_Fast_PWM_Mode														BIT_ON(TCCR0,6);BIT_ON(TCCR0,3)
#define TCCR0_CTC_Mode															BIT_ON(TCCR0,3)
#define TCCR0_Phase_Correct_PWM													BIT_ON(TCCR0,6)
#define TCCR0_Top1_Fast_PWM														BIT_ON(TCCR0,5)
#define TCCR0_TOP0_Fast_PWM														BIT_ON(TCCR0,4);BIT_ON(TCCR0,5)


#define TCCR0_Clk_1																BIT_ON(TCCR0,0)
#define TCCR0_Clk_8																BIT_ON(TCCR0,1)
#define TCCR0_Clk_32															BIT_ON(TCCR0,1);BIT_ON(TCCR0,0)													
#define TCCR0_Clk_64															BIT_ON(TCCR0,2)
#define TCCR0_Clk_128															BIT_ON(TCCR0,2);BIT_ON(TCCR0,0)
#define TCCR0_Clk_256															BIT_ON(TCCR0,2);BIT_ON(TCCR0,1)
#define TCCR0_Clk_1024															BIT_ON(TCCR0,2);BIT_ON(TCCR0,1);BIT_ON(TCCR0,0)


#define SET_OCR0									OCR0=50




void INIT_TIMER(void);


/*TCCR0=0x45;
TIMSK=0x02;
OCR0=50; //분주비 조절하여 약 256ms에 한번씩 검사하도록함.
TCCR1A=0xa1;
TCCR1B=0x0a;
*/



#endif /* TIMER_H_ */