/*
 * serial.c
 *
 * Created: 25.04.2020 10:57:01
 *  Author: Denis Denlger, Maximilian Kürschner, David Schader
 */

/* includes */ 
#include "serial.h"

/* global variables */
func f;


/* function implementations */
void usart_init(func function){
	/*Set baud rate */
	f = function;
	UBRR0H = (MYUBRR >> 8);
	UBRR0L = MYUBRR;
		
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);      // Enable receiver and transmitter
	UCSR0B |= (1 << RXCIE0);                    // Enable receiver interrupt
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);    // Set frame: 8data, 1 stp

	sei();                                      // Enable interrupts
}

void usart_send(uint8_t toSend){
	 while ( !(UCSR0A & (1 << UDRE0)) ){}
		UDR0 = toSend;							// Write the data to the TX buffer
}

void usart_send_string(char *data){
	while(*data){
		usart_send(*data++);
	}
}

uint8_t usart_receive(){
	while ( !(UCSR0A & (1 << RXC0)) ){}
	return (uint8_t)UDR0;                       // Read data from the RX buffer
}

ISR (USART_RX_vect){
	f();
}