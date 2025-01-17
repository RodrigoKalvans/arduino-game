#ifndef MEMORYGAME_H
#define MEMORYGAME_H

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
extern int yellow;

extern unsigned long gameScore;

extern TM1638plus tm;

// consts
const unsigned int MEMORY_GAME_REPEATS = 5; // number of rounds
const unsigned int POINTS_PER_MEMORY_ROUND = 25;
const unsigned int ADDITION_TO_ROUNDS = 4;

// functions
void memoryGame();
int getIndexOfInput(int* previous, int* current);

extern void flashGreen();
extern void flashRed();
extern void flashYellow();
extern void displayTime();
extern void displayScore();
extern unsigned int getBITS();

#endif
