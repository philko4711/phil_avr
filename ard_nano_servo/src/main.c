/*
 * main.c
 *
 *  Created on: 21.02.2014
 *      Author: Phil
 */

#include <avr/io.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

#include "inits.h"
#include "uart.h"

volatile uint8_t _pulse;

int main(void)
{
	cli();
	port_init();
	init_timer0();
	init_uart(UBRR_VAL);
	sei();
	_pulse = 4;
	PORTB |= (1 << PORTB5);
	while(1)
	{
	  send_number(_pulse);
	  _pulse += 1;
	  if(_pulse == 20)
	    _pulse = 4;
	  _delay_ms(1000);
	}
}

