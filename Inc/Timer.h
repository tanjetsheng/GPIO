/*
 * Timer.h
 *
 *  Created on: Nov 21, 2017
 *      Author: user
 */

#ifndef TIMER_H_
#define TIMER_H_

#include<stdio.h>

#define TIMER8_BASE_ADDR 	0x40010400
#define timer8      ((TimerReg *)(TIMER8_BASE_ADDR))

typedef struct TimerReg TimerReg;								//channel 1 pc 6, channel 3 pc8
struct TimerReg{
	volatile uint32_t CR1;					//0h
	volatile uint32_t CR2;					//4h
	volatile uint32_t SMCR;					//8h
	volatile uint32_t DIER;					//ch
	volatile uint32_t SR;					//10h
	volatile uint32_t EGR;					//14h
	volatile uint32_t CCMR1;				//18h
	volatile uint32_t CCMR2;				//1ch
	volatile uint32_t CCER;					//20h
	volatile uint32_t CNT;					//24h
	volatile uint32_t PSC;					//28h
	volatile uint32_t ARR;					//2ch
	volatile uint32_t RCR;					//30h
	volatile uint32_t CCR1;					//34h
	volatile uint32_t CCR2;					//38h
	volatile uint32_t CCR3;					//3ch
	volatile uint32_t CCR4;					//40h
	volatile uint32_t BDTR;					//44h
	volatile uint32_t DCR;					//48h
	volatile uint32_t DMAR;					//4ch
};

//cr1
#define UPCOUNTER			~(1<<4)
#define DOWNCOUNTER		 	(1<<4)

#define ENABLE_MOE			(1<<15)

#define FORCE_LOW			(4<<4)
#define FORCE_HIGH			(5<<4)
#define TOGGLE				(3<<4)

#define OUTPUT_ENABLE			1

#define COUNTER_ENABLE			1

#define OUTPUTCOMPARE_ENABLE	(1<<2)

void initTimer8(void);
void SetTimer8C1ToOC();
void forceOutCompareChannel1High();
void forceOutCompareChannel1Low();
void initTimer8_OC(void);
void toggleOutCompareChannel1WithForce();
void sendBitPattern(uint8_t data);
void initTimer8forDma();

void waittime(int value);

#endif /* TIMER_H_ */
