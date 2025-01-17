#include "helpers.h"

void flashGreen() {
  digitalWrite(green, LOW);
  digitalWrite(green, HIGH);
  delay(500);
  digitalWrite(green, LOW);
}

void flashRed() {
  digitalWrite(red, LOW);
  digitalWrite(red, HIGH);
  delay(500);
  digitalWrite(red, LOW);
}

void flashYellow() {
  digitalWrite(yellow, LOW);
  digitalWrite(yellow, HIGH);
  delay(500);
  digitalWrite(yellow, LOW);
}

void displayTime() {
  long now = millis();
  int seconds = now / 1000;

  int minutes = seconds / 60;
  seconds %= 60;

  if (seconds < 10) {
    lcd.setCursor(11, 0);
    lcd.print(" ");
  }

  lcd.setCursor(7, 0);
  lcd.print(minutes);
  lcd.setCursor(9, 0);
  lcd.print(":");
  lcd.setCursor(10, 0);
  lcd.print(seconds);
}

void displayScore() {
  lcd.setCursor(7, 1);
  lcd.print(gameScore);
}

unsigned int getBITS() {
  return BITS;
}
