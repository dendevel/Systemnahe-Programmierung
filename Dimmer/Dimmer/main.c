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
	// PB1 is now an output
	DDRB |= (1 << DDB1);

	// set PWM for 100% duty cycle
	OCR1A = 255;

	// set none-inverting mode
	TCCR1A |= (1 << COM0A1);

	// set fast PWM Mode
	TCCR1A |= (1 << WGM01) | (1 << WGM00) | (1 << WGM02);

	// set prescaler to 8 and start PWM
	TCCR1B |= (1 << CS01);
}


int main(void)
{
	init();
	
	while (1)
	{
		pulseStep(0,255);
	}
}

