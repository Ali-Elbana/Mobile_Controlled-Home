/*
 * UART_PROG.c
 *
 *  Created on: Oct 29, 2021
 *      Author: Ali El Bana
 */

#include"../LIB/STD_TYPES.h"
#include"../LIB/BITMATH.h"
#include<string.h>
#include "../DIO/DIO_interface.h"
#include "UART_CONFIG.h"
#include "UART_INTR.h"
#include "UART_PRIVATE.h"
#include<util/delay.h>

static void (*Global_UART_CallBack[3])(void)= {NULL};

u8 f=0;

void UART_Init(void){

//1-enable/disable interrupt sources


//1a-en/dis RX complete
//1b-en/dis TX complete
//1c-en/dis TX empty

	CLR_BIT(UCSRB,RXCIE);
	CLR_BIT(UCSRB,TXCIE);
	CLR_BIT(UCSRB,UDRIE);


//2-set character size-> 5,6,7,8,9

CLR_BIT(UCSRB,UCSZ2);

UCSRC=((1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0));




//3-set UART mode: ASYNC OR SYNC




//4-set parity mode : DIS, EVEN ,ODD




//5-set num of stop bits: 1,2




//6-set CLK polarity -> with synch. mode only



//7-set BAUD RATE

UBRRL=51;

//8-en/dis RX and TX

SET_BIT(UCSRB,RXEN);

SET_BIT(UCSRB,TXEN);


}



/*************************************************************/
/*************************************************************/



void USART_Transmit( u8 data )
{
/* Wait for empty transmit buffer */
 while ( !( UCSRA & (1<<UDRE)) );
/* Put data into buffer, sends the data */
UDR = data;

}


/*************************************************************/
/*************************************************************/



u8 USART_Receive( void )
{
/* Wait for data to be received */
while ( !(UCSRA & (1<<RXC)) );
/* Get and return received data from buffer */
return UDR;
}



/*************************************************************/
/*************************************************************/



void USART_Flush( void ){

u8 dummy;

while ( UCSRA & (1<<RXC) ){

dummy = UDR;
}


}



/*************************************************************/
/*************************************************************/




void UART_ENABLE(void){




}



/*************************************************************/
/*************************************************************/



void UART_DISABLE(void){



}


/*************************************************************/
/*************************************************************/


void UART_SetBAUDRate(u16 baud){




}



/*************************************************************/
/*************************************************************/


//RX COMPELTE

void __vector_13 (void) __attribute__((signal));

void __vector_13 (void){

	if(Global_UART_CallBack[CB_RXC]!=NULL){


		Global_UART_CallBack[CB_RXC]();

	}


}


/*************************************************************/
/*************************************************************/


//UDR EMPTY COMPELTE
void __vector_14 (void) __attribute__((signal));
void __vector_14 (void){


	if(Global_UART_CallBack[CB_UDR]!=NULL){


		Global_UART_CallBack[CB_UDR]();

	}

}


/*************************************************************/
/*************************************************************/


//TX COMPELTE
void __vector_15 (void) __attribute__((signal));
void __vector_15 (void){


	if(Global_UART_CallBack[CB_TXC]!=NULL){


		Global_UART_CallBack[CB_TXC]();

	}


}


/*************************************************************/
/*************************************************************/



void UART_SetCallBack(u8 id, void(*CBFB)(void)){

	switch(id){

	case CB_RXC:


	Global_UART_CallBack[id] =CBFB;

	break;

	case CB_TXC:


		Global_UART_CallBack[id] =CBFB;

		break;

	case CB_UDR:

		Global_UART_CallBack[id] =CBFB;

				break;
	}




}



/*************************************************************/
/*************************************************************/


void UART_printString( const char *myString){

while (*myString){
USART_Transmit(*myString++);
}

}



/*************************************************************/
/*************************************************************/




u8  UART_compare_string(const char *s1, const char *s2)
 {





      if(strcmp(s1,s2)==0){



          return Correct; // the strings compare

      }


     else{



      return Incorrect;

     }


 } // end



/*************************************************************/
/*************************************************************/



void  UART_recieve_string(char * ptr)
{
	int i=0;
	ptr[i]=USART_Receive();

	while(ptr[i] !='\n')
	{
		i++;
		ptr[i]=USART_Receive();

	}

	if(ptr[i]=='\n'){

	ptr[i]='\0';

	                }


}



/*************************************************************/
/*************************************************************/



s8 UART_Get_UDR(void){

return UDR;


}








/*************************************************************/
/*************************************************************/


//void UART_sendString(s8 d[]){
//
//
//	for(int i=0;d[i]!='\0';i++){
//
//
//		USART_Transmit(d[i]);
//
//
//	}
//
//
//}




/*************************************************************/
/*************************************************************/




//void UART_RecieveString(s8 d[],int size){
//
//
//	for(int i=0;i<size;i++){
//
//    f=1;
//
//          d[i]=USART_Receive();
//
//
//          if(d[i]=='\n'){
//
//        	  d[i]='\0';
//
//        	  break;
//          }
//
//
//	}
//
//
//	if(f==0){
//
//	d[size-1]='\0';
//
//
//	}
//
//
//}







