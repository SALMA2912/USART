/*
 * UART.c
 *
 *  Created on: Oct 1, 2022
 *      Author: a
 */

#include "STD_Types.h"
#include "BIT_Math.h"

#include "UART.h"

#define     UCSRA  *((volatile uint8 *) 0x2B)
#define     UCSRB  *((volatile uint8 *) 0x2A)
#define     UCSRC  *((volatile uint8 *) 0x40)
#define     UBRRL  *((volatile uint8 *) 0x29)
#define     UBRRH  *((volatile uint8 *) 0x40)
#define     UDR    *((volatile uint8 *) 0x2C)


void UART_voidInit(void)
{
	UCSRA = 0 ;
	UCSRB = 0b00011000;
	UCSRC = 0b10000110;
	UBRRL =51 ;
	UBRRH = 0 ;
}

void UART_voidTransmit(uint8 u8DataCpy)
{

	while (GET_BIT(UCSRA , 5)==0);
	UDR = u8DataCpy ;
}
uint8 UART_u8Receive(void)
{
	while (GET_BIT(UCSRA , 7)==0);
	return UDR ;
}
