#include "Ant.h"

Ant::Ant(Pos position) : position(position) {};
// buffer będzie odpowiedzialny za wyznaczanie środka

void Ant::go() {
  position.x += direction.x;
  position.y += direction.y;
}

void Ant::turnLeft() {
  direction.turnLeft();
}

void Ant::turnRight() {
  direction.turnRight();
}

void Ant::flipState() {
  direction.turnBack();
}
