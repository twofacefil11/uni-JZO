#include "Buffer.h"

// : dimentions(dimentions)//, cells(dimentions.height),
// std::vector<Cell>(dimentions.width, Cell(Pos))
// naprawde brzydki syntax.
Buffer::Buffer(Dim dimentions)
    : dimentions(dimentions),
      cells(dimentions.height, std::vector<Cell>(dimentions.width))
{
  for (int y = 0; y < dimentions.height; ++y) {
    for (int x = 0; x < dimentions.width; ++x) {
      cells[y][x] = Cell(x, y);
    }
  }
}
