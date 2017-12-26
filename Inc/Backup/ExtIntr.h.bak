/*
 * ExtIntr.h
 *
 *  Created on: Nov 7, 2017
 *      Author: user
 */

#ifndef EXTINTR_H_
#define EXTINTR_H_

#include <stdint.h>

#define EXTI_BASE_ADDR 	0x40013C00
#define ExtI      ((ExtIReg *)(EXTI_BASE_ADDR))


typedef struct ExtIReg ExtIReg;
struct ExtIReg{
	volatile uint32_t IMR;			//interrupt
	volatile uint32_t EMR;			//event
	volatile uint32_t RTSR;			//rising trigger
	volatile uint32_t FTSR;			//falling trigger
	volatile uint32_t SWIER;		//softWare interrupt
	volatile uint32_t PR;			//pending
};

#define interMaskEnable(bit)		(ExtI->IMR |= (1 << bit))
#define interMaskEDisable(bit)		(ExtI->IMR &= ~(1 << bit))
#define eventMaskEnable(bit)		(ExtI->EMR |= (1 << bit))
#define eventMaskDisable(bit)		(ExtI->EMR &= ~(1 << bit))
#define risingEnable(bit)			(ExtI->RTSR |= (1 << bit))
#define risingDisable(bit)			(ExtI->RTSR &= ~(1 << bit))
#define fallingEnable(bit)			(ExtI->FTSR |= (1 << bit))
#define fallingDisable(bit)			(ExtI->FTSR &= ~(1 << bit))
#define softwareIntr(bit)			(ExtI->SWIER |= (1 << bit))
#define readPending()				(ExtI->PR)
#define clearPending(bit)			(ExtI->PR |= (bit))





#endif /* EXTINTR_H_ */
