/*
 * trafficcontrol.c
 *
 * Created: 16.04.2020 13:57:26
 * Author:  Denis Dengler, Maximilan Kürschner, David Schader
 * Version: 0.0.1
 * Description: Implementation of traffic light functions
 */ 

/* includes */
#include "trafficcontrol.h"

/* function implementations */
void reset_all(void){
	//set all pins to LOW
	CLEAR_BIT(PORTB, RED);
	CLEAR_BIT(PORTB, YELLOW);
	CLEAR_BIT(PORTB, GREEN);
}

void traffic_light(){
	//make sure all LEDs are turned off
	reset_all();
	
	//set red LED on HIGH
	SET_BIT(PORTB, RED);
	_delay_ms(DURATION_RED);

	//set yellow LED on HIGH additionally to red LED
	SET_BIT(PORTB, YELLOW);
	_delay_ms(DURATION_RED_YELLOW);

	//set red and yellow LED to LOW and green to HIGH
	CLEAR_BIT(PORTB, RED);
	CLEAR_BIT(PORTB, YELLOW);
	SET_BIT(PORTB, GREEN);
	_delay_ms(DURATION_GREEN);

	//set green LED to LOW and yellow LED to HIGH
	CLEAR_BIT(PORTB, GREEN);
	SET_BIT(PORTB, YELLOW);
	_delay_ms(DURATION_YELLOW);
};