/*
 * kammerton.h
 *
 * Created: 24.04.2020 17:48:47
 *  Author: Denis Dengler, Maximilian Kürschner, David Schader
 */ 


#ifndef KAMMERTON_H_
#define KAMMERTON_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void kammerton(void);


#endif /* KAMMERTON_H_ */