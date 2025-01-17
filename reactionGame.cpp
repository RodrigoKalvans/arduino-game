#include "reactionGame.h"

float scores[REACTION_GAME_REPEATS];

unsigned long start;
float timeTaken;

void reactionGame() {
  Serial.println("BEGIN REACTION GAME");
  
  for(unsigned int i = 0; i < REACTION_GAME_REPEATS; ++i) {

    while(digitalRead(button) == HIGH) {} // busy wait

    delay(100); // UX
    digitalWrite(red, HIGH);

    delay(random(LOWER_THRESHOLD, UPPER_THRESHOLD)); // wait before turning led off again

    digitalWrite(red, LOW); // reaction time beginner
    start = millis(); // record time when led turned off

    while(digitalRead(button) == HIGH) {} // wait until the player reacts

    timeTaken = (millis() - start); // once they have reacted, take the time

    flashGreen();

    scores[i] = timeTaken; // record reaction time

    displayTime();
    displayScore();
  }
  gameScore += calculateReactionGameScore();

  displayTime();
  displayScore();
}

// calculate the number of points the player will gain given their reaction times
unsigned long calculateReactionGameScore() {
  unsigned long total = 0;
  for(int i = 0; i < sizeof(scores)/sizeof(scores[0]); ++i) { // SUM all scores
    if (scores[i] < 1000) {
      total += scores[i];
    }
  }

  unsigned int remainder = (int)total % 100;

  return 30 - ((total - remainder) / 100);
}
