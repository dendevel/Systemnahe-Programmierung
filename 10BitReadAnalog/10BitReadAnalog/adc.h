/*
 * adc.h
 *
 * Created: 27.04.2020 14:52:18
 *  Author: Denis Dengler, Maximilian Kürschner, David Schader
 */ 


#ifndef ADC_H_
#define ADC_H_

#define FOSC 16000000               // Clock Speed

/* includes */
#include <avr/io.h>
#include <stdlib.h>
#include <stdint.h>       			// needed for uint8_t and uint16_t
#include <avr/interrupt.h>

/* function prototypes */
void adc_init_10(void);
void adc_init_8(void);

#endif /* ADC_H_ */