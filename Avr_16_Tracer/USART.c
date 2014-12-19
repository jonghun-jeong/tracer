/*
 * USART.c
 *
 * Created: 2014-11-27 오전 12:27:22
 *  Author: 정종훈
 */ 
#include "USART.h"
void INIT_USART()
{
	//UCSRA_DoubleSpeed_Mode_ON;
	UCSRA_Parity_Error_OFF;
	UCSRA_DOR_OFF;
	UCSRA_Multi_Processor_Comunication_Mode_OFF;
	
	
	UCSRB_TX_Complete_Interrupt_Disable;
	UCSRB_RX_Complete_Interrupt_Disable;
	UCSRB_UDR_empty_Interrupt_Disable;
	UCSRB_Recive_Enable;
	UCSRB_Transmit_Enable;
	UCSRB_Recive_9th_Bit_OFF;
	UCSRB_Transmit_9th_Bit_OFF;
	
	
	UCSRC_Asynchronous_Mode;
	UCSRC_8_bit;
	UCSRC_Parity_Mode_Disable;
	UCSRC_USART_Register_Select_ON;
	UCSRC_1BIT_Stop_Select;
	
	
	USART_8MHz_Baud_Rate_9600;
	
}




void USART_TEST(void)
{
	while((UCSRA & 0x20) == 0x00);
	UDR='a';	
}