/*
 * adc_10_bit.h
 *
 * Created: 27.04.2020 09:47:53
 *  Author: Denis Dengler, Maximilian Kürschner, David Schader
 */ 


#ifndef ADC_10_BIT_H_
#define ADC_10_BIT_H_

#define FOSC 16000000    

#include <avr/io.h>
#include "serial.h"
#include <stdlib.h>
#include <stdint.h>       		// needed for uint8_t
#include <avr/interrupt.h>


void adc_init_10(void);
char* getPoti(int);


#endif /* ADC_10_BIT_H_ */