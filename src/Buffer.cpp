#include "Buffer.h"

// : dimensions(dimensions)//, cells(dimensions.height),
// std::vector<Cell>(dimensions.width, Cell(Pos))
// naprawde brzydki syntax.

Buffer::Buffer(Dim dim)
    : dimensions(dim), cells(dim.height, std::vector<Cell>(dim.width)) {

  for (int y = 0; y < dimensions.height; ++y) {
    for (int x = 0; x < dimensions.width; ++x) {
      cells[y][x] = Cell(x, y);
    }
  }
}

void Buffer::update() {
// TODO
}
