
#define F_CPU 8e6
#include <avr/io.h>
#include <util/delay.h>

/******************************************************************/
void wait( int ms )
/* 
short:			Busy wait number of millisecs
inputs:			int ms (Number of millisecs to busy wait)
outputs:	
notes:			Busy wait, not very accurate. Make sure (external)
				clock value is set. This is used by _delay_ms inside
				util/delay.h
Version :    	DMK, Initial code
*******************************************************************/
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}


}
/******************************************************************/
int main( void )
/*
short:			main() loop, entry point of executable
inputs:
outputs:
notes:
Version :    	DMK, Initial code
*******************************************************************/
{
	// set PORTD for output
	DDRD = 0b01111111;					// PORTD.7 input all other bits output
	PORTC = 0b00000000;						// portc.0 
	
	while (1)
	{
		if (PINC & 0x80)
		{
			PORTD = 0x01;				// write 1 to all the bits of PortD
		}
		else
		{
			PORTD = 0x00;				// write 0 to all the bits of PortD
		}
	}

	return 1;
}
