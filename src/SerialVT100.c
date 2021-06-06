/*
 * SerialVT100.c
 *
 *  Created on: 30/12/2016
 *      Author: ralves
 */

#include "SerialVT100.h"

void SendString(char * str)
{
	int i;

	for (i=0; str[i]!=0; i++)
	{
		while (Serial_SendChar(str[i])!=ERR_OK);
	}
}

void SendChar(char c)
{
	while (Serial_SendChar(c)!=ERR_OK);
}

void SendCSI(char * str)
{

	while (Serial_SendChar('\33')!=ERR_OK);
	while (Serial_SendChar('[')!=ERR_OK);

	SendString(str);
}
