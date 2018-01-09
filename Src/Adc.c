/*
 * Adc.c
 *
 *  Created on: Jan 2, 2018
 *      Author: user
 */

#include "Adc.h"
#include "Gpio.h"

void initAdc(void){
	 gpioConfig(GpioA,5, GPIO_MODE_ANA , GPIO_PUSH_PULL,GPIO_NO_PULL,GPIO_VHIGH_SPEED);
	 gpioConfig(GpioC,3, GPIO_MODE_ANA , GPIO_PUSH_PULL,GPIO_NO_PULL,GPIO_VHIGH_SPEED);

	//adc1->CR1|=CHANNEL5;
	adc1->CR2 = ENABLE_ADC|CONTINUOUS_MODE;
	adc1->SQR1 = CONV_2;
	adc1->SQR3 = CHANNEL5|(5<<CHANNEL13);
	adc1->SMPR2 |= (15<<CYCLE_480);
	adc1->SMPR1 |= (9<<CYCLE_15);
	adc1->CR2 |= SWSTART;

}


void getDataAdc(void){
	while(EOC_bit ==0){
	}
	int data = adc1->DR;
	float ana = ((3.3 * data)/(4096.0));
	printf("Voltage = %.4fV\n",ana);
	adc1->SR &= ~(1<<26);
	adc1->CR2 |= SWSTART;
}



void configAdc(void){
	adc1->CR1 = BITS_10|SCAN_ON;
	adc1->SQR1 = CONV_4;
	adc1->SQR3 = CHANNEL1|(CHANNEL6<<5)|(CHANNEL10<<10)|(CHANNEL14<<15);
	adc1->CR2 |= LEFT_ALIGN;
	adc1->CR2 |= SWSTART;
}



void adcSetChannelSamplingSequaence(AdcReg *adc,int channels[],int numofChan){
	adc->SQR1 |= (20<<numofChan);		//setting the total number of convertion
	for(int i=0;i<numofChan;i++){		//loop total number of channel that
										// we wanted to insert
		if(i<6){
			adc->SQR3 |= (channels[i]<<i*5);

		}
		else if(6<i<12){
			adc->SQR2 |= (channels[i]<<(i-7)*5);
		}
		else{
			adc->SQR3 |= (channels[i]<<(i-13)*5);
		}
	}
}

void adcChannelsamplingTime(AdcReg *adc,int channel,int cycles){
	if(channel>9){
			adc->SMPR1 = (cycles<<(channel-10)*3);
		}
		else if(channel<9)
		{
			adc-> SMPR2 = (cycles<<(channel*3));
		}

}
