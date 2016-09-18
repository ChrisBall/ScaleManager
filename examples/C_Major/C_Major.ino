//example that returns midi notes from the C Major scale.
#include "ScaleManager.h"

ScaleManager scalemanager;

void setup() {
  Serial.begin(9600);

  scalemanager.init();  //loads three default scales (Chromatic, Major, Minor) into scalemanager
  scalemanager.setScale(MAJOR); //sets the currently used scale to Major
  scalemanager.setFundamental(60); //sets the fundamental to C5 (this is already the default, but included for clarity)

  Serial.println(scalemanager.getFundamentalName() + " " + scalemanager.getScaleName());
  Serial.println("Midi notes:");

  for (int i = 0; i < 8; i++) {
    Serial.print(scalemanager.getScaleNote(i));
    Serial.print("\t");
  }
  Serial.println();
  for (int i = 0; i < 8; i++) {
    Serial.print(scalemanager.getScaleNoteName(i));
    Serial.print("\t");
  }
}

void loop() {
}