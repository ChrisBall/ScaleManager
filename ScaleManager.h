/*----------------------------------
  ScaleManager.cpp - Library for managing musical scales & note frequencies
  Created by Chris J. Ball, March 12 2016.
  Released into the public domain.
  Aims are simply to handle the musical side of things, not to do any synthesis or manage any hardware. I wrote this to speed up development of home brew MIDI instruments.
  I would appreciate input from musicologists on how this library is structured - chrisballprojects@gmail.com

  Also, currently uses a horrendous amount of dynamic memory due to 'Scale' class.
 */

#ifndef ScaleManager_h
#define ScaleManager_h
#include "Arduino.h"
#include "Scale.h"

class ScaleManager {
    
  public:
    int fundamental = 60;  //default fundamental is middle C
    int currentScale=0;    //default is chromatic
    Scale scales[8];       //chromatic, major, minor, space for 8 total
    const char noteNames[12][3]={"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
    
    ScaleManager();
    void init();
    
    void setFundamental(int NOTENUMBER);
    void addScale(int INDEX, Scale INPUTSCALE);
    void setScale(int SCALENUMBER);
    
	String getFundamentalName();
    String getScaleName();
    int getScaleNote(int NOTENUMBER);
    float getScaleNoteFreq(int NOTENUMBER);
    float getScaleNotePeriod(int NOTENUMBER);
    String getScaleNoteName(int NOTENUMBER);
    
    void loadDefaultScales();
};

#endif
