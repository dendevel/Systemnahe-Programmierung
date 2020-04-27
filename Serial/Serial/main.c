/*
 * Serial.c
 *
 * Created: 25.04.2020 10:24:50
 * Author : Denis Dengler, Maximilian Kürschner, David Schader
 */ 

// This code waits for a character and transmits the character back (No interrupts)

/* includes */
#include <avr/io.h>
#include <stdint.h>                     // needed for uint8_t

/* constants and typedefs */
#define FOSC 16000000                   // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD -1			//Transmitting Speed

/* global variables */
char ReceivedChar;

void init(){
	/*Set baud rate */
	UBRR0H = (MYUBRR >> 8);
	UBRR0L = MYUBRR;
		
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);      // Enable receiver and transmitter
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);    // Set frame: 8data, 1 stp
}

int main( void )
{
	while(1)
	{
		//The RXC(RXCn) bit (Receive Complete) will be set to HIGH(1) when data has been received and is available in the UDR (UDR0) buffer. 
		while ( !(UCSR0A & (1 << RXC0)) ){}		// Wait until data is received
		
		ReceivedChar = UDR0;                    // Read the data from the RX buffer
		
		//The UDRE(UDREn) is set to HIGH(1) when the buffer (UDR/UDRn) is empty, and therefore ready to be written. 
		while ( !(UCSR0A & (1 << UDRE0)) ){} // Wait until buffer is empty

		UDR0 = ReceivedChar;                    // Send the data to the TX buffer
	}
}
