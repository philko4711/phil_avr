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
