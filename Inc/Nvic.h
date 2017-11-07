/*
 * Nvic.h
 *
 *  Created on: Oct 31, 2017
 *      Author: user
 */

#ifndef NVIC_H_
#define NVIC_H_

#include <stdint.h>

#define NVIC_BASE_ADDR 0xE000E100
#define Nvic      ((NvicReg *)(NVIC_BASE_ADDR))

typedef struct NvicReg NvicReg;
struct NvicReg{
	volatile uint32_t ISER[3];				//interrupt set enable   0h
	volatile uint32_t reserve1[29];
	volatile uint32_t ICER[3];				//interrupt clear enable  80h
	volatile uint32_t reserve2[29];
	volatile uint32_t ISPR[3];				//interrupt set pending 	100h
	volatile uint32_t reserve3[29];
	volatile uint32_t ICPR[3];				//interrupt clear pending   180h
	volatile uint32_t reserve4[29];
	volatile uint32_t IABRR[3];				//interrupt active bit	200h
	volatile uint32_t reserve5[61];
	volatile uint32_t IPR[21];				//interrupt priority 300h
	volatile uint32_t reserve6[683];
	volatile uint32_t STIR;					//trigger interrupt	 e00h
};

#define nvicEnableIrq(irqNum)					(Nvic->ISER[irqNum >> 5] |= 1 << (irqNum & 0x1f))
#define nvicDisableIrq(irqNum)					(Nvic->ICER[irqNum >> 5] |= 1 << (irqNum & 0x1f))
#define nvicSetPriority(irqNum,priority)		(Nvic->IPR[irqNum >>  2] |= priority << ((irqNum & 0x3) * 8 + 4))



#endif /* NVIC_H_ */
