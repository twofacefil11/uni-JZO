#pragma once

#ifndef ANT_H
#define ANT_H

#include "utils.h"

class Cell;

class Ant {
private:
  Pos position;
  Dir direction = {1, 0}; // możliwe że będziemy chcieli precyzować dir mrówki
                          // na starcie later.......

  Pos calculateCenter(Dim boardDimentions);

public:
  Ant(Pos position);
  void go();
  void turnRight();
  void turnLeft();
  void flipState(); //zobaczymy jak to będzi
};

#endif // ANT_H
