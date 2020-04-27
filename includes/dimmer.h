/*
 * dimmer.h
 *
 * Created: 19.04.2020 17:44:38
 *  Author: Denis Dengler, Maximilian Kürschner, David Schader
 */ 


#ifndef DIMMER_H_
#define DIMMER_H_

/* includes */
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

/* function prototypes */
void pulseStep(int, int);

#endif /* DIMMER_H_ */