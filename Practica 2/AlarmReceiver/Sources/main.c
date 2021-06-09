/* ###################################################################
**     Filename    : main.c
**     Project     : AlarmReceiver
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
#include "MCUC1.h"
#include "WAIT1.h"
#include "Term1.h"
#include "Inhr1.h"
#include "ASerialLdd1.h"
#include "PPG1.h"
#include "PpgLdd1.h"
#include "II2C.h"
#include "IntI2cLdd1.h"
#include "CAN1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "lcd.h"
#include <stdio.h>

// alarm cycle definition
#define ALARM_CYCLE 100

// tones definition
#define TONE_UNO 1
#define TONE_LOW 200
#define TONE_HIGH 400
word TONES_T[]={TONE_HIGH,TONE_LOW,TONE_HIGH,TONE_LOW,TONE_HIGH,TONE_LOW,TONE_HIGH,TONE_LOW,0};
word TONES_L[]={1,1,1,1,1,1,1,1,0};

// color definition
#define COLOR_BACKGROUND clBlack
#define COLOR_ACTIVATED clRed
#define COLOR_DESACTIVATED clGreen
#define COLOR_LETTER clWhite

// global variables
bool isAlarmActivated = FALSE;
LDD_TDeviceData *g_CANPtr = NULL;

/**
 * Play buzzer.
 * */
void tone(word frecuencia){
	PPG1_Enable();
	PPG1_SetFreqHz(frecuencia);
}
void notone(){
	PPG1_Disable();
	PPG1_ClrValue();
}
void playtone(word *ptrT, word*ptrL, word vel){
	int i;
	for(i=0; ptrT[i]; i++){
		if(ptrT[i]!=TONE_UNO){
			tone(ptrT[i]);
		}else{
			notone();
		}
		WAIT1_Waitms(vel*ptrL[i]);
	}
	notone();
}

/**
 * Print LCD
 * */
void printLcd(char * message){
	LCD_backlight();
	LCD_clear();
	LCD_setCursor(0,0);
	LCD_printstr(message);
}

void printSerial(char * message){
	if(isAlarmActivated){
		Term1_SetColor(COLOR_LETTER, COLOR_ACTIVATED);
	}else{
		Term1_SetColor(COLOR_LETTER, COLOR_DESACTIVATED);
	}
	Term1_SendStr(message);
	Term1_SetColor(COLOR_LETTER, COLOR_BACKGROUND);
}


void alarmBehaviour(){
	// read from bus
	LDD_TError error;
	uint8_t Message[2];
	LDD_CAN_TFrame Frame;
	Frame.Data=Message;

	while(1){
		error = CAN1_ReadFrame(gCANPtr, 0U, &Frame);
		if(error == ERR_OK){
			if(Frame.Data[1] == 'A' && !isAlarmActivated){
				printf("Alarma activada\n\r");
				isAlarmActivated = TRUE;
				printLcd("ACTIVADO");
				printSerial("Alarma activada\n");
			}else if(Frame.Data[1] == 'D' && isAlarmActivated){
				printf("Alarma desactivada\n\r");
				isAlarmActivated = FALSE;
				notone();
				printLcd("DESACTIVADO");
				printSerial("Alarma desactivada\n");
			}else{
				printf("No signal\n\r");
			}
		}
		// make sound if the alarm is activated
		if(isAlarmActivated){
			playtone(TONES_T, TONES_L, 200);
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

  // disable buzzer
  notone();

  // init can bus
  g_CANPtr = CAN1_Init(NULL);

  // set initial alarm value to false
  isAlarmActivated = FALSE;

  // initialize LCD
  LCD_Init(0x27, 16, 2, LCD_5x8DOTS);
  printLcd("DESACTIVADO");

  // print initial message
  Term1_Cls();
  printSerial("Historico:\n");

  // enter in classical alarm behaviour
  while(1){
	  // do alarm behaviour
	  alarmBehaviour();
	  // wait time step
	  WAIT1_Waitms(ALARM_CYCLE);
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
