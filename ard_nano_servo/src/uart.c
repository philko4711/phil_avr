/*
 *uart.c
 *
 *  Created on: 23.02.2014
 *      Author: phil
 */

#include "uart.h"

#include <avr/io.h>
#include <string.h>

void init_uart(uint16_t ubrr)
{
  /*Set baud rate */
  UBRR0H = (unsigned char)(ubrr>>8);
  UBRR0L = (unsigned char)ubrr;
  /*Enable receiver and transmitter and receiver interrupt*/
  UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
  /* Set frame format: 8data, 1stop bit */
  UCSR0C = (0<<USBS0)|(3<<UCSZ00);
}

void send_char(uint8_t c)
{
  while (!( UCSR0A & (1<<UDRE0)))
    ;
  UDR0 = c;
}

void send_string(uint8_t* string)
{
  volatile uint8_t i = 0;
  for(i = 0; i < strlen(string); i++)
    send_char(string[i]);
}

void send_number(uint8_t number)
{
  send_char(number + 48);
}
