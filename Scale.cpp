#include "Arduino.h"
#include "Scale.h"

Scale::Scale() {
}

void Scale::setScale(byte LENGTH, byte NOTES[], char NAME[]) {
  //scales are given as semitones relative to a fundamental, usually beginning with the fundamental (0)
  for(byte i=0;i<16;i++){
  scaleName[i] = NAME[i];
  }
  scaleLength = LENGTH;
  
  for (byte i = 0; i < scaleLength; i++) {
    scaleNotes[i] = NOTES[i];
  }

}

int Scale::getNote(int INDEX){
  //returns the nth note in the scale in semitones. E.g. asking for the 3rd note in a major scale will return 4 (the 3rd in a major scale is always 4 semitones above the fundamental)
  //also handles numbers above 12 and below 0, e.g. asking for the -1th note in a major scale will return the major seventh (one semitone below).
  
  int sensibleIndex=INDEX;
  int low=0;
  while(sensibleIndex<0){sensibleIndex+=scaleLength; low--;}
  
  return scaleNotes[sensibleIndex%scaleLength]+12*((sensibleIndex/scaleLength)+low);
}


