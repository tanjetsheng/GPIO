/*
 * Dma.c
 *
 *  Created on: Dec 19, 2017
 *      Author: user
 */

#include "Dma.h"
#include "Common.h"

//DMA2 stream2.ch4=USART1_RX
//DMA2 stream7.ch4=USART1_TX

//PSIZE = 1byte
//MSIZE = 1byte

//MBURST = IN 8 beat INCREAMENT
//FIFO BURST = 1/2 	THRESHOLD

//PINC = no
//MINC = yes

//circular mode = no
//double buffering = no

//flow controller = DMA

//transfer direction = memory to peripheral ->transmit
//transfer direction = peripheral to memory ->receive

//priority = high






int dmaStreamCheckFlag(DmaReg *dma,int streamNum,int flag){
	int isUpper16 = 0;
	volatile uint32_t *intrStatusReg = &dma1->LISR;
	if(streamNum>=4){
		intrStatusReg = &dma1->HISR;
		streamNum -= 4;
	}
	if(streamNum >= 2){
		streamNum -= 2;
		isUpper16 = TRUE;
	}

	return *intrStatusReg & (flag <<(6 *streamNum + 16 * isUpper16));
}



void dmaIntiForUsart1(){
	char *value="hello world";
	dma2->S[2].CR &= ~ENABLE_STREAM ;
	dma2->S[2].CR = (PERI_TO_MEM<<6) | (ONE_BYTE<<11) | (ONE_BYTE<<13) | (HIGH_PRIO << 16) |(INC8 << 23) | (4 << 25) |(1<<10);

	dma2->S[7].CR &= ~ENABLE_STREAM ;
	dma2->S[7].CR = (MEM_TO_PERI<<6) | (ONE_BYTE<<11) | (ONE_BYTE<<13) | (HIGH_PRIO << 16) |(INC8 << 23) | (4 << 25) |(1<<10);

	dma2->S[2].FCR |= HALF_FIFO;
	dma2->S[7].FCR |= HALF_FIFO;

	dma2->S[2].PAR = &(usart1->DR);
	dma2->S[7].PAR = &(usart1->DR);

	//dma2->S[2].NDTR = 8;
	dma2->S[7].NDTR = strlen(value);

	dma2->S[2].M0AR = value;
	dma2->S[7].M0AR = value;

	dma2->S[2].CR |= ENABLE_STREAM ;
	dma2->S[7].CR |= ENABLE_STREAM ;

}

void dmaTransmitData(char *value){
	dma2->S[2].M0AR = value;
	dma2->S[7].M0AR = value;
}

void dmaSetAddressAndSize(uint32_t memoryAddr,uint32_t peripheralAddr,uint32_t size){

}
