/*
 * ReadAnalog.c
 *
 * Created: 25.04.2020 13:06:48
 * Author : dengl
 */ 

#include <avr/io.h>
#include "serial.h"

// this code continually scans ADC0 for an analog signal, using 16Mhz processor clock


#include <avr/io.h>
#include <stdlib.h>
#include <stdint.h>       // needed for uint8_t

#include <avr/interrupt.h>


volatile uint8_t ADCvalue;    // Global variable, set to volatile if used with ISR

void echo(){
	usart_send(usart_receive());
}

int main(void)
{

	ADMUX = 0;                // use ADC0
	ADMUX |= (1 << REFS0);    // use AVcc as the reference
	ADMUX |= (1 << ADLAR);    // Right adjust for 8 bit resolution

	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // 128 prescale for 16Mhz
	ADCSRA |= (1 << ADATE);   // Set ADC Auto Trigger Enable
	
	ADCSRB = 0;               // 0 for free running mode

	ADCSRA |= (1 << ADEN);    // Enable the ADC
	ADCSRA |= (1 << ADIE);    // Enable Interrupts

	ADCSRA |= (1 << ADSC);    // Start the ADC conversion

	sei();    // Thanks N, forgot this the first time =P


	usart_init(echo);
	while (1)
	{
		// main loop
		
	}
}


ISR(ADC_vect)
{
	cli();
	ADCvalue = ADCH;          // only need to read the high value for 8 bit
	
	char buffer [10];
	itoa(ADCvalue, buffer, 10);
	usart_send_string(buffer);
	usart_send_string("\n\r");
	sei();
}

