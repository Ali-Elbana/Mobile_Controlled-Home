/*
 * DIO_interface.h
 *
 *  Created on: Sep 10, 2021
 *      Author: Ali El Bana
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "../LIB/STD_TYPES.h"

void vDIO_SetPinDirection(u8 portn,u8 pinn,u8 dir);

void vDIO_SetPortDirection(u8 portn,u8 dir);

void vDIO_SetPinValue(u8 portn,u8 pinn,u8 val);

void vDIO_SetPortValue(u8 portn,u8 val);

u8  u8DIO_GetPinValue(u8 portn,u8 pinn);

u8  u8DIO_GetPortValue(u8 portn);

void DIO_toggle(u8 port,u8 pin);

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_OUTPUT 1
#define DIO_INPUT 0

#define DIO_HIGH 1
#define DIO_LOW 0


#endif /* DIO_INTERFACE_H_ */
