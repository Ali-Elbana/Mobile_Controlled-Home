/* FILENAME: BLUETOOTH_USERS_interface  
*  Author:  Ali El Bana
*  Version:  V1.0
*  DATE:   Thu 12/16/2021
*/
#ifndef _BLUETOOTH_USERS_interface_H
#define _BLUETOOTH_USERS_interface_H


#include "../LIB/STD_TYPES.h"



u8 Users_Check(void);

u8 IDs_Check(void);

void Bluetooth_PassCheck3times(u8 pass);


void Menu (void);


void OPEN_THEDOOR(void);

void CLOSE_THEDOOR(void);

void LED_ON(void);

void LED_OFF(void);

void TURNON_BUZZER(void);

void TURNOFF_BUZZER(void);

void TURNON_FAN(void);

void TURNOFF_FAN(void);









#endif //_BLUETOOTH_USERS_interface_H
