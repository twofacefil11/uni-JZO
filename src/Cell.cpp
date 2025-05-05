#include "Cell.h"

Cell::Cell(Pos index, bool state) : index(index), state(state) {}
Cell::Cell(unsigned int x, unsigned int y, bool state)
    : index{x, y}, state(state) {}


void Cell::flipState() { state = !state; }
