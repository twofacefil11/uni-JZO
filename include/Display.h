#pragma once

#include "Buffer.h"
#ifndef DISPLAY_H
#define DISPLAY_H

#include "utils.h"

class Display {
public:
  virtual void draw();
  virtual void init(); // nie wiem czy będzie potrzebne. ale raczej tak

  void pull_generation(unsigned int generation);

  Dim push_userWorkingArea();

private:
  
  virtual Dim get_displayDimensions();
  virtual void set_resizePendingFlag(bool flag);
  virtual void get_userWorkingArea();
  virtual void handleResize();
  virtual char* remakeDisplayBuffer(Dim dimensions);

protected:

  bool shouldResize = 1; // w app loopie będzie nadkondycja youll see
  unsigned int generation = 0; // simualtion data class? maybe?
  Dim displayDimensions = {0, 0}; // ?????
  
  // Dim userWorkingArea = {0, 0};
};

#endif // DISPLAY_H
