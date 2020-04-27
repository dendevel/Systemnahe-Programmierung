/*
 * 10BitReadAnalog.c
 *
 * Created: 25.04.2020 14:52:10
 * Author : Denis Dengler, Maximilian Kürschner, David Schader
 * Description: Read analog value from potentiometer with 10 bit resolution
 */ 

#include <avr/io.h>
#include "serial.h"

#include <stdlib.h>
#include <stdint.h>       		// needed for uint16_t

#include <avr/interrupt.h>


volatile uint16_t ADCvalue;    		// Global variable, set to volatile if used with ISR

void echo(){
	usart_send(usart_receive());
}

int main(void)
{

	ADMUX = 0;                // use ADC0
	ADMUX |= (1 << REFS0);    // use AVcc as the reference
	ADMUX &= ~(1 << ADLAR);   // clear for 10 bit resolution

	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // 128 prescaler for 16Mhz
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
	//concatenate HIGH Bits (ADC9 ADC8) to LOW Bits
	ADCvalue = ADCL | (ADCH << 8);
	char buffer [10];
	//convert integer to string
	itoa(ADCvalue, buffer, 10);
	usart_send_string(buffer);
	usart_send_string("\n\r");
	sei();
}
