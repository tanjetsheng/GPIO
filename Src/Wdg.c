/*
 * Iwdg.c
 *
 *  Created on: Jan 9, 2018
 *      Author: user
 */


#include "Wdg.h"

void initIwdg(int reloadValue){
	Iwdg->KR = START_KEY;
	Iwdg->KR = ENABLE_ACCESS;
	Iwdg->PR = PRESCALE_64;
	Iwdg->RLR = reloadValue;

	waitReload();
	waitPrescale();
}


void initWwdg(int value){
	Wwdg->CR = ACTIVATE|CR_T6|(value & ~WND_MASK);

}



void set(int value){
	Wwdg->CFR &= WND_MASK;
	Wwdg->CFR |= (value & ~WND_MASK);

}

void setDivider(int value){
	Wwdg->CFR |= (value<<7);
}

void enableWwdgIntrerrupt(){
	Wwdg->CFR |= WAKEUPINTR;
}
