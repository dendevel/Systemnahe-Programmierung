/*
 * Lauflicht.c
 *
 * Created: 17.04.2020 12:45:59
 * Author : Denis Dengler, Maximilian Kürschner, David Schader
 * Version: 0.0.1
 * Description: program to light up several count of LEDs in a row successively. If end reached, direction is changed.
 */ 

#include <avr/io.h>
#include "lauflicht.h"

void init() {
	// set pins PB0-PB5 as output
	DDRB = 0b00111111;
	// set pins PC0-PC5 as output
	DDRC = 0b00111111;
	
}

int main(void)
{
	init();	
    while(1){
		lauflicht(0,7);
    }
}

