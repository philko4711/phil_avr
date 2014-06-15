/*
 * lcd_characteristics.h
 *
 *  Created on: Jun 15, 2014
 *      Author: phil
 */

#ifndef LCD_CHARACTERISTICS_H_
#define LCD_CHARACTERISTICS_H_

#define LCD_BOOTUP_MS           15
#define LCD_ENABLE_US           20
#define LCD_WRITEDATA_US        46
#define LCD_COMMAND_US          42
#define LCD_SOFT_RESET_MS1      5
#define LCD_SOFT_RESET_MS2      1
#define LCD_SOFT_RESET_MS3      1
#define LCD_SET_4BITMODE_MS     5
#define LCD_CLEAR_DISPLAY_MS    2
#define LCD_CURSOR_HOME_MS      2
#define LCD_DDADR_LINE1         0x00
#define LCD_DDADR_LINE2         0x40
#define LCD_DDADR_LINE3         0x10
#define LCD_DDADR_LINE4         0x50

#define LCD_PORT      PORTC
#define LCD_DDR       DDRC
#define LCD_DB        PC0
#define LCD_RS        PC4
#define LCD_EN        PC5

#endif /* LCD_CHARACTERISTICS_H_ */
