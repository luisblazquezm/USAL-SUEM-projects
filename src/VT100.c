/*
 * VT100.c
 *
 *  Created on: 27/12/2016
 *      Author: ralves
 */

#include "Serial.h"
#include "stdio.h"

// Variable global para almacenar el codigo de escape
char g_cmd[15];

// Erase Display: clears part of the screen. If n is 0 (or missing), clear from cursor to end of screen. If  n is 1, clear from cursor to beginning of the screen. If  n is 2, clear entire screen (and moves cursor to upper left on DOS ANSI.SYS).
char * EraseDisplay(unsigned char mode)
{
	sprintf(g_cmd,"%dJ",mode);
	return g_cmd;
}

// Erases part of the line. If  n is zero (or missing), clear from cursor to the end of the line. If  n is one, clear from cursor to beginning of the line. If n is two, clear entire line. Cursor position does not change.
char * EraseLine(unsigned char mode)
{
	sprintf(g_cmd,"%dK",mode);
	return g_cmd;
}

// Cursor Position: Moves the cursor to row {\displaystyle n} n, column {\displaystyle m} m. The values are 1-based, and default to 1 (top left corner) if omitted.
char * CursorPosition(unsigned char row, unsigned char column) {
	sprintf(g_cmd,"%d;%dH",row,column);
	return g_cmd;
}



char * SetTextColor(unsigned char color, unsigned char bright)
{
	if (bright)
		sprintf(g_cmd,"%d;1m",color);
	else
		sprintf(g_cmd,"%dm",color);
	return g_cmd;
}


char * SetCursorStatus(unsigned char status)
{
	sprintf(g_cmd,"?25%c",status);
	return g_cmd;
}

char * CursorPositionSR(char cmd)
{
	sprintf(g_cmd,"%c",cmd);
	return g_cmd;
}

char * SetBlink(unsigned char status)
{
	sprintf(g_cmd,"%dm",status);
	return g_cmd;
}

char * SetBackgroundColor(unsigned char color, unsigned char bright)
{
	if (bright)
		sprintf(g_cmd,"%d;1m",color+10);
	else
		sprintf(g_cmd,"%dm",color+10);
	return g_cmd;
}

// Moves the cursor  n  cells in the given direction. If the cursor is already at the edge of the screen, this has no effect.
char * MoveCursor(unsigned char dir, unsigned char n)
{
	sprintf(g_cmd,"%d%c",n,dir);
	return g_cmd;
}

// Moves cursor to beginning of the line  n (default 1) lines down/up.
char * MoveCursorLine(unsigned char dir, unsigned char n)
{
	sprintf(g_cmd,"%d%c",n,dir);
	return g_cmd;
}

char * ResetAttributes(void)
{
	sprintf(g_cmd,"0m");
	return g_cmd;
}




