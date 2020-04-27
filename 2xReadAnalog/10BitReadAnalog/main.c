/*
 * 10BitReadAnalog.c
 *
 * Created: 25.04.2020 14:52:10
 * Author : Denis Dengler, Maximilian Kürschner, David Schader
 * Description: Read analog value from potentiometer with 10 bit resolution
 */ 

/* includes */
#include "serial.h"
#include "adc.h"

/* global variables */
volatile uint16_t ADCvalue;    		// Global variable, set to volatile if used with ISR

/* function implementations */
char* getPoti(int admux_val){
	//admux_val & 1 --> AND with 0001 --> Only last Bit is checked
	//If last bit is 0 --> ADC0
	//else --> ADC1
	return (admux_val & 1) == 0 ? "ADC0" : "ADC1";
}

void echo(){
	usart_send(usart_receive());
}

ISR(ADC_vect)
{
	cli();
	//concatenate HIGH Bits (ADC9 ADC8) to LOW Bits
	ADCvalue = ADCL | (ADCH << 8);
	char buffer [10];
	//convert integer to string
	itoa(ADCvalue, buffer, 10);
	
	usart_send_string(getPoti(ADMUX));
	usart_send_string(": ");
	
	usart_send_string(buffer);
	usart_send_string("\n\r");
	//Toggle MUX0 Bit -> Toggle between ADC0 <-> ADC1
	ADMUX ^= (1 << MUX0);
	sei();
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