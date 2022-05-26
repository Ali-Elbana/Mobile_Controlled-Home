/*
0
 * UART_INTR.h
 *
 *  Created on: Oct 29, 2021
 *      Author: Ali El Bana
 */

#ifndef UART_DRIV_UART_INTR_H_
#define UART_DRIV_UART_INTR_H_

#include "../LIB/STD_TYPES.h"

void UART_Init(void);

void USART_Transmit( u8 data );

u8 USART_Receive( void );

void UART_ENABLE(void);

void UART_DISABLE(void);

void UART_SetBAUDRate(u16 baud);

void UART_SetCallBack(u8 Init, void(*CBFB)(void));

s8 UART_Get_UDR(void);

void  UART_recieve_string(char * ptr);

void UART_printString( const char *myString);

void USART_Flush( void );

u8  UART_compare_string(const char *s1, const char *s2);

//void UART_sendString(s8 d[]);

//void UART_RecieveString(s8 d[],int size);



#define CB_RXC 0
#define CB_TXC 1
#define CB_UDR 2


#define Correct 1
#define Incorrect 0







#endif /* UART_DRIV_UART_INTR_H_ */
