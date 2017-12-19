/*
 * Usart.h
 *
 *  Created on: Dec 12, 2017
 *      Author: user
 */

#ifndef USART_H_
#define USART_H_

#include<stdio.h>

#define USART1_BASE_ADDR 	0x40011000
#define usart1      ((UsartReg *)(USART1_BASE_ADDR))

typedef struct UsartReg UsartReg;

#define ENABLE_USART 		(1<<13)
#define BIT8_LENGTH			~(1<<12)
#define BIT9_LENGTH			(1<<12)

#define ENABLE_PARITY		(1<<10)
#define ODD_PARITY			(1<<9)
#define EVEN_PARITY			~(1<<9)

#define ENABLE_TRANSMIT		(1<<3)
#define DISABLE_TRANSMIT	~(1<<3)
#define ENABLE_RECEIVE		(1<<2)
#define DISABLE_RECEIVE		~(1<<2)

#define OVERSAMPLING8		(1<<15)
#define OVERSAMPLING16		~(1<<15)

#define STOP1				0
#define STOP_HALF			1
#define STOP_DOUBLE			2
#define STOP_1_HALF			3

#define TRANSMIT_DONE 		(1<<6)
#define READY_READ			(1<<5)

#define UART_DMA_Tx_EN		(1<<7)
#define UART_DMA_Rx_EN		(1<<6)

#define usart1EnableDmaTx()		(usart1->CR3 |= UART_DMA_Tx_EN)
#define usart1EnableDmaRx()		(usart1->CR3 |= UART_DMA_Rx_EN)



struct UsartReg{
	volatile uint32_t SR;					//0h
	volatile uint32_t DR;					//4h
	volatile uint32_t BRR;					//8h
	volatile uint32_t CR1;					//ch
	volatile uint32_t CR2;					//10h
	volatile uint32_t CR3;					//14h
	volatile uint32_t GTPR;					//18h

};

void configBaudRate(void);
void initUsart(void);
void writeData(char *data);
void EnableReceiv(void);
void EnableTrans(void);
void DisableReceiv(void);
void DisableTrans(void);
uint8_t ReceiveByte();
void ReceiveTillEnter(char *Data);


#endif /* USART_H_ */
