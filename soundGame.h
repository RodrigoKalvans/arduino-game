#ifndef SOUNDGAME_H
#define SOUNDGAME_H

#include <Arduino.h>

// tone(int pin, unsigned int freq, unsigned long? duration)
// noTone(int pin)

// declarations
extern int buzzer;
extern int button;
extern int yellow;
extern int green;
extern int red;
extern int potentiometer;

extern unsigned long gameScore;

// consts
const unsigned long DURATION = 2000; // duration that the hint sound will be played for
const unsigned long LOWER_FREQUENCY = 200; // lower bound for random freq
const unsigned long UPPER_FREQUENCY = 5000; // upper bound for random freq
const unsigned int DURATION_DECREMENT = 500; // decrease in allowed time for user's guess
const unsigned int ACCEPTABLE_RANGE = 500; // abs(frequency - input) must be with this threshold 
const unsigned int ROUND_DURATION = 4000; // allowed time for player to select frequency
const unsigned int SOUND_GAME_REPEATS = 3;
const unsigned int POINTS_PER_CORRECT_SOUND_GUESS = 20;
const float MAX_POTENTIOMETER_VALUE = 1023.0; // 1023 is the max value that the potentiometer can give

// functions
void soundGame();
void generateFrequencies();
bool isInRange(unsigned int correctFrequency, unsigned int inputFrequency);

extern void flashGreen();
extern void flashRed();
extern void displayTime();
extern void displayScore();

#endif
