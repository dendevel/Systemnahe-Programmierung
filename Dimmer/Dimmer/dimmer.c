/*
 * dimmer.c
 *
 * Created: 19.04.2020 17:45:00
 *  Author: Denis Dengler, Maximilian Kürschner, David Schader
 */ 

#include "dimmer.h"

/* increasing and decreasing brightness of led between min and max value depending on direction */
void pulseStep(int min, int max){
	static int direction = 1;
	static int brightness = 0;	
	
	direction = ((brightness == max && direction > 0) || (brightness == min && direction < 0)) ? -direction : direction;
	OCR0A = brightness;
	_delay_ms(10);
	brightness += direction;
}
