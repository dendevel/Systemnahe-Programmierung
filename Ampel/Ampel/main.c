/*
 * Ampel.c
 *
 * Created: 16.04.2020 13:54:32
 * Author:  Denis Dengler, Maximilan Kürschner, David Schader
 * Version: 0.0.1
 * Description: Simple program simulating a traffic light
 */ 

#include <avr/io.h>
#include "trafficcontrol.h"

void init(){
	//set PB1-PB3 as output
	DDRB |= (1 << PINB1) | (1 << PINB2) | (1 << PINB3);
}

void mainloop(){
	while (1)
	{
		traffic_light();
	}
}

int main(void)
{	
	init();
	mainloop();
}

