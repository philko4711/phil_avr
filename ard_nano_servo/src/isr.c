/*
 * isr.c
 *
 *  Created on: 23.02.2014
 *      Author: phil
 */

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "inits.h"
#include "uart.h"

extern volatile uint8_t _pulse;

ISR(TIMER0_OVF_vect)
{
  cli();
  //PORTB = 0x00;
  static volatile uint16_t ctr = 0;
  TCNT0 = TCNT0_PRESET;
  if(ctr < _pulse)
    PORTB |=  (1 << PORTB5) | (1 << PORTB4);   //switch pins 4,5 ON
  else
    PORTB &= ~((1 << PORTB5) | (1 << PORTB4)); //switch pins 4, 5 OFF
  if(ctr++ == T_PER)        //period duration
    ctr = 0;
  sei();
}

ISR(USART_RX_vect)
{
    cli();
    uint8_t data = UDR0;

    //debug
    send_char(data);

    sei();
}

