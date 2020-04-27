/*
 * ReadAnalog.c
 *
 * Created: 25.04.2020 13:06:48
 * Author : Denis Dengler, Maximilian Kürschner, David Schader
 * Description: Read value from potentiometer and print in serial monitor
 */ 

#include <avr/io.h>
#include "serial.h"
#include "adc.h"

#include <stdlib.h>
#include <stdint.h>       			// needed for uint8_t

#include <avr/interrupt.h>


volatile uint8_t ADCvalue;    		// Global variable, set to volatile if used with ISR

void echo(){
	usart_send(usart_receive());
}

int main(void)
{
	adc_init_8();
	usart_init(echo);
	
	while (1)
	{
		// main loop
		
	}
}


ISR(ADC_vect)
{
	cli();
	ADCvalue = ADCH;			// only need to read the high value for 8 bit
	
	char buffer [10];
	itoa(ADCvalue, buffer, 10);
	usart_send_string(buffer);
	usart_send_string("\n\r");
	sei();
}

