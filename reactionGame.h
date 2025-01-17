#ifndef REACTIONGAME_H
#define REACTIONGAME_H

#include <Arduino.h>

// declarations
extern int red;
extern int button;

extern unsigned long gameScore;

// consts
const unsigned int LOWER_THRESHOLD = 2000; // earliest that LED can turn off
const unsigned int UPPER_THRESHOLD = 4000; // latest that LED can turn off
const unsigned int REACTION_GAME_REPEATS = 3; // numbe of time the game will repeat

// functions
void reactionGame();
unsigned long calculateReactionGameScore();

extern void flashGreen();
extern void flashRed();
extern void displayTime();
extern void displayScore();

#endif
