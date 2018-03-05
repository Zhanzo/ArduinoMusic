#include "pitches.h"
#include "heathens.h"

// Declare global pin constant fr buzzer
const byte buzzerPin = 11;

void setup() {
  // put your setup code here, to run once:
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
    tone(buzzerPin, melody[thisNote], noteDuration);;

    // To destinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    // Stop the tone playing
    noTone(buzzerPin);
  }
}
