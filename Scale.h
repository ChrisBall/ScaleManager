/*
 * This model of scale assumes use of the chromatic scale, i.e. 12 notes per octave.
 */
#ifndef Scale_h
#define Scale_h
#include "Arduino.h"

class Scale {
    
  public:
  
    char scaleName[16];
    byte scaleNotes[12];  
    byte scaleLength;
    
    Scale();
    void setScale(byte LENGTH, byte NOTES[], char NAME[]);
    int getNote(int INDEX);

};

#endif
