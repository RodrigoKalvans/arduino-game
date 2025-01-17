#include "memoryGame.h"

uint8_t currentButtonsStateMemoryGame;
uint8_t lastButtonsStateMemoryGame = 0;

int input; // index of button pressed by player
bool correct;

void memoryGame() {
  Serial.println("BEGIN MEMORY GAME");

  digitalWrite(yellow, LOW);
  
  tm.reset();
  tm.displayBegin();
  tm.brightness(7);

  for (unsigned int i = 0; i < MEMORY_GAME_REPEATS; i++) {
    correct = true;
    auto b = getBITS();

    int values[i+ADDITION_TO_ROUNDS];
    int guesses[sizeof(values)/sizeof(values[0])];

    for (int v = 0; v < sizeof(values)/sizeof(values[0]); ++v) { // flash correct color // populate values
    values[v] = random(3);
    tm.displayIntNum(values[v]);
      switch (values[v]) {
        case 0: 
          flashYellow();
          break;
        case 1: 
          flashRed();
          break;
        case 2:
          flashGreen();
          break;
        default:
          break;
      }
      delay(500);
    }

    for (int u = 0; u < sizeof(values)/sizeof(values[0]); ++u) { // user must now input their guesses
      lastButtonsStateMemoryGame = currentButtonsStateMemoryGame;
      while (true) { // loop until button press
        currentButtonsStateMemoryGame = tm.readButtons();
        if ((currentButtonsStateMemoryGame != lastButtonsStateMemoryGame) & (currentButtonsStateMemoryGame > lastButtonsStateMemoryGame)) { // user pressed a button
          int* currentBits = new int[b];
          int* lastBits = new int[b];
          for (unsigned int j = 0; j < b; ++j) { // get bit array from denary
            currentBits[j] = (currentButtonsStateMemoryGame >> j) & 1;
            lastBits[j] = (lastButtonsStateMemoryGame >> j) & 1;
          }

          guesses[u] = getIndexOfInput(lastBits, currentBits);

          delete[] currentBits;
          delete[] lastBits;

          break;
        }
        lastButtonsStateMemoryGame = currentButtonsStateMemoryGame;
      }
    }

    delay(500);

    for (int f = 0; f < sizeof(values)/sizeof(values[0]); ++f) { // check result
      tm.displayIntNum(f+1);
      if (values[f] != guesses[f]) {
        correct = false;
        flashRed();
      } else {
        flashGreen();
      }
      delay(500);
    }

    delay(1000);

    if (correct) {
      flashGreen();
      gameScore += POINTS_PER_MEMORY_ROUND;      
    } else {
      flashRed();
    }

    // for some reason this seemed to be causing crashes
    // delete[] values;
    // delete[] guesses;

    displayTime();
    displayScore();
  }
}
