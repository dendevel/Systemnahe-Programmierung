/*
 * adc.h
 *
 * Created: 27.04.2020 14:52:18
 *  Author: Denis Dengler, Maximilian Kürschner, David Schader
 */ 


#ifndef ADC_H_
#define ADC_H_

#define FOSC 16000000                       // Clock Speed

#include <avr/io.h>
#include <stdlib.h>
#include <stdint.h>       		// needed for uint8_t and uint16_t
#include <avr/interrupt.h>

void adc_init_10(void);
char* getPoti(int);

#endif /* ADC_H_ */