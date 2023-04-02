/*
 * Pauer_HUB_AVR-Projekt.c
 *
 * Created: 27.03.2023 17:12:09
 * Author : olive
 */ 

#include <avr/io.h>

// libs
#include "io.h"
#include "adc.h"
#include "pwm.h"

// LCD-lib
#include "LCD_4.h"
#include "printf.h"

int main(void)
{
	init_io(); 
	lcd_init(); 
		
    while (1) 
    {
		// read adc values 
		unsigned int v1 = read_adc(7);
		unsigned int mw = avg(10, 7);
		
		// display voltage 
		lcd_pos(0, 0);
		printf("U_MV: %d", v1);
		
		// display average of 10 measurements
		lcd_pos(1, 0);
		printf("MW[10]: %d", mw);
		
		// 12 MOD 4 = 0 (PA0)
		if (BUTTON_PRESSED(0))
		{
			SET_LED(0); // turn PA0 on
		}
		else
		{
			CLR_LED(0); // turn PA0 off
		}
		
		// if PA2 => clear PC2
		if (is_bit_set(PINA, 2))
		{
			port_clr(&PORTC, 2);
		}
		else // turn PC2 off
		{
			port_set(&PORTC, 2);
		}
		
		// PWM: if PA3 => OCR0 = 100 
		if (is_bit_set(PINA, 3))
		{
			set_pwm_0(100);
		}
		else // increase brightness
		{
			set_pwm_0(200);
		}	
    }
}

