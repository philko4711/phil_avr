/*
 * port_init.c
 *
 *  Created on: 21.02.2014
 *      Author: Phil
 */

#include "inits.h"

#include <avr/io.h>
#include <inttypes.h>

void port_init(void)
{
	DDRB  = 0xFC;
}

void init_adc(void)
{
   ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));    //16Mhz/128 = 125Khz the ADC reference clock
   ADMUX |= (1<<REFS0);                //Voltage reference from Avcc (5v)
   ADCSRA |= (1<<ADEN);                //Turn on ADC
   ADCSRA |= (1<<ADSC);                //Do an initial conversion because this one is the slowest and to ensure that everything is up and running

}
