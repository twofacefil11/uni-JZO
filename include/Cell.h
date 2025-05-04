#pragma once

#ifndef CELL_H
#define CELL_H

#include "utils.h"

class Cell {
private:
  bool state;
  Pos index;

public:
  Cell(Pos index, bool state = 0); // nie wiem jeszcze co będze wygodniejsze
  Cell(unsigned int x, unsigned int y, bool state = 0);

  void flipState(); // a friend or something? naa..
};
#endif // CELL_H
