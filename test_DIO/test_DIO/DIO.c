/* common lib */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
/* DIO headers */
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

sint8_t DIO_setPinDirection(uint8_t GPIO, uint8_t pin_number, uint8_t direction)
{
	switch (GPIO)
	{
		case GPIOA:
			if (pin_number < 7 && direction <= 1) 
			{
				PORTA_DDR |= (direction<< pin_number);
				return 1; // no errors
			}
		return -2; // pin_number or direction are out of range

		case GPIOB:
			if (pin_number < 7 && direction <= 1) 
			{
				PORTB_DDR |= (direction<< pin_number);
				return 1; // no errors
			}
		return -2; // pin_number or direction are out of range
		
		case GPIOC:
			if (pin_number < 7 && direction <= 1) 
				{
					PORTA_DDR |= (direction<< pin_number);
					return 1; // no errors
				}
		return -2; // pin_number or direction are out of range
		
		case GPIOD:
		if (pin_number < 7 && direction <= 1) 
				{
					PORTA_DDR |= (direction<< pin_number);
					return 1; // no errors
				}
			
		return -2; // pin_number or direction are out of range

	default: return -1; // GPIO Id isn't defined
	}
}



sint8_t DIO_setPinValue(uint8_t GPIO, uint8_t pin_number, uint8_t value)
{
	switch (GPIO)
	{
		case GPIOA:
		if (pin_number < 7)
		{
			if (GET_BIT(value, 0) == LOW)
			{
				CLR_BIT(PORTA_DATA, pin_number);
			}
			else
			{
				SET_BIT(PORTA_DATA, pin_number);
			}
			return 1; // no errors
		}
		return -2; // pin_number is out of range


		case GPIOB:
		if (pin_number < 7)
		{
			if (GET_BIT(value, 0) == LOW)
			{
				CLR_BIT(PORTB_DATA, pin_number);
			}
			else
			{
				SET_BIT(PORTB_DATA, pin_number);
			}
			return 1; // no errors
		}
		return -2; // pin_number is out of range

		
		case GPIOC:
		if (pin_number < 7)
		{
			if (GET_BIT(value, 0) == LOW)
			{
				CLR_BIT(PORTC_DATA, pin_number);
			}
			else
			{
				SET_BIT(PORTC_DATA, pin_number);
			}
			return 1; // no errors
		}
		return -2; // pin_number is out of range

		
		case GPIOD:
		if (pin_number < 7)
		{
			if (GET_BIT(value, 0) == LOW)
			{
				CLR_BIT(PORTD_DATA, pin_number);
			}
			else
			{
				SET_BIT(PORTD_DATA, pin_number);
			}
			return 1; // no errors
		}
		return -2; // pin_number is out of range


		default: return -1; // GPIO Id isn't defined
	}
}



uint8_t DIO_readPinValue(uint8_t GPIO, uint8_t pin_number)
{
	switch (GPIO)
	{
		case GPIOA:
			if (pin_number < 8) 
			{
				// return the value
				return GET_BIT(PORTA_PIN, pin_number); // no errors
			}
		return -2; // pin_number is out of range

		case GPIOB:
			if (pin_number < 8) 
			{
				return GET_BIT(PORTB_PIN, pin_number); // no errors
			}
		return -2; // pin_number is out of range
		
		case GPIOC:
			if (pin_number < 8) 
				{
					return GET_BIT(PORTC_PIN, pin_number); // no errors
				}
		return -2; // pin_number is out of range
		
		case GPIOD:
		if (pin_number < 8) 
				{
					return GET_BIT(PORTD_PIN, pin_number); // no errors
				}
		return -2; // pin_number is out of range

	default: return -1; // GPIO Id isn't defined
	}
}