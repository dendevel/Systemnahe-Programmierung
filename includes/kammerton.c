/*
 * kammerton.c
 *
 * Created: 24.04.2020 17:48:02
 *  Author: Denis Dengler, Maximilian Kürschner, David Schader
 */ 

/* includes */
#include "kammerton.h"

/* function implementations */
ISR (INT0_vect){
	//set timer TOP to 70 (tone A)
	OCR0A = 70;
}

ISR (INT1_vect){
	//set timer TOP to 117 (tone C)
	OCR0A = 117;
}

ISR (TIMER0_COMPA_vect){
	//invert pins
	PORTB = ~PORTB;
}

void kammerton(){
	
	//set PIND2 & PIND3 as input
	DDRD &= ~(1 << PIND2);
	DDRD &= ~(1 << PIND3);
	
	//set PINB0 as output
	DDRB |= (1 << DDB0);
	
	//set INT0 & INT1 trigger to any logic
	EICRA |= (1 << ISC00) | (1 << ISC10);
	//turn on INT0 & INT1 trigger
	EIMSK |= (1 << INT0) | (1 << INT1);
	
	//set timer mode to CTC
	TCCR0A |= (1 << WGM01);

	//Set the ISR COMPA vect
	TIMSK0 |= (1 << OCIE0A);

	//starting tone A
	OCR0A = 70;
	
	//enable interrupts
	sei();
	
	//set prescaler to 256 and start timer
	TCCR0B |= (1 << CS02);
}

