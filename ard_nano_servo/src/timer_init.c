/*
 * timer_init.c
 *
 *  Created on: 23.02.2014
 *      Author: phil
 */

#include "inits.h"

#include <avr/io.h>

void init_timer0(void)
{
  TCCR0A = 0x00;
  TCCR0B |=  (1 << CS02);// | (1 << CS00);          //set prescaler to 1/256
  TIMSK0 |= (1 << TOIE0);         //enable timer0 overflow interrupt
  TCNT0 = TCNT0_PRESET;
}


