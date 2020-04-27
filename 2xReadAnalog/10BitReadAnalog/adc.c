/*
 * adc.c
 *
 * Created: 27.04.2020 14:53:48
 * Author: Denis Dengler, Maximilian Kürschner, David Schader
 */ 

#include "adc.h"

char* getPoti(int admux_val){
	//admux_val & 1 --> AND with 0001 --> Only last Bit is checked
	//If last bit is 0 --> ADC0
	//else --> ADC1
	return (admux_val & 1) == 0 ? "ADC0" : "ADC1";
}

void adc_init_10(){
	ADMUX = 0;				  // use ADC0
	ADMUX |= (1 << REFS0);    // use AVcc as the reference
	ADMUX &= ~(1 << ADLAR);   // clear for 10 bit resolution

	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // 128 prescale for 16Mhz
	ADCSRA |= (1 << ADATE);   // Set ADC Auto Trigger Enable
		
	ADCSRB = 0;               // 0 for free running mode

	ADCSRA |= (1 << ADEN);    // Enable the ADC
	ADCSRA |= (1 << ADIE);    // Enable Interrupts

	ADCSRA |= (1 << ADSC);    // Start the ADC conversion

	sei();
}
