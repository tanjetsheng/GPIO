/*
 * Timer.c
 *
 *  Created on: Nov 21, 2017
 *      Author: user
 */

#include "Rcc.h"
#include "Timer.h"
#include "Gpio.h"
#include "stdint.h"
#include "dma.h"


void initTimer8(void){
	//enable
	enableTimer8();
	timer8->ARR  = 10000;
	timer8->PSC = 8999;
	timer8->SMCR &= 7 ;
	timer8->CR1 |= COUNTER_ENABLE;
	timer8->CR1 &= UPCOUNTER;
}

void initTimer8_OC(void){
	//enable
	enableTimer8();
	timer8->ARR  = 125;
	timer8->PSC = 1;
	timer8->CCR1 = 12;
	timer8->SMCR &= 7 ;
	timer8->CR1 |= COUNTER_ENABLE;
	timer8->CR1 &= UPCOUNTER;
}
void SetTimer8C1ToOC(){
	//gpioConfig(GpioG,,int mode, int outdriveType,int pullType,int speed);

	timer8->CCMR1 |= OUTPUTCOMPARE_ENABLE;
	timer8->CCER |= OUTPUT_ENABLE;
	timer8->BDTR |= ENABLE_MOE;

}



void forceOutCompareChannel1High(){
	timer8->CCMR1 |= FORCE_HIGH;
	timer8->CCMR1 &= ~(FORCE_HIGH);
}

void forceOutCompareChannel1Low(){

	timer8->CCMR1 |= FORCE_LOW;
	timer8->CCMR1 &= ~(FORCE_LOW);
}

void toggleOutCompareChannel1WithForce(){
	forceOutCompareChannel1High();
	forceOutCompareChannel1Low();
}

void togglemode(){
	timer8->CCMR1 |= TOGGLE;

}

void initTimer8forDma(){
	forceOutCompareChannel1High();
		timer8->CCER |= 1;
		togglemode();
		timer8->DIER |=(1<<9);
		timer8->CCR1 = (timer8->ARR);
		timer8->CNT = (timer8->ARR) - 1;
}



void waittime(int value){
	for(int i= 0;i<value;i++){

	}
}




/*void initTimer8Channel3(){

}
*/
