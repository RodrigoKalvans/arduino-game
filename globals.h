#ifndef GLOBALS_H
#define GLOBALS_H

#include <LiquidCrystal_I2C.h>
#include <TM1638plus.h>

// LEDs
int yellow = 2;
int red = 3;
int green = 4;

// tm
int TM_STROBE = 8;
int TM_CLOCK = 9;
int TM_DIO = 10;

// other
int buzzer = 5;
int button = 13;
int potentiometer = A5;

extern LiquidCrystal_I2C lcd; // (address, nr of chars per row, nr of rows on display)

// global variables
TM1638plus tm(TM_STROBE, TM_CLOCK, TM_DIO);
unsigned long gameScore = 0;
bool ranOutOfTime = false; // did the player run out of time before finishing?
bool gameEnded = false;

// consts
const unsigned long ALLOWED_TIME = 900000; // 15min

// functions
extern void displayTime();
extern void displayScore();

#endif
