/*
 * test_DIO.c
 *
 * Created: 9/3/2021 10:49:59 PM
 *  Author: Farouk
 */ 


/* common lib */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
/* DIO */
#include "DIO_interface.h"
#include "DIO_private.h"

int main(void)
{
	// button definition
	DIO_setPinDirection(GPIOA, PIN0, INPUT); // for button
	DIO_setPinValue(GPIOA, PIN0, HIGH); // set pull-up resistor on this pin
	// led definition
	DIO_setPinDirection(GPIOA, PIN1, OUTPUT);
	DIO_setPinValue(GPIOA, PIN1, LOW);
	
	uint8_t button_state = 1;
	uint8_t previous_state = 1;
	uint8_t led_state = 0;
    while(1)
    {
		// read button state
		button_state = DIO_readPinValue(GPIOA, PIN0); 
		// falling edge?
        if (!button_state && previous_state)
        {
			led_state = DIO_readPinValue(GPIOA,PIN1);
			// toggle the led
			DIO_setPinValue(GPIOA, PIN1, !led_state);
			previous_state = button_state;
        }
		// not falling edge?
		else
		{
			previous_state = button_state;
		}
    }
}