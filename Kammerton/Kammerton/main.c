/*
 * Kammerton.c
 *
 * Created: 19.04.2020 08:48:48
 * Author : Denis Dengler, Maximilian Kürschner, David Schader
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


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

void init(){
	
	//set PIND2 & PIND3 as input
	DDRD &= ~(1 << PIND2);
	DDRD &= ~(1 << PIND3);
	
	//set PIND6 as output
	DDRB |= (1 << DDB0);
	
	//set INT0 & INT1 trigger to any logic
	EICRA |= (1 << ISC00) | (1 << ISC10);
	//turn on INT0 & INT1 trigger
	EIMSK |= (1 << INT0) | (1 << INT1);
	
	//set timer mode to CTC
	TCCR0A |= (1 << WGM01);

	//Set the ISR COMPA vect
	TIMSK0 |= (1 << OCIE0A);

	OCR0A = 0;
	
	sei();
	
	//set prescaler to 256 and start timer
	TCCR0B |= (1 << CS02);

	
}


int main(void)
{
    init();

    while (1) 
    {
    }
}

