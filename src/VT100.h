/*
 * VT100.h
 *
 *  Created on: 27/12/2016
 *      Author: ralves
 */

#include "stdio.h"

#ifndef SOURCES_VT100SERIAL_H_
#define SOURCES_VT100SERIAL_H_

// Erase Display: lears part of the screen. If n is 0 (or missing), clear from cursor to end of screen. If  n is 1, clear from cursor to beginning of the screen. If  n is 2, clear entire screen (and moves cursor to upper left on DOS ANSI.SYS).
#define VT100_ERASEDISPLAY_TOEND	0
#define VT100_ERASEDISPLAY_TOBEGIN	1
#define VT100_ERASEDISPLAY_ENTIRE	2
char * EraseDisplay(unsigned char mode);

// Erases part of the line. If  n is zero (or missing), clear from cursor to the end of the line. If  n is one, clear from cursor to beginning of the line. If n is two, clear entire line. Cursor position does not change.
#define VT100_ERASELINE_TOEND	0
#define VT100_ERASELINE_TOBEGIN	1
#define VT100_ERASELINE_ENTIRE	2
char * EraseLine(unsigned char mode);

// Cursor Position: Moves the cursor to row {\displaystyle n} n, column {\displaystyle m} m. The values are 1-based, and default to 1 (top left corner) if omitted.
char * CursorPosition(unsigned char row, unsigned char column);

// Moves the cursor  n  cells in the given direction. If the cursor is already at the edge of the screen, this has no effect.
#define VT100_CUP		'A' //CUU – Cursor Up
#define VT100_CDOWN		'B' //CUD – Cursor Down
#define VT100_CLEFT		'D' //CUF – Cursor Forward
#define VT100_CRIGHT	'C' //CUB – Cursor Back
char * MoveCursor(char dir, unsigned char n);

// Moves cursor to beginning of the line  n (default 1) lines down/up.
#define VT100_CNL_UP	'F'
#define VT100_CNL_DOWN	'E'
char * MoveCursorLine(char dir, unsigned char n);

// Save/Restore Cursor Position: Saves / Restores the cursor position.
#define VT100_SRCP_SAVE		's'
#define VT100_SRCP_RESTORE	'u'
char * CursorPositionSR(char cmd);

// Set Text Color
#define VT100_BLACK		30
#define VT100_RED		31
#define VT100_GREEN		32
#define VT100_YELLOW	33
#define VT100_BLUE		34
#define VT100_MAGENTA	35
#define VT100_CYAN		36
#define VT100_WHITE		37
#define VT100_I_NORMAL	0
#define VT100_I_BRIGHT	1

char * SetTextColor(unsigned char color, unsigned char bright);
char * SetBackgroundColor(unsigned char color, unsigned char bright);

// ShowCursor
#define VT100_SETCURSOR_SHOW	'l'
#define VT100_SETCURSOR_HIDE	'h'
char * SetCursorStatus(char status);

// Blink
#define VT100_SGR_BLINK_SLOW	5
#define VT100_SGR_BLINK_RAPID	6
#define VT100_SGR_BLINK_NORMAL	25
char * SetBlink(unsigned char status);

// Reset Attributes
char * ResetAttributes(void);




#endif /* SOURCES_VT100SERIAL_H_ */
