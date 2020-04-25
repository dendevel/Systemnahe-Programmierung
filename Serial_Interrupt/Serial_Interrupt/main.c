/*
 * Serial_Interrupt.c
 *
 * Created: 25.04.2020 10:29:20
 * Author : dengl
 */ 

// This code waits for a character and transmits the character back (with interrupts)


#include <avr/io.h>
#include <stdint.h>                     // needed for uint8_t

#include <avr/interrupt.h>
#include "serial.h"


#define FOSC 16000000                       // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD -1

void func(){
	usart_send(usart_receive());
}



int main( void )
{
	usart_init(func);
	usart_send_string("hallo_test\n\r");
	while(1)
	{                              // Main loop
	}
}

