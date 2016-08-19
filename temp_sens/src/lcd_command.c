/*
 * lcd_command.c
 *
 *  Created on: Jun 15, 2014
 *      Author: phil
 */

#include "lcd_command.h"
#include "lcd_characteristics.h"

#include <avr/io.h>
#include <util/delay.h>

void lcd_enable(void)
{
    LCD_PORT |= (1 << LCD_EN);     // Enable auf 1 setzen
    _delay_us(LCD_ENABLE_US);  // kurze Pause
    LCD_PORT &= ~(1 << LCD_EN);    // Enable auf 0 setzen
}

void lcd_out(uint8_t data)
{
    data &= 0xF0;                       // obere 4 Bit maskieren

    LCD_PORT &= ~(0xF0>>(4-LCD_DB));    // Maske löschen
    LCD_PORT |= (data>>(4-LCD_DB));     // Bits setzen
    lcd_enable();
}

void lcd_init( void )
{
    // verwendete Pins auf Ausgang schalten
    uint8_t pins = (0x0F << LCD_DB) |           // 4 Datenleitungen
                   (1<<LCD_RS) |                // R/S Leitung
                   (1<<LCD_EN);                 // Enable Leitung
    LCD_DDR |= pins;

    // initial alle Ausgänge auf Null
    LCD_PORT &= ~pins;

    // warten auf die Bereitschaft des LCD
    _delay_ms( LCD_BOOTUP_MS );

    // Soft-Reset muss 3mal hintereinander gesendet werden zur Initialisierung
    lcd_out( LCD_SOFT_RESET );
    _delay_ms( LCD_SOFT_RESET_MS1 );

    lcd_enable();
    _delay_ms( LCD_SOFT_RESET_MS2 );

    lcd_enable();
    _delay_ms( LCD_SOFT_RESET_MS3 );

    // 4-bit Modus aktivieren
    lcd_out( LCD_SET_FUNCTION |
             LCD_FUNCTION_4BIT );
    _delay_ms( LCD_SET_4BITMODE_MS );

    // 4-bit Modus / 2 Zeilen / 5x7
    lcd_command( LCD_SET_FUNCTION |
                 LCD_FUNCTION_4BIT |
                 LCD_FUNCTION_2LINE |
                 LCD_FUNCTION_5X7 );

    // Display ein / Cursor aus / Blinken aus
    lcd_command( LCD_SET_DISPLAY |
                 LCD_DISPLAY_ON |
                 LCD_CURSOR_OFF |
                 LCD_BLINKING_OFF);

    // Cursor inkrement / kein Scrollen
    lcd_command( LCD_SET_ENTRY |
                 LCD_ENTRY_INCREASE |
                 LCD_ENTRY_NOSHIFT );

    lcd_clear();
}

void lcd_data(uint8_t data)
{
    LCD_PORT |= (1<<LCD_RS);    // RS auf 1 setzen

    lcd_out( data );            // zuerst die oberen,
    lcd_out( data<<4 );         // dann die unteren 4 Bit senden

    _delay_us( LCD_WRITEDATA_US );
}

void lcd_command(uint8_t data)
{
    LCD_PORT &= ~(1<<LCD_RS);    // RS auf 0 setzen

    lcd_out( data );             // zuerst die oberen,
    lcd_out( data<<4 );           // dann die unteren 4 Bit senden

    _delay_us( LCD_COMMAND_US );
}

void lcd_clear( void )
{
    lcd_command( LCD_CLEAR_DISPLAY );
    _delay_ms( LCD_CLEAR_DISPLAY_MS );
}

void lcd_home( void )
{
    lcd_command( LCD_CURSOR_HOME );
    _delay_ms( LCD_CURSOR_HOME_MS );
}

void lcd_string( const char *data )
{
    while( *data != '\0' )
        lcd_data( *data++ );
}

void lcd_setcursor( uint8_t x, uint8_t y )
{
    uint8_t data;

    switch (y)
    {
        case 1:    // 1. Zeile
            data = LCD_SET_DDADR + LCD_DDADR_LINE1 + x;
            break;

        case 2:    // 2. Zeile
            data = LCD_SET_DDADR + LCD_DDADR_LINE2 + x;
            break;

        case 3:    // 3. Zeile
            data = LCD_SET_DDADR + LCD_DDADR_LINE3 + x;
            break;

        case 4:    // 4. Zeile
            data = LCD_SET_DDADR + LCD_DDADR_LINE4 + x;
            break;

        default:
            return;                                   // für den Fall einer falschen Zeile
    }

    lcd_command( data );
}
