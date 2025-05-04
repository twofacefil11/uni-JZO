#pragma once

#ifndef UTILS_H
#define UTILS_H

typedef struct { // tęsknie za tobą, och C. 
  unsigned int x;
  unsigned int y;
} Pos;

struct Dim { 
  unsigned int width;
  unsigned int height;

  unsigned int area();
  Pos center();
};

struct Dir {
  int x;
  int y;

  void turnRight();
  void turnLeft();
  void turnBack(); 
};

#endif // UTILS_H
