#pragma once

#ifndef BUFFER_H
#define BUFFER_H

#include "Cell.h"
#include "utils.h"
#include <vector>

class Buffer {
private:
  std::vector<std::vector<Cell>> cells;
  Dim dimensions;

public:
  Buffer(Dim dim);
  void update();

  Cell &at(Pos position); // dla mrówki, może się przydać
};


#endif // BUFFER_H
