/*
 * 2PotiAnalogRead.c
 *
 * Created: 25.04.2020 15:58:00
 * Author : Denis Denlger, Maximilian Kürschner, David Schader
 * Description: Read analog value from two potentiometers
 */ 

#include <avr/io.h>
#include "serial.h"

#include <stdlib.h>
#include <stdint.h>					// needed for uint8_t

#include <avr/interrupt.h>


volatile uint8_t ADCvalue;    		// Global variable, set to volatile if used with ISR

void echo(){
	usart_send(usart_receive());
}

int main(void)
{

	ADMUX = 0;	// start with ADC0
	ADMUX |= (1 << REFS0);				// use AVcc as the reference
	ADMUX &= ~(1 << ADLAR);				// clear for 10 bit resolution

	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // 128 prescale for 16Mhz
	ADCSRA |= (1 << ADATE);   // Set ADC Auto Trigger Enable
	
	ADCSRB = 0;               // 0 for free running mode

	ADCSRA |= (1 << ADEN);    // Enable the ADC
	ADCSRA |= (1 << ADIE);    // Enable Interrupts

	ADCSRA |= (1 << ADSC);    // Start the ADC conversion

	sei();
	
	usart_init(echo);
	
	while (1)
	{
		// main loop
	}
}


ISR(ADC_vect)
{
	cli();
	
	char buffer[10];
	uint8_t tmp;            // temp register for storage of misc data

	tmp = ADMUX;            // read the value of ADMUX register
	tmp &= 0x0F;            // AND the first 4 bits (value of ADC pin being used)

	ADCvalue = ADCH;        // read the sensor value

	if (tmp == 0){			//Poti at A0
		//concatenate HIGH Bits (ADC9 ADC8) to LOW Bits
		ADCvalue = ADCL | (ADCH << 8);
		//convert integer to string
		itoa(ADCvalue, buffer, 10);
		usart_send_string("Poti - A0: ");
		usart_send_string(buffer);
		ADMUX++;            // add 1 to ADMUX to go to the next sensor
	}
	 
	else if (tmp == 1){			//Poti at A1
		//concatenate HIGH Bits (ADC9 ADC8) to LOW Bits
		ADCvalue = ADCL | (ADCH << 8);
		//convert integer to string
		itoa(ADCvalue, buffer, 10);
		usart_send_string("   Poti - A1: ");
		usart_send_string(buffer);
		usart_send_string("\n\r");
		ADMUX &= 0xF8;      // clear the last 4 bits to reset the mux to ADC0
	}
	 
	sei();
}
