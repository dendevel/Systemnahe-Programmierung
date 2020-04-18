/*
 * lauflicht.h
 *
 * Created: 17.04.2020 13:42:50
 *  Author: Denis Dengler, Maximilian K�rschner, David Schader
 */ 


#ifndef LAUFLICHT_H_
#define LAUFLICHT_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


/* const definitions */
#define INTERVAL 1000

/* function prototypes */
extern void lauflicht(int,int);

#endif /* LAUFLICHT_H_ */