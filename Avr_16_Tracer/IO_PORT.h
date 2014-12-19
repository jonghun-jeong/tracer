/*
 * IO_PORT.h
 *
 * Created: 2014-11-26 afternoon 11:23:11
 *  Author: jjh
 */ 


#ifndef IO_PORT_H_
#define IO_PORT_H_

#include <avr/io.h>

#define BIT_ON(mPORT, index)	mPORT |= (0x01 << index)
#define BIT_OFF(mPORT, index)	mPORT &= ~(0x01 << index)

#define OUT_PORTC_0				BIT_ON(DDRC, 0)
#define OUT_PORTC_1				BIT_ON(DDRC, 1)
#define PORTC_0_ON				BIT_ON(PORTC, 0)//PORTC는 LED임
#define PORTC_1_ON				BIT_ON(PORTC, 1)
#define PORTC_0_OFF				BIT_OFF(PORTC,0)
#define PORTC_1_OFF				BIT_OFF(PORTC,1)


void led0(void);
void led1(void);
void INIT_IO(void);


#endif  //IO_PORT_H_ 