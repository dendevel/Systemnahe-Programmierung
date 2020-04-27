/*
 * adc.c
 *
 * Created: 27.04.2020 14:53:48
 * Author: Denis Dengler, Maximilian Kürschner, David Schader
 */ 

/* includes */ 
#include "adc.h"

/* function implementations */
void adc_init(){
	ADMUX = 0;					// use ADC0
	ADMUX |= (1 << REFS0);		// use AVcc as the reference
		
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // 128 prescale for 16Mhz
	ADCSRA |= (1 << ADATE);		// Set ADC Auto Trigger Enable
		
	ADCSRB = 0;					// 0 for free running mode

	ADCSRA |= (1 << ADEN);		// Enable the ADC
	ADCSRA |= (1 << ADIE);		// Enable Interrupts
}

void adc_init_10(){	
	adc_init();
	ADMUX &= ~(1 << ADLAR);		// clear for 10 bit resolution
	ADCSRA |= (1 << ADSC);		// Start the ADC conversion
	sei();
}

void adc_init_8(){	
	adc_init();
	ADMUX |= (1 << ADLAR);		// set up for 8 bit resolution
	ADCSRA |= (1 << ADSC);		// Start the ADC conversion
	sei();
}
