#pragma once

#ifndef DISPLAY_H
#define DISPLAY_H

#include <conio.h>
#include <cstdio>
#include <vector>
#include <windows.h>

#include "utils.h"

class Display {
public:
  Display(Dim plansza);

  Dim displayDim;
  bool *board;
  int displayDimentions = 400;

  void update();
  void clearScreen();

  void showCursor();
  void hideCursor();

private:
  char *displayBuffer;

  void draw();


  // windowsowe żeczy
  HANDLE hIn;
  HANDLE hOut;
};

#endif // DISPLAY_H
