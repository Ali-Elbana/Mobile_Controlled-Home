/*
 * UART_PRIVATE.h
 *
 *  Created on: Oct 29, 2021
 *      Author: Ali El Bana
 */

#ifndef UART_DRIV_UART_PRIVATE_H_
#define UART_DRIV_UART_PRIVATE_H_

#define UDR *((volatile u8*)(0x2C))

#define UCSRA  *((volatile u8*)(0x2B))

#define UCSRB  *((volatile u8*)(0x2A))

#define UCSRC  *((volatile u8*)(0x40))

#define UBRRH  *((volatile u8*)(0x40))

#define UBRRL *((volatile u8*)(0x29))

#define RXB 0

#define TXB 0

#define RXC 7

#define TXC 6

#define UDRE 5

#define FE 4

#define DOR 3

#define PE 2

#define RXCIE 7

#define TXCIE 6

#define UDRIE 5

#define RXEN 4

#define TXEN 3

#define UCSZ2 2

#define RXB8 1

#define TXB8 0

#define UMSEL 6

#define UPM0 4

#define UPM1 5

#define USBS 3

#define UCSZ0 1

#define UCSZ1 2

#define UCSZ2 2

#define URSEL 7

#define UBRR 0



#endif /* UART_DRIV_UART_PRIVATE_H_ */
