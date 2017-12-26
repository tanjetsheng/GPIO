/*
 * Rng.c
 *
 *  Created on: Oct 31, 2017
 *      Author: tjs
 */

#include "Rng.h"


void generateRandomNunber(){
	Rng->CR |= RNG_RNGEN;
}

//return 0 is no ready
//return 1 is ready
int isRandomNumberAvailable(){
	return Rng->SR & RNG_DRDY;
}

//return 0 is no error
//return non 0 is error
int isAnyError(){
	return Rng->SR & (RNG_FAULTY_SEQUENCE|RNG_FAULTY_CLK);
}
//find faulty random sequence
//return 0 is no error
//return non 0 is error
int isFaultyRandomSequence(void){
	return Rng->SR & RNG_FAULTY_SEQUENCE;
}
int getRandomNumber(void){
	do{
	generateRandomNunber();
	while(!isRandomNumberAvailable());
	}while(isFaultyRandomSequence());
	return Rng->DR;
}

void getRandomNumberByInterrupt(void){
	Rng->CR |= RNG_RNGEN | RNG_IE;
}
