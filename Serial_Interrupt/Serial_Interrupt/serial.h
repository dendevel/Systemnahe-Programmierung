/*
 * serial.h
 *
 * Created: 25.04.2020 10:55:22
 * Author: Denis Dengler, Maximilian Kürschner, David Schader
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_

#include <avr/io.h>
#include <stdint.h>                     // needed for uint8_t
#include <avr/interrupt.h>

#define FOSC 16000000                   // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD -1          //Transmitting Speed


/* function prototypes */
void usart_init(void (*fun)());
void usart_send(uint8_t toSend);
void usart_send_string(char *data);
uint8_t usart_receive();


#endif /* SERIAL_H_ */
