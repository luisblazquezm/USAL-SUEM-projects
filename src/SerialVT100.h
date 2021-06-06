/*
 * SerialVT100.h
 *
 *  Created on: 30/12/2016
 *      Author: ralves
 */

#ifndef SOURCES_SERIALVT100_H_
#define SOURCES_SERIALVT100_H_

#include "VT100.h"
#include "Serial.h"
#include "ASerialLdd1.h"

void SendString(char * str);
void SendCSI(char * str);
void SendChar(char c);


#endif /* SOURCES_SERIALVT100_H_ */
