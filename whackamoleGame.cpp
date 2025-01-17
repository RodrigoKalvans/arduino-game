#include "whackamoleGame.h"

uint8_t currentButtonsStateMoleGame;
uint8_t lastButtonsStateMoleGame = 0;

int guess; // newly pressed button by the user
unsigned int moleIndex; // which LED to light up

unsigned int counter = 0; // game counter
int cooldown = 500; // delay before lighting next LED

void whackAMoleGame() {
  Serial.println("BEGIN MOLE GAME");

  tm.displayBegin();
  tm.brightness(7);
  auto b = getBITS();

  while(counter < WHACK_A_MOLE_REPEATS) {
    currentButtonsStateMoleGame = tm.readButtons();

    tm.setLED(moleIndex, 1);

    if((currentButtonsStateMoleGame != lastButtonsStateMoleGame) & (currentButtonsStateMoleGame > lastButtonsStateMoleGame)) { // wait until player presses a button

      // convert base10 ints to arrays containing only binary values
      int* currentBits = new int[b];
      int* lastBits = new int[b];
      for (unsigned int i = 0; i < b; ++i) {
        currentBits[i] = (currentButtonsStateMoleGame >> i) & 1;
        lastBits[i] = (lastButtonsStateMoleGame >> i) & 1;
      }

      // get index of new button press
      guess = getIndexOfInput(lastBits, currentBits);

      // release memory
      delete[] currentBits;
      delete[] lastBits;

      // increment points if applicable, and flash indicator LED
      if (moleIndex == guess) {
        gameScore += POINTS_PER_WHACK;
        flashGreen();
      } else {
        gameScore -= POINTS_PER_WHACK;
        flashRed();
      }

      displayTime();
      displayScore();

      // pick a new LED to light up
      tm.setLED(moleIndex, 0);
      moleIndex = random(0, 8);

      counter++;

      // game gets faster
      delay(cooldown);
      cooldown -= COOLDOWN_DECREMENT;
    }

    lastButtonsStateMoleGame = currentButtonsStateMoleGame;
  }

  tm.reset(); // optional
}

// find index of the newly pressed button // it is assumed that the player will not be able to press two new buttons fast enough such that we'd need to find multiple indexes
int getIndexOfInput(int* previous, int* current) {
  unsigned int index;
  auto b = getBITS();

  // XOR the arrays
  int temp[b];
  for(unsigned int i = 0; i < b; ++i) {
    if (previous[i] == current[i]) {
      temp[i] = 0;
    } else {
      temp[i] = 1;
    }
  }

  // get index of first 1
  for(int j = 0; j < b; ++j) {
    if(temp[j] == 1) {
      index = j;
    }
  }

  // release memory
  delete[] temp;

  return index;
}
