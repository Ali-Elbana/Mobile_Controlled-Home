/*
 * DIO_programe.c
 *
 *  Created on: Sep 10, 2021
 *      Author: Ali El Bana
 */
#include"../LIB/STD_TYPES.h"
#include"../LIB/BITMATH.h"
#include"DIO_private.h"
#include"DIO_config.h"

void vDIO_SetPinDirection(u8 portn,u8 pinn,u8 dir){

	if(dir==1){

		switch(portn){

		case 0:SET_BIT(DDRA,pinn);break;

		case 1:SET_BIT(DDRB,pinn);break;

		case 2:SET_BIT(DDRC,pinn);break;

		case 3:SET_BIT(DDRD,pinn);break;
	                 }



}

	else if(dir==0){

		switch(portn){

        case 0:CLR_BIT(DDRA,pinn);break;

		case 1:CLR_BIT(DDRB,pinn);break;

		case 2:CLR_BIT(DDRC,pinn);break;

		case 3:CLR_BIT(DDRD,pinn);break;
		             }


}




	                                            }




void vDIO_SetPortDirection(u8 portn,u8 dir){

	switch(portn){

			case 0:DDRA=dir;break;

			case 1:DDRB=dir;break;

			case 2:DDRC=dir;break;

			case 3:DDRD=dir;break;
		                 }

}

void vDIO_SetPinValue(u8 portn,u8 pinn,u8 val){

	if(val==1){

		switch(portn){

		case 0:SET_BIT(PORTA,pinn);break;

		case 1:SET_BIT(PORTB,pinn);break;

		case 2:SET_BIT(PORTC,pinn);break;

		case 3:SET_BIT(PORTD,pinn);break;
	                 }



}

	else if(val==0){

		switch(portn){

        case 0:CLR_BIT(PORTA,pinn);break;

		case 1:CLR_BIT(PORTB,pinn);break;

		case 2:CLR_BIT(PORTC,pinn);break;

		case 3:CLR_BIT(PORTD,pinn);break;

		             }


}




}

void vDIO_SetPortValue(u8 portn,u8 val){

	switch(portn){

			case 0:PORTA=val;break;

			case 1:PORTB=val;break;

			case 2:PORTC=val;break;

			case 3:PORTD=val;break;
		                 }


}

u8  u8DIO_GetPinValue(u8 portn,u8 pinn){

u8 result=0;

switch(portn){

	case 0: result= GET_BIT(PINA,pinn);break;

	case 1: result= GET_BIT(PINB,pinn);break;

	case 2: result= GET_BIT(PINC,pinn);break;

	case 3: result= GET_BIT(PIND,pinn);break;
                 }



return result;


}

u8  u8DIO_GetPortValue(u8 portn){


	u8 result=0;

	switch(portn){

		case 0: result= PINA;break;

		case 1: result= PINB;break;

		case 2: result= PINC;break;

		case 3: result= PIND;break;
	                 }



	return result;


	}


void DIO_toggle(u8 port,u8 pin){

	switch(port){

	case 0: TOGGLE_BIT(PORTA,pin); break;

	case 1: TOGGLE_BIT(PORTB,pin); break;

	case 2: TOGGLE_BIT(PORTC,pin); break;

	case 3: TOGGLE_BIT(PORTD,pin); break;

	}



}

