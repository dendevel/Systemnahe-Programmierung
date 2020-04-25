/*
 * serial.c
 *
 * Created: 25.04.2020 10:57:01
 *  Author: Denis Dengler, Maximilian Kürschner, David Schader
 */ 

#include "serial.h"

func func_ptr;

void usart_init(func function){
	//set function pointer
	func_ptr = function;
	
	/*Set baud rate */
	UBRR0H = (MYUBRR >> 8);
	UBRR0L = MYUBRR;
		
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);      // Enable receiver and transmitter
	UCSR0B |= (1 << RXCIE0);                    // Enable receiver interrupt
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);    // Set frame: 8data, 1 stp

	sei();                                      // Lets not forget to enable interrupts =P
}

void usart_send(uint8_t toSend){
	//wait for empty buffer
	while ( !(UCSR0A & (1 << UDRE0)) ){}
	UDR0 = toSend;                       	    // Write the data to the TX buffer
}

void usart_send_string(char *data){
	while(*data){
		usart_send(*data++);
	}
}

uint8_t usart_receive(){
	//wait until data is received
	while ( !(UCSR0A & (1 << RXC0)) ){}
	return (uint8_t)UDR0;                       // Read data from the RX buffer
}

ISR (USART_RX_vect){
	func_ptr();
}
