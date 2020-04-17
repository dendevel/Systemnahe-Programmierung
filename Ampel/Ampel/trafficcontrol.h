#ifndef TRAFFICCONTROL_H
#define TRAFFICCONTROL_H

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "bitcontrol.h"

#define RED PINB1
#define YELLOW PINB2
#define GREEN PINB3

extern void reset_all(void);

extern void traffic_light(void);
 
#endif /* TRAFFICCONTROL_H */