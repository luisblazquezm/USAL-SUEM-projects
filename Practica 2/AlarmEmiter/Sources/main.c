/* ###################################################################
**     Filename    : main.c
**     Project     : AlarmEmiter
**     Processor   : MKE06Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2021-06-09, 16:48, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Pins1.h"
#include "WAIT.h"
#include "MCUC1.h"
#include "CAN1.h"
#include "Bits_Botones.h"
#include "BitsIoLdd1.h"
#include "ECHO.h"
#include "BitIoLdd2.h"
#include "FC321.h"
#include "RealTimeLdd1.h"
#include "TU1.h"
#include "Term1.h"
#include "Inhr1.h"
#include "ASerialLdd1.h"
#include "TRIGGER.h"
#include "BitIoLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include <stdio.h>
#include <stdlib.h>

// alarm cycle definition
#define ALARM_CYCLE 1000

// button values
#define START_BUTTON_VALUE_1 1
#define START_BUTTON_VALUE_2 2
#define DEFAULT_BUTTON_VALUE 3

// ultrasound threshold
#define ULTRASOUND_THRESHOLD 0.2

// color definition
#define COLOR_BACKGROUND clBlack
#define COLOR_ACTIVATED clRed
#define COLOR_DESACTIVATED clGreen
#define COLOR_LETTER clWhite

// global variables
bool isAlarmTriggered = FALSE;
volatile bool g_Complete = FALSE;
LDD_TDeviceData *g_CANPtr = NULL;

/**
 * Read ultrasound sensors
 * */

word previousValue = 0;
bool isUltraSoundActivated(){
	  word tpo;
	  bool result;

	  // enable trigger
	  TRIGGER_SetVal();
	  FC321_Reset();
	  WAIT_Waitus(10);
	  TRIGGER_ClrVal();

	  // start echo read
	  while(!ECHO_GetVal());
	  while(ECHO_GetVal());
	  FC321_GetTimeUS(&tpo);

	  if(previousValue == 0){
		  previousValue = tpo;
	  }

	  if(ULTRASOUND_THRESHOLD <= abs(tpo-previousValue)){
		  result = TRUE;
	  }else{
		  result = FALSE;
	  }

	  previousValue = tpo;

	  return result;
}


/**
 * Read button
 * */
bool isButtonPushed(){
	byte value = Bits_Botones_GetVal();
	printf("value %d\r\n",value);
	return (value==START_BUTTON_VALUE_1 || value==START_BUTTON_VALUE_2);
}


/**
 * Write in CAN bus
 * */
void writeCan(bool activated){
	LDD_CAN_TFrame Frame;
	Frame.MessageID = (0x123U);
	Frame.FrameType = LDD_CAN_DATA_FRAME;
	uint8_t Message [] = { 'P', 'T', 'H', activated ? 'A': 'D'};
	Frame.Length = sizeof(Message);
	Frame.Data = Message;
	CAN1_SendFrame(g_CANPtr, 1U, &Frame);
}


void printSerial(char * message){
	if(isAlarmTriggered){
		Term1_SetColor(COLOR_LETTER, COLOR_ACTIVATED);
	}else{
		Term1_SetColor(COLOR_LETTER, COLOR_DESACTIVATED);
	}
	Term1_SendStr(message);
	Term1_SetColor(COLOR_LETTER, COLOR_BACKGROUND);
}

/* *
 * Implements the alarm behaviour.
 * */
void alarmBehaviour(){
	 if(!isAlarmTriggered){
		 printf("Alarma desactivada midiendo\r\n");
		 // read ultrasound values and if it says that trigger write in can bus
		 if(isUltraSoundActivated()){
			 printSerial("ACTIVADA\n");
			 printf("Activar alarma\r\n");
			 writeCan(TRUE);
			 isAlarmTriggered = TRUE;
		 }
	 }else{
		 printf("Alarma activada midiendo\r\n");
		 // read button and if is correct write in can bus
		 if(isButtonPushed()){
			 printf("Desactivar alarma\r\n");
			 printSerial("DESACTIVADA\n");
			 writeCan(FALSE);
			 isAlarmTriggered = FALSE;
		 }
	 }
}


/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */

  // init can bus
  g_CANPtr = CAN1_Init(NULL);

  // set default value for alarm
  isAlarmTriggered = FALSE;

  // print initial message
  Term1_MoveTo(1,1);
  Term1_SetColor(COLOR_BACKGROUND,COLOR_BACKGROUND);
  Term1_Cls();
  printSerial("Historico:\n");

  while(1){
	  alarmBehaviour();
	  WAIT_Waitms(ALARM_CYCLE);
  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
