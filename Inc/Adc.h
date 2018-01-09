/*
 * Adc.h
 *
 *  Created on: Jan 2, 2018
 *      Author: user
 */

#ifndef ADC_H_
#define ADC_H_

#include<stdio.h>

#define ADC_BASE_ADDR 	0x40012000
#define adc1      	((AdcReg *)(ADC_BASE_ADDR))
#define adc2      	((AdcReg *)(ADC_BASE_ADDR + 0x100))
#define adc3      	((AdcReg *)(ADC_BASE_ADDR + 0x200))
#define commAdc     ((CommAdcReg *)(ADC_BASE_ADDR + 0x300))

typedef struct AdcReg AdcReg;
struct AdcReg{
	volatile uint32_t SR;					//0h
	volatile uint32_t CR1;					//4h
	volatile uint32_t CR2;					//8h
	volatile uint32_t SMPR1;				//ch
	volatile uint32_t SMPR2;				//10h
	volatile uint32_t JOFR1;				//14h
	volatile uint32_t JOFR2;				//18h
	volatile uint32_t JOFR3;				//1ch
	volatile uint32_t JOFR4;				//20h
	volatile uint32_t HTR;					//24h
	volatile uint32_t LTR;					//28h
	volatile uint32_t SQR1;					//2ch
	volatile uint32_t SQR2;					//30h
	volatile uint32_t SQR3;					//34h
	volatile uint32_t JSQR;					//38h
	volatile uint32_t JDR1;					//3ch
	volatile uint32_t JDR2;					//40h
	volatile uint32_t JDR3;					//44h
	volatile uint32_t JDR4;					//48h
	volatile uint32_t DR;					//4ch
};

typedef struct CommAdcReg CommAdcReg;
struct CommAdcReg{
	volatile uint32_t CSR;					//0h
	volatile uint32_t CCR;					//4h
	volatile uint32_t CDR;					//8h
};


#define ENABLE_ADC   		1
#define SWSTART 			(1<<30)
#define JSWSTART			(1<<22)
#define CONTINUOUS_MODE		(1<<1)

#define REG_EXT_DIS		~(3<<29)
#define REG_EXT_RIS		(1<<29)
#define REG_EXT_FALL	(2<<29)
#define REG_EXT_BOTH	(3<<29)

#define CHANNEL1		1
#define CHANNEL5		5
#define CHANNEL6		6
#define CHANNEL10		10
#define CHANNEL13		13
#define CHANNEL14		14

#define CYCLE_3				0
#define CYCLE_15			1
#define CYCLE_28			2
#define CYCLE_56			3
#define CYCLE_84			4
#define CYCLE_112			5
#define CYCLE_144			6
#define CYCLE_480			7

#define CONV_1				~(20<<15)
#define CONV_2				(20<<1)
#define CONV_4				(20<<4)

#define EOC_bit			(adc1->SR & (1<<1))


void initAdc(void);
void getDataAdc(void);




#define BITS_12			0
#define BITS_10			1
#define BITS_8			2
#define BITS_6			3

#define SCAN_ON				(8<<1)
#define SCAN_OFF			~(8<<1)

#define LEFT_ALIGN			(11<1)
#define RIGHT_ALIGN			~(11<1)




#endif /* ADC_H_ */
