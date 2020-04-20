/*
 * Dimmer.c
 *
 * Created: 19.04.2020 08:50:20
 * Author : Denis Dengler, Maximilian Kürschner, David Schader
 * Description: pulsating led
 */ 

#include <avr/io.h>
#include "dimmer.h"

void init(void){
	// PD6 is now an output
	DDRD |= (1 << DDD6);

	// set PWM for 100% duty cycle
	OCR0A = 255;

	// set none-inverting mode
	TCCR0A |= (1 << COM0A1);

	// set fast PWM Mode, TOP=0xFF
	TCCR0A |= (1 << WGM01) | (1 << WGM00);

	// set prescaler to 8 and start PWM
	TCCR0B |= (1 << CS01);
}


int main(void)
{
	init();
	
	while (1)
	{
		pulseStep(0,255);
	}
}

