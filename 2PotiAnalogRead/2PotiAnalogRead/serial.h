/*
 * serial.h
 *
 * Created: 25.04.2020 10:55:22
 *  Author: Denis Denlger, Maximilian Kürschner, David Schader
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_

/* includes */
#include <avr/io.h>
#include <stdint.h>							        // needed for uint8_t
#include <avr/interrupt.h>

/* constants and typedefs */
#define FOSC 16000000								// Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD -1						// Transmitting Speed

typedef void (*func)(void);

/* function prototypes */
void usart_init(func);
void usart_send(uint8_t toSend);
void usart_send_string(char *data);
uint8_t usart_receive();


#endif /* SERIAL_H_ */
