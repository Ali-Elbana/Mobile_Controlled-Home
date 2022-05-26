/* FILENAME: BLUETOOTH_USERS_program 
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Thu 12/16/2021
*/


#include "../LIB/STD_TYPES.h"
#include "../LIB/BITMATH.h"
#include <string.h>
#include "../DIO/DIO_interface.h"
#include "../UART_DRIV/UART_INTR.h"
#include "BLUETOOTH_USERS_config.h"
#include "BLUETOOTH_USERS_interface.h"
#include "BLUETOOTH_USERS_private.h"





u8 flag=0;




void LED_ON(void){


	vDIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);

    UART_printString("LED_ON\n");


				 }



/*************************************************************/
/*************************************************************/



void LED_OFF(void){


	 vDIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_LOW);

	 UART_printString("\nLED OFF\n");


				  }


/*************************************************************/
/*************************************************************/



void OPEN_THEDOOR(void){


	vDIO_SetPinValue(DIO_PORTD,DIO_PIN7,DIO_HIGH);

   	UART_printString("\nDOOR OPENED\n");


					   }


/*************************************************************/
/*************************************************************/



void CLOSE_THEDOOR(void){


	vDIO_SetPinValue(DIO_PORTD,DIO_PIN7,DIO_LOW);

   	UART_printString("\nDOOR CLOSED\n");


						}


/*************************************************************/
/*************************************************************/



void TURNON_BUZZER(void){


	vDIO_SetPinValue(DIO_PORTB,DIO_PIN0,DIO_HIGH);

	UART_printString("\nBUZZER Turned On\n");


						}


/*************************************************************/
/*************************************************************/



void TURNOFF_BUZZER(void){


	vDIO_SetPinValue(DIO_PORTB,DIO_PIN0,DIO_LOW);

	UART_printString("\nBUZZER Turned Off\n");


						 }


/*************************************************************/
/*************************************************************/



void TURNON_FAN(void){


	vDIO_SetPinValue(DIO_PORTD,DIO_PIN6,DIO_HIGH);

	UART_printString("\nFan Turned On\n");


					 }


/*************************************************************/
/*************************************************************/



void TURNOFF_FAN(void){


	vDIO_SetPinValue(DIO_PORTD,DIO_PIN6,DIO_LOW);

	UART_printString("\nFan Turned Off\n");


					  }


/*************************************************************/
/*************************************************************/



u8 Users_Check(void){



	char user[5]="0";


    u8 user_check;


	UART_recieve_string(user);


	user_check= UART_compare_string(user,USER1_NAME);


	if(user_check==Correct){

		flag=1;

	    return Correct;

							}


	/*--------------------------------------------------------------*/


	user_check= UART_compare_string(user,USER2_NAME);


	if(user_check==Correct){

		flag=2;

		return Correct;

							}


	/*--------------------------------------------------------------*/


	user_check= UART_compare_string(user,USER3_NAME);



	if(user_check==Correct){

		 flag=3;

		 return Correct;

							}


	/*--------------------------------------------------------------*/


	user_check= UART_compare_string(user,USER4_NAME);


	if(user_check==Correct){

		  flag=4;

		  return Correct;

							}


	/*--------------------------------------------------------------*/


	user_check= UART_compare_string(user,USER5_NAME);


	if(user_check==Correct){

		  flag=5;

		  return Correct;

						   }

	/*--------------------------------------------------------------*/


	user_check= UART_compare_string(user,USER6_NAME);


	if(user_check==Correct){

		  flag=6;

		  return Correct;

							}


	/*--------------------------------------------------------------*/


	user_check= UART_compare_string(user,USER7_NAME);


	if(user_check==Correct){

		   flag=7;

		   return Correct;

							}


	/*--------------------------------------------------------------*/


	user_check= UART_compare_string(user,USER8_NAME);


	if(user_check==Correct){

		    flag=8;

		    return Correct;

							}


	/*--------------------------------------------------------------*/


	user_check= UART_compare_string(user,USER9_NAME);


	if(user_check==Correct){

		    flag=9;

		    return Correct;

							}


	/*--------------------------------------------------------------*/


	user_check= UART_compare_string(user,USER10_NAME);


	if(user_check==Correct){

		    flag=10;

		    return Correct;

							}


	/*--------------------------------------------------------------*/


	else

		return Incorrect;

	/*----------------------------END-------------------------------*/

}



/*************************************************************/
/*************************************************************/



u8 IDs_Check(void){



	char id[4]="0";

	u8 pass;




	switch(flag){



	case 1:


		UART_printString("\nWELCOME Ali\n");

		UART_printString("\nEnter your password: \n");

		UART_recieve_string(id);

		pass= UART_compare_string(id,USER1_ID);

		return pass;

		break;


	/*--------------------------------------------------------------*/



	case 2:


		UART_printString("\nWELCOME Omar\n");

		UART_printString("\nEnter your password: \n");

		UART_recieve_string(id);

		pass= UART_compare_string(id,USER2_ID);

		return pass;

		break;


	/*--------------------------------------------------------------*/



	case 3:


		UART_printString("\nWELCOME Amr\n");

		UART_printString("\nEnter your password: \n");

		UART_recieve_string(id);

		pass= UART_compare_string(id,USER3_ID);

		return pass;

		break;


	/*--------------------------------------------------------------*/



	case 4:


		UART_printString("\nWELCOME Adel\n");

		UART_printString("\nEnter your password: \n");

		UART_recieve_string(id);

		pass= UART_compare_string(id,USER4_ID);

		return pass;

		break;


	/*--------------------------------------------------------------*/



	case 5:


		UART_printString("\nWELCOME Ahmed\n");

		UART_printString("\nEnter your password: \n");

		UART_recieve_string(id);

		pass= UART_compare_string(id,USER5_ID);

		return pass;

		break;


	/*--------------------------------------------------------------*/



	case 6:


		UART_printString("\nWELCOME Alaa\n");

		UART_printString("\nEnter your password: \n");

		UART_recieve_string(id);

		pass= UART_compare_string(id,USER6_ID);

		return pass;

		break;


	/*--------------------------------------------------------------*/



	case 7:


		UART_printString("\nWELCOME Osman\n");

		UART_printString("\nEnter your password: \n");

		UART_recieve_string(id);

		pass= UART_compare_string(id,USER7_ID);

		return pass;

		break;


	/*--------------------------------------------------------------*/



	case 8:


		UART_printString("\nWELCOME Amin\n");

		UART_printString("\nEnter your password: \n");

		UART_recieve_string(id);

		pass= UART_compare_string(id,USER8_ID);

		return pass;

		break;


	/*--------------------------------------------------------------*/



	case 9:


		UART_printString("\nWELCOME Anas\n");

		UART_printString("\nEnter your password: \n");

		UART_recieve_string(id);

		pass= UART_compare_string(id,USER9_ID);

		return pass;

		break;


	/*--------------------------------------------------------------*/



	case 10:


		UART_printString("\nWELCOME Hala\n");

		UART_printString("\nEnter your password: \n");

		UART_recieve_string(id);

		pass= UART_compare_string(id,USER10_ID);

		return pass;

		break;


	/*--------------------------------------------------------------*/



	default: return Incorrect; break;





				}


	/*----------------------------END-------------------------------*/


}



/*************************************************************/
/*************************************************************/



void Menu (void){




	char select=0;


	do{




	      UART_printString("\nSelect from the menu: \n");

		  UART_printString("\n1) Open the door\n");
		  UART_printString("\n2) Close the door\n");
		  UART_printString("\n3) Open the light\n");
		  UART_printString("\n4) Close the light\n");
		  UART_printString("\n5) Close the buzzer\n");
		  UART_printString("\n6) Turn on the Fan\n");
		  UART_printString("\n7) Turn off the Fan\n");
		  UART_printString("\n8) Exit\n");


	     select=USART_Receive();


	     switch(select){


	     case OPEN_DOOR :      OPEN_THEDOOR();   break;

	     case CLOSE_DOOR :     CLOSE_THEDOOR();  break;

	     case TURNON_LED :     LED_ON();         break;

	     case TURNOFF_LED :    LED_OFF();        break;

	     case TURNOff_BUZZER:  TURNOFF_BUZZER(); break;

	     case TURNOn_FAN :     TURNON_FAN();     break;

	     case TURNOff_FAN :    TURNOFF_FAN();    break;

	     case EXIT: CLOSE_THEDOOR(); LED_OFF(); TURNOFF_BUZZER(); TURNOFF_FAN();

	     	 	 	 	}



	}while(select!=EXIT);




	switch(flag){


		case 1 : UART_printString("\n\nAli Signed Out\n\n\n");   break;

		case 2 : UART_printString("\n\nOmar Signed Out\n\n\n");  break;

		case 3 : UART_printString("\n\nAmr Signed Out\n\n\n");   break;

		case 4 : UART_printString("\n\nAdel Signed Out\n\n\n");  break;

		case 5 : UART_printString("\n\nAhmed Signed Out\n\n\n"); break;

		case 6 : UART_printString("\n\nAlaa Signed Out\n\n\n");  break;

		case 7 : UART_printString("\n\nOsman Signed Out\n\n\n"); break;

		case 8 : UART_printString("\n\nAmin Signed Out\n\n\n");  break;

		case 9 : UART_printString("\n\nAnas Signed Out\n\n\n");  break;

		case 10: UART_printString("\n\nHala Signed Out\n\n\n");  break;




				}


	/*----------------------------END-------------------------------*/

}





/*************************************************************/
/*************************************************************/




void Bluetooth_PassCheck3times(u8 pass){


	u8 i;



	if(pass != Correct)

	{



			for (i=0;i<2;i++)

			{



			UART_printString("\nWrong password\n");
			UART_printString("\nTry again\n");

		    pass = IDs_Check();



		           	if (pass == Correct)

		           	{

		           	        Menu();

		           	        break; // break from the for loop and do the following

		           	}







             } // bracket of ((for loop))





				if(pass != Correct)


				{


					UART_printString("\nSecurity alert\n");


					UART_printString("\nUnrecognized logins into the system are disabled\n");


					TURNON_BUZZER();



			     }



	} // bracket of ((the first if statement))



	/*----------------------------END-------------------------------*/


}



/*************************************************************/
/*************************************************************/












//
//
//typedef struct{
//	char name[50];
//	char ID[4];
//}users;
//
//
//
//users user[10]={
//
//
//	{USER1_NAME,USER1_ID},
//
//	{USER2_NAME,USER2_ID},
//
//	{USER3_NAME,USER3_ID},
//
//	{USER4_NAME,USER4_ID},
//
//	{USER5_NAME,USER5_ID},
//
//	{USER6_NAME,USER6_ID},
//
//	{USER7_NAME,USER7_ID},
//
//	{USER8_NAME,USER8_ID},
//
//	{USER9_NAME,USER9_ID},
//
//	{USER10_NAME,USER10_ID},
//
//
//	};
//
//
//
// users *ptr= &user[10];
//
//
//




