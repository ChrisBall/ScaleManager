//example that returns midi notes from the C Major scale.
#include "ScaleManager.h"

ScaleManager scalemanager;

void setup() {
  Serial.begin(9600);

  scalemanager.init();  //loads three default scales (Chromatic, Major, Minor) into scalemanager
  scalemanager.setScale(MAJOR); //sets the currently used scale to Major
  scalemanager.setFundamental(60); //sets the fundamental to middle C (this is already the default, but included for clarity)

  Serial.println(scalemanager.getFundamentalName() + scalemanager.getScaleName());
  for (int i = 0; i < 13; i++) {
    Serial.print(scalemanager.getScaleNote(i));
    Serial.print("\t");
  }

}

void loop() {
}