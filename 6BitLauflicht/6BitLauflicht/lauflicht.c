/*
 * lauflicht.c
 *
 * Created: 17.04.2020 13:43:02
 *  Author: Denis Dengler, Maximilian Kürschner, David Schader
 */ 

#include "lauflicht.h"


/* IDEA:
function, which calculates which port has to be used by given minimum and maximum index*/


void lauflicht(int min, int max){
	static int dir = 1;
	static int pin = 0;
	//set light direction
	//if maximum or minimum reached, change direction, else keep 
	dir = ((pin == max && dir > 0) || (pin == min && dir < 0)) ? -dir : dir;
	PORTB = (1 << pin);
	_delay_ms(INTERVAL);
	pin += dir;
}
