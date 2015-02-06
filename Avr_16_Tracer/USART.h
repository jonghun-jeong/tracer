/*
 * USART.h
 *
 * Created: 2014-11-27 morning 12:27:08
 *  Author: jjh
 */ 


#ifndef USART_H_
#define USART_H_
#include<avr/io.h>

#define BIT_ON(mPORT, index)	mPORT |= (0x01 << index)
#define BIT_OFF(mPORT, index)	mPORT &= ~(0x01 << index)




#define INIT_UCSRA			UCSRA=0x00
#define INIT_UCSRB			UCSRB=0x00
#define INIT_UCSRC			UCSRC=0x00
#define INIT_UBRRH			UBRRH=0x00
#define INIT_UBRRL			UBRRL=0x00

//UCSRA
#define UCSRA_Multi_Processor_Comunication_Mode_ON				BIT_ON(UCSRA, 0)
#define UCSRA_DoubleSpeed_Mode_ON								BIT_ON(UCSRA, 1)
#define UCSRA_Parity_Error_ON									BIT_ON(UCSRA, 2)
#define UCSRA_DOR_ON											BIT_ON(UCSRA, 3)//Data over run

#define UCSRA_Multi_Processor_Comunication_Mode_OFF				BIT_OFF(UCSRA, 0)
#define UCSRA_DoubleSpeed_OFF									BIT_OFF(UCSRA, 1)
#define UCSRA_Parity_Error_OFF									BIT_OFF(UCSRA, 2)
#define UCSRA_DOR_OFF											BIT_OFF(UCSRA, 3)
/*  
	4: Frame error
	5: UDR empty
	6: Transmit complete
	7: Recive complete
*/  



//UCSRB
#define UCSRB_Transmit_9th_Bit_ON								BIT_ON(UCSRB, 0)
#define UCSRB_Recive_9th_Bit_ON									BIT_ON(UCSRB, 1)
#define UCSRB_Transmit_Enable									BIT_ON(UCSRB, 3)
#define UCSRB_Recive_Enable										BIT_ON(UCSRB, 4)
#define UCSRB_UDR_empty_Interrupt_Enable						BIT_ON(UCSRB, 5)
#define UCSRB_TX_Complete_Interrupt_Enable						BIT_ON(UCSRB, 6)
#define UCSRB_RX_Complete_Interrupt_Enable						BIT_ON(UCSRB, 7)


#define UCSRB_Transmit_9th_Bit_OFF								BIT_OFF(UCSRB, 0)
#define UCSRB_Recive_9th_Bit_OFF								BIT_OFF(UCSRB, 1)
#define UCSRB_Transmit_Disable									BIT_OFF(UCSRB, 3)
#define UCSRB_Recive_Disable									BIT_OFF(UCSRB, 4)
#define UCSRB_UDR_empty_Interrupt_Disable						BIT_OFF(UCSRB, 5)
#define UCSRB_TX_Complete_Interrupt_Disable						BIT_OFF(UCSRB, 6)
#define UCSRB_RX_Complete_Interrupt_Disable						BIT_OFF(UCSRB, 7)




//UCSRC
#define UCSRC_5_bit												BIT_OFF(UCSRB,2);BIT_OFF(UCSRC,2);BIT_OFF(UCSRC,1)
#define UCSRC_6_bit												BIT_OFF(UCSRB,2);BIT_OFF(UCSRC,2);BIT_ON(UCSRC,1)
#define UCSRC_7_bit												BIT_OFF(UCSRB,2);BIT_ON(UCSRC,2);BIT_OFF(UCSRC,1)
#define UCSRC_8_bit												BIT_OFF(UCSRB,2);BIT_ON(UCSRC,2);BIT_ON(UCSRC,1)
#define UCSRC_9_bit												BIT_ON(UCSRB,2);BIT_ON(UCSRC,2);BIT_ON(UCSRC,1)
#define UCSRC_2BIT_Stop_Select									BIT_ON(UCSRC,3)
#define UCSRC_1BIT_Stop_Select									BIT_OFF(UCSRC,3)
#define UCSRC_Parity_Mode_Disable							    BIT_OFF(UCSRC,5); BIT_OFF(UCSRC,4)
#define UCSRC_Parity_Mode_Even_Parity						    BIT_ON(UCSRC,5); BIT_OFF(UCSRC,4)
#define UCSRC_Parity_Mode_Odd_Parity						    BIT_ON(UCSRC,5); BIT_ON(UCSRC,4)
#define UCSRC_Synchronous_Mode									BIT_ON(UCSRC,6)
#define UCSRC_Asynchronous_Mode									BIT_OFF(UCSRC,6)
#define UCSRC_USART_Register_Select_ON							BIT_ON(UCSRC,7)


#define UCSRC_USART_Register_Select_OFF							BIT_OFF(UCSRC,7)

#define USART_8MHz_Baud_Rate_9600                          UBRRH = 0; UBRRL = 51
#define USART_8MHz_Baud_Rate_38400                         UBRRH = 0; UBRRL = 12
#define USART_8MHz_Baud_Rate_115200                        UBRRH = 0; UBRRL = 3
#define USART_8MHz_U2X_Baud_Rate_9600                      UBRRH = 0; UBRRL = 103
#define USART_8MHz_U2X_Baud_Rate_38400                     UBRRH = 0; UBRRL = 25
#define USART_8MHz_U2X_Baud_Rate_115200                    UBRRH = 0; UBRRL = 8

///////////////////////////////////////////////////////////////////////////////////////
 		




//void USART_TEST(void);
void INIT_USART(void);



#endif /* USART_H_ */