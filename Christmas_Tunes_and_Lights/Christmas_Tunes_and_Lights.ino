#include "pitches.h"
#include "melody.h"

// Declare global pin constant fr buzzer
const byte buzzerPin = 11;
const byte ledPins[4] = {10, 9, 6, 5};

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i <= 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  playTone(melody, noteDurations, sizeof(melody)/sizeof(int));
}

void playTone(int melody[], int noteDurations[], int lengths) {
  // Iterate over the notes of the melody
  for (int thisNote = 0; thisNote < lengths; thisNote++) {
    // To calculate the note duration take one second divided by the note
    // type e.g. quarter note = 1000/4, eighth note = 1000/8 etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    int whichLight = thisNote % 4;
    tone(buzzerPin, melody[thisNote], noteDuration);
    analogWrite(ledPins[whichLight], noteDuration/4);

    // To destinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    // Stop the tone playing
    noTone(buzzerPin);
    analogWrite(ledPins[whichLight], 0);
  }
}


