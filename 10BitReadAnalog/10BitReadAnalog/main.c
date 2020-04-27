/*
 * 10BitReadAnalog.c
 *
 * Created: 25.04.2020 14:52:10
 * Author : Denis Dengler, Maximilian Kürschner, David Schader
 * Description: Read analog value from potentiometer with 10 bit resolution
 */ 

/* includes */
#include <avr/io.h>
#include "serial.h"
#include "adc.h"

#include <stdlib.h>
#include <stdint.h>       			// needed for uint16_t

#include <avr/interrupt.h>

/* global variables */
volatile uint16_t ADCvalue;    			// Global variable, set to volatile if used with ISR

void echo(){
	usart_send(usart_receive());
}

int main(void)
{  
	adc_init_10();
	usart_init(echo);
	
	while (1)
	{
		// main loop
		
	}
}

ISR(ADC_vect)
{
	cli();
	//concatenate HIGH Bits (ADC9 ADC8) to LOW Bits
	ADCvalue = ADCL | (ADCH << 8);
	char buffer [10];
	//convert integer to string
	itoa(ADCvalue, buffer, 10);
	usart_send_string(buffer);
	usart_send_string("\n\r");
	sei();
}
