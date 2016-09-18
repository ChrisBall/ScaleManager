/*----------------------------------
  ScaleManager.cpp - Library for managing musical scales & note frequencies
  Created by Chris J. Ball, March 12 2016.
  Released into the public domain.
  Aims are simply to handle the musical side of things, not to do any synthesis or manage any hardware. I wrote this to speed up development of home brew MIDI instruments.
  I would appreciate input from musicologists on how this library is structured - chrisballprojects@gmail.com

  Also, currently uses a horrendous amount of dynamic memory due to 'Scale' class.
 */

#include "Arduino.h"
#include "ScaleManager.h"

//Public functions/classes
ScaleManager::ScaleManager() {
  loadDefaultScales();
}

void ScaleManager::init() {
  loadDefaultScales();
}

void ScaleManager::setFundamental(int NOTENUMBER) {
  fundamental = constrain(NOTENUMBER, 0, 127); //limit within midi note range
}

void ScaleManager::addScale(int INDEX, Scale INPUTSCALE) {
  scales[INDEX] = INPUTSCALE;
}

void ScaleManager::setScale(int SCALENUMBER) {
  currentScale = SCALENUMBER;
}

String ScaleManager::getFundamentalName() {
  return String(noteNames[fundamental % 12]) + String(fundamental/12);
}

String ScaleManager::getScaleName() {
  return scales[currentScale].scaleName;
}

int ScaleManager::getScaleNote(int INDEX) {
  return fundamental + scales[currentScale].getNote(INDEX);
}

float ScaleManager::getScaleNoteFreq(int NOTENUMBER) {
  return 0;
#warning getScaleNoteFreq not implemented (yet).
  //returns the note frequency as a float
}

void ScaleManager::loadDefaultScales() {
  //just chromatic, major and minor for now
  //CHROMATIC
  {
    byte scaleLength = 12;
    byte scaleNotes[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    char scaleName[] = "Chromatic";
    scales[0].setScale(scaleLength, scaleNotes, scaleName);
  }

  //MAJOR
  {
    byte scaleLength = 7;
    byte scaleNotes[] = {0, 2, 4, 5, 7, 9, 11};
    char scaleName[] = "Major";
    scales[1].setScale(scaleLength, scaleNotes, scaleName);
  }

  //MINOR
  {
    byte scaleLength = 7;
    byte scaleNotes[] = {0, 2, 3, 5, 7, 8, 10};
    char scaleName[] = "Minor";
    scales[2].setScale(scaleLength, scaleNotes, scaleName);
  }
}

//Private functions/classes


