#include "globals.h"

#include "reactionGame.h"
#include "soundGame.h"
#include "whackamoleGame.h"
#include "memoryGame.h"

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.display();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Time:");
  lcd.setCursor(0, 1);
  lcd.print("Score:");

  tm.reset();

  randomSeed(millis());

  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);

  // YELLOW LED should stay on for the whole game
  digitalWrite(yellow, HIGH);

  // the player will use this button to interact with the circuit
  pinMode(button, INPUT_PULLUP);

  displayTime();
  displayScore();

  play();
}

void loop() {}

void play() {
  while(digitalRead(button) == HIGH) {}
  reactionGame();
  while(digitalRead(button) == HIGH) {}
  soundGame();
  while(digitalRead(button) == HIGH) {}
  whackAMoleGame();
  while(digitalRead(button) == HIGH) {}
  memoryGame();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("GAME OVER");
  lcd.setCursor(0, 1);

  Serial.println("GAME OVER");
  if(millis() < ALLOWED_TIME) {
    digitalWrite(green, HIGH);
    lcd.print("VICTORY");
  } else {
    digitalWrite(red, HIGH);
    lcd.print("LOSS");
  }

  tm.displayBegin();
  tm.brightness(7);
  tm.displayIntNum(88888888);
}
