#include "trafficcontrol.h"

void reset_all(void){
	CLEAR_BIT(PORTB, RED);
	CLEAR_BIT(PORTB, YELLOW);
	CLEAR_BIT(PORTB, GREEN);
}

void traffic_light(void){
	//make sure all LEDs are turned off
	reset_all();
	
	//set red LED on HIGH
	SET_BIT(PORTB, RED);
	_delay_ms(1000);

	//set yellow LED on HIGH additionally to red LED
	SET_BIT(PORTB, YELLOW);
	_delay_ms(100);

	//set red and yellow LED to LOW and green to HIGH
	CLEAR_BIT(PORTB, RED);
	CLEAR_BIT(PORTB, YELLOW);
	SET_BIT(PORTB, GREEN);
	_delay_ms(1000);

	//set green LED to LOW and yellow LED to HIGH
	CLEAR_BIT(PORTB, GREEN);
	SET_BIT(PORTB, YELLOW);
	_delay_ms(100);
};