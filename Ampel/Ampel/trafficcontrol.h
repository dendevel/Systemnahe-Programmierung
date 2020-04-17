/*
 * trafficcontrol.h
 *
 * Created: 16.04.2020 13:56:12
 * Author:  Denis Dengler, Maximilan Kürschner, David Schader
 * Version: 0.0.1
 * Description: Implementation of traffic light functions
 */ 

#ifndef TRAFFICCONTROL_H
#define TRAFFICCONTROL_H

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "bitcontrol.h"

/* constant definitions */
#define RED PINB1
#define YELLOW PINB2
#define GREEN PINB3

#define DURATION_RED 1000
#define DURATION_RED_YELLOW 100
#define DURATION_GREEN	1000
#define DURATION_YELLOW 100

/* function prototypes */
extern void reset_all(void);
extern void traffic_light(void);
 
#endif /* TRAFFICCONTROL_H */