/*
 * Timer.c
 *
 *  Created on: Nov 21, 2017
 *      Author: user
 */

#include "Rcc.h"
#include "Timer.h"


void initTimer8(void){
	//enable
	enableTimer8();
	timer8->ARR  = 10000;
	timer8->PSC = 8999;
	timer8->SMCR &= 7 ;
	timer8->CR1 |= 1;
}

void initTimer8Channel1(){
	//gpioConfig(GpioG,,int mode, int outdriveType,int pullType,int speed);
}

void initTimer8Channel3(){

}
