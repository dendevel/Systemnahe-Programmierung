/*
 * lauflicht.c
 *
 * Created: 17.04.2020 13:43:02
 *  Author: Denis Dengler, Maximilian Kürschner, David Schader
 */ 

#include "lauflicht.h"
#include <stdio.h>

//first 6 pins on PortB (index <= 5)
//next 6 pins on PortC (index >= 6)
void setPin(int pinIndex){
	if(pinIndex >= 0 && pinIndex <= 5){
		PORTB = (1 << pinIndex);
		PORTC = 0;
	}
	else if (pinIndex >= 6 && pinIndex <= 11){
		PORTB = 0;
		PORTC = (1 << (pinIndex - 6));
	}
}

//LEDs
//1-6 on PortB
//7-10 on PortC
void lauflicht(int min, int max){
	static int dir = 1;
	static int pin = 0;
	//set light direction
	//if maximum or minimum reached, change direction, else keep 
	dir = ((pin == max && dir > 0) || (pin == min && dir < 0)) ? -dir : dir;
	setPin(pin);
	_delay_ms(INTERVAL);
	pin += dir;
}
