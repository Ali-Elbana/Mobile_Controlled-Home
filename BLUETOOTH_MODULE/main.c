/*
 * main.c
 *
 *  Created on: Dec 15, 2021
 *      Author: Ali El Bana
 */


#include "LIB/STD_TYPES.h"
#include "LIB/BITMATH.h"
#include <string.h>
#include "DIO/DIO_interface.h"
#include "UART_DRIV/UART_INTR.h"
#include "BLUETOOTH_USERS/BLUETOOTH_USERS_interface.h"




int main()

{

	u8 pass=0,user_check=0;


	UART_Init();

	USART_Flush();

	vDIO_SetPinDirection(DIO_PORTD,DIO_PIN0,DIO_INPUT);  //RX IS INPUT
	vDIO_SetPinDirection(DIO_PORTD,DIO_PIN1,DIO_OUTPUT); //TX IS OUTPUT

	vDIO_SetPinDirection(DIO_PORTB,DIO_PIN0,DIO_OUTPUT); //BUZZER
	vDIO_SetPinDirection(DIO_PORTD,DIO_PIN7,DIO_OUTPUT); //DOOR
	vDIO_SetPinDirection(DIO_PORTD,DIO_PIN6,DIO_OUTPUT); //FAN
	vDIO_SetPortDirection(DIO_PORTA,DIO_OUTPUT);         //LED




while(1)

 {


    UART_printString("\nLogin to Smart Home: \n\n");

	UART_printString("\nEnter your user name: \n");


	user_check = Users_Check();

	/*
	 * This function checks for the user name is correct or not.
	 *
	 * If it's correct it will return 1 to the defined variable (user_check).
	 *
	 * And if it isn't it will return 0 to the defined variable (user_check).
	 *
	 */



  if(user_check == Correct)

  {


	pass = IDs_Check();


	/*
	 * This function checks for the user id is correct or not.
	 *
	 * If it's correct it will return 1 to the defined variable (pass).
	 *
	 * And if it isn't it will return 0 to the defined variable (pass).
	 *
	 */


		  if(pass == Correct)


		  {


			  Menu();


	 /*
      * This function contains the choices of the system can do.
	  *
	  * The user can choose one of them at a time and then the menu will appear again
	  * to choose again until he/she chooses to exit from the menu.
      *
	  */

		  }



		  Bluetooth_PassCheck3times(pass);



       /*
        * This function checks the pass if it isn't correct it gives the user 2 trials to enter
        * the correct password, in the third time if he/she enters the wrong password again,
        * the system will neglect the user and send an alarm to the mobile application and
        * the system will turn on the buzzer to alarm the other users.
        *
        */




   } // bracket of ((the first if statement))




  else if(user_check == Incorrect)

  {


	  UART_printString("\nInvalid User\n");


  }




 } // bracket of ((while loop))



} // bracket of ((main))


