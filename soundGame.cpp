#include "soundGame.h"

float percent; // percentage twist on potentiometer
unsigned int read; // value read from potentiometer
unsigned int frequencyToPlay; // frequency to play based on potentiometer R

unsigned long tones[SOUND_GAME_REPEATS]; // contains frequencies to be played

void soundGame() {
  Serial.println("BEGIN SOUND GAME");

  generateFrequencies(); // populate tones[]

  for(unsigned int i = 0; i < SOUND_GAME_REPEATS; ++i) {
    Serial.print("Round ");
    Serial.println(i+1);

    while(digitalRead(button) == HIGH) {} // busy wait until button press

    unsigned long start = millis();

    delay(100); // UX

    digitalWrite(green, HIGH);
    tone(buzzer, tones[i], DURATION); // play first sound
    delay(DURATION);
    digitalWrite(green, LOW);
    
    while(!((millis() - start) >= ROUND_DURATION)) { // while the player is allowed to guess
      read = analogRead(potentiometer);
      percent = read / MAX_POTENTIOMETER_VALUE;
      frequencyToPlay = (unsigned int)(percent * UPPER_FREQUENCY);
      tone(buzzer, frequencyToPlay);
    }

    noTone(buzzer); // stop playing

    if(isInRange(tones[i], frequencyToPlay)) { // right or wrong
      gameScore += POINTS_PER_CORRECT_SOUND_GUESS;
      flashGreen();
    } else {
      flashRed();
    }
    displayTime();
    displayScore();
  }
}

// populates tones[] with random frequencies in range of the thresholds specified in header file
void generateFrequencies() {
  for(unsigned int j = 0; j < SOUND_GAME_REPEATS; ++j) {
    long d = random(LOWER_FREQUENCY, UPPER_FREQUENCY);
    tones[j] = d;
  }
}

// return true if the input frequency is within the acceptable range provided in the header file
bool isInRange(unsigned int correctFrequency, unsigned int inputFrequency) {
  unsigned long distance = abs((int)correctFrequency - (int)inputFrequency); // absolute difference between input and correct frequency
  if(distance <= ACCEPTABLE_RANGE) {
    return true;
  }
  return false;
}
