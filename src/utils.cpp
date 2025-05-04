#include "utils.h"

void Dir::turnLeft() {
  int tmp = y;
  y = x;
  x = -tmp;
}

void Dir::turnRight() {
  int tmp = x;
  x = y;
  y = -tmp;
}

void Dir::turnBack() {
  x = -x;
  y = -y;
}

unsigned int Dim::area() {
  return width * height;
}

Pos Dim::center() {
  return {width >> 1, height >> 1};
}
