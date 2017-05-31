/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#include "pitches.h"
int greenPin = 6;
int redPin = 9;
int bluePin = 5;
int counter = 0;//狀態切換
// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, 0,NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
};

void setup() {
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 15; thisNote++) {

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    analogWrite(greenPin,NOTE_D2+thisNote*20);
    analogWrite(redPin,NOTE_DS3+thisNote*50);
    analogWrite(bluePin,thisNote*10);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    noTone(8);
    analogWrite(greenPin,0);
    analogWrite(redPin,0);
    analogWrite(bluePin,0);
  }
}

void loop() {

}
