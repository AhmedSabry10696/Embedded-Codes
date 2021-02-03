/*
 * configure INT0 as a pull down to toggle led as a negative logic
 * FCPU --> 1 MHZ
*/
#ifndef __AVR_ATmega16__
	#define __AVR_ATmega16__
#endif

#include <avr/io.h>
#include <avr/interrupt.h>    /* to use interrupt */

/* External INT0 Interrupt Service Routine */
ISR(INT0_vect)                   
{
	PORTC = PORTC ^ (1<<PC0);   /* toggle led state */
}

/* External INT0 enable and configuration function */
void INT0_Init(void)           
{
	SREG  &= ~(1<<7);          /* Disable interrupts by clearing I-bit */
	DDRD  &= (~(1<<PD2));      /* Configure INT0/PD2 as input pin */
	GICR  |= (1<<INT0);        /* Enable external interrupt pin INT0 */
	MCUCR |= (1<<ISC00) | (1<<ISC01); /* Trigger INT0 with the raising edge pull down switch */
	SREG  |= (1<<7);           /* Enable interrupts by setting I-bit */
}

int main(void)
{
	INT0_Init(); /* Enable external INT0 */

	DDRC  = DDRC | (1<<PC0);  /* Configure pin PC0 in PORTC as output pin */
	PORTC = PORTC | (1<<PC0); /* Initialization Led is off at the beginning(Negative Logic) */
    while(1)
    {
		/* do no thing */				
	}					
}
