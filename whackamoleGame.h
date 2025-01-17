#ifndef WHACKAMOLEGAME_H
#define WHACKAMOLEGAME_H

#include <Arduino.h>
#include <TM1638plus.h>

// Vcc MUST BE CONNECTED TO 3.3V, NOT 5V

// tm.displayBegin()
// tm.setLED(int index, int value) // value must be 0 or 1
// tm.display7Seg(int index, int value)
// tm.displayHex(int index, int value) // value must be 0-15
// tm.displayIntNum(long number, bool leadingZeros? = true, AlignTextType_e? = TMAlignTextLeft | TMAlignTextRight) // the board handles how to display the provided number (default left side)
// tm.brightness(int brightness) // brightness must be 0-7
// tm.readButtons() // returns sum of pressed button binary values
// tm.reset()

// declarations
extern int red;
extern int green;

extern unsigned long gameScore;

extern TM1638plus tm;

// consts
const unsigned int WHACK_A_MOLE_REPEATS = 20; // maximum number of guesses the player gets
const unsigned int POINTS_PER_WHACK = 5;
const unsigned int COOLDOWN_DECREMENT = 15;

// functions
void whackAMoleGame();
int getIndexOfInput(int* previous, int* current);

extern void flashGreen();
extern void flashRed();
extern void displayTime();
extern void displayScore();
extern unsigned int getBITS();

#endif
