/*
 * Serial_Interrupt.c
 *
 * Created: 25.04.2020 10:29:20
 * Author : Denis Dengler, Maximilian Kürschner, David Schader
 * Description: Using serial pins for echo function
 */ 

/* includes */
#include "serial.h"

/* function implementations */
void echo(){
	usart_send(usart_receive());
}


int main( void )
{
	usart_init(echo);
	//test string
	usart_send_string("hallo_test\n\r");
	
	while(1)
	{   
		// Main loop
	}
}

