#pragma once

#include <windows.h>

#ifndef UTILS_H
#define UTILS_H

typedef struct Dim {
  unsigned int x;
  unsigned int y;
} Dim;

struct Dir {
  int x;
  int y;
  void turnRight();
  void turnLeft();
};

inline void Dir::turnLeft() {
  int tmp = y;
  y = x;
  x = -tmp;
}

inline void Dir::turnRight() {
  int tmp = x;
  x = y;
  y = -tmp;
}

inline Dim getScreenDim() {
  HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO info;

  if (!GetConsoleScreenBufferInfo(out, &info)) {
    return {0, 0}; // or handle error however you'd like
  }

  unsigned int width = info.srWindow.Right - info.srWindow.Left + 1;
  unsigned int height = info.srWindow.Bottom - info.srWindow.Top + 1;

  return {width - 10, height - 10};
}

#endif
