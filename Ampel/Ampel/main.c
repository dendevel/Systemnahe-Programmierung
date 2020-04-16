/*
 * Ampel.c
 *
 * Created: 16.04.2020 13:54:32
 * Author : dengl
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include "trafficcontrol.h"

int main(void)
{
	//set PB1-PB3 as output
	DDRB |= (1 << PINB1) | (1 << PINB2) | (1 << PINB3);
	
    /* Replace with your application code */
    while (1) 
    {
		traffic_light();
    }
}

