#ifndef HELPERS_H
#define HELPERS_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// lcd.display()
// lcd.noDisplay()
// lcd.clear()
// lcd.setBacklight(int value) // value can be 0 or 1
// lcd.setCursor(column, row) // move cursor to indicated cell // top left = 0,0 , bottom right = 15,1
// lcd.home() // return cursor to 0,0
// lcd.cursor(), lcd.noCursor()
// lcd.blink(), lcd.noBlink()
// lcd.scrollDisplayLeft(), lcd.scrollDisplayRight()

// hardware
extern int green;
extern int red;
extern int yellow;

extern unsigned long gameScore;

const unsigned int BITS = 8; // NR of LEDs, NR of buttons, etc.

LiquidCrystal_I2C lcd(0x27, 16, 2); // (address, nr of chars per row, nr of rows on display)

// functions
void flashGreen();
void flashRed();
void flashYellow();
void displayTime();
void displayScore();

#endif
