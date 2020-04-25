/*
 * serial.h
 *
 * Created: 25.04.2020 10:55:22
 *  Author: dengl
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_

void usart_init();
void usart_send(uint8_t toSend);
void usart_send_string(char *data);
uint8_t usart_receive();


#endif /* SERIAL_H_ */