/***********************************************************************/
/***********    Author     : Tarek Elmenshawy       		************/
/***********    File Name  : Mini_Project_4.c			    ************/
/***********    Date       : 30-05-2022             		************/
/***********    Description: HC-SR04 Ultra-sonic Module		************/
/***********************************************************************/

#include "std_types.h"
#include "lcd.h"
#include "ultrasonic.h"
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
	uint16 l_distance;

	/* Enable global interrupts */
	sei();
	/* Initialize ultra-sonic sensor */
	ULTRASONIC_init();
	/* Initialize LCD */
	LCD_init();
	LCD_displayString("Distance = ");

	while(1)
	{
		/* Get distance */
		l_distance = ULTRASONIC_readDistance();
		/* Display distance on LCD */
		LCD_moveCursor(0, 11);
		LCD_integerToString(l_distance);
		LCD_displayString("cm ");
		_delay_ms(100);

	}
	return 0;
}
