#include "STD_Types.h"
#include "BIT_Math.h"
#include <avr/delay.h>
#include "DIO_int.h"
#include "UART.h"

void main(void)
{
	uint8 x ;
	DIO_voidInit();
	UART_voidInit();

	while(1)
	{
		UART_voidTransmit('B');

		x = UART_u8Receive();
		if(x == 'A')
		{
			DIO_enuWritePin(0,1);
			_delay_ms(500);
		}
		else
		{
			DIO_enuWritePin(0,0);
			_delay_ms(500);
		}
		UART_voidTransmit('A');
		_delay_ms(500);


	}


}
