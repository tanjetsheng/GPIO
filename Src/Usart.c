/*
 * Usart.c
 *
 *  Created on: Dec 12, 2017
 *      Author: user
 */

#include "Usart.h"
#include "stdio.h"

// Enable the USART by writing the UE bit in USART_CR1 register to 1.
//Program the M bit in USART_CR1 to define the word length.
//Program the number of stop bits in USART_CR2.
//Select DMA enable (DMAT) in USART_CR3 if Multi buffer Communication is to take place.
//Configure the DMA register as explained in multibuffer communication.
//Select the desired baud rate using the USART_BRR register.
//Set the TE bit in USART_CR1 to send an idle frame as first transmission.
//Write the data to send in the USART_DR register (this clears the TXE bit).
//Repeat this for each data to be transmitted in case of single buffer
//After writing the last data into the USART_DR register, wait until TC=1. This indicates that
//the transmission of the last frame is complete. This is required for
//instance when the USART is disabled or enters the Halt mode to avoid corrupting
// the last transmission.


void initUsart(void){
	usart1->CR1 = ENABLE_USART | BIT9_LENGTH | ODD_PARITY | ENABLE_PARITY;
	usart1->CR1 &= OVERSAMPLING16;
	usart1->CR2 |= (STOP_DOUBLE<<12);
	usart1->CR3 |= UART_DMA_Tx_EN;

}

void EnableTrans(void){
	usart1->CR1 |= ENABLE_TRANSMIT;
}

void EnableReceiv(void){
	usart1->CR1 |= ENABLE_RECEIVE;
}

void DisableTrans(void){
	usart1->CR1 &= DISABLE_TRANSMIT;
}

void DisableReceiv(void){
	usart1->CR1 |= DISABLE_RECEIVE;
}


void configBaudRate(void){
	usart1->BRR = (0xD) | (0x30<<4);

}


void writeData(char *data){
	while((((usart1->SR)>>7)*0x01)!=1){
	}
	usart1->DR = *data;
}

uint8_t ReceiveByte(){
	while(!(usart1->SR & READY_READ));
	return (uint8_t)usart1->DR;
}

void ReceiveTillEnter(char *Data){
	*(Data) = ReceiveByte();
	while(*(Data)!=0xA){
		Data++;
		*(Data) = ReceiveByte();
	}
	*Data=0;
}
