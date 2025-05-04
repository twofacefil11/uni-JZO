#include "Cell.h"

Cell::Cell(unsigned int x, unsigned int y, bool state)

: index{x, y}, state(state) {}
Cell::Cell(Pos index, bool state) : index(index), state(state) {}

void Cell::flipState() { state = !state; }
