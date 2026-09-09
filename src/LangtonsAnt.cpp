#include "LangtonsAnt.h"

LangtonsAnt::LangtonsAnt(Dim plansza) {
  wymiartyPlanszy = plansza;
  board = new bool[plansza.x * plansza.y];

  for (int i = 0; i < plansza.x * plansza.y; i++) {
    board[i] = false;
  }
  antPosition = {plansza.x / 2, plansza.y / 2};
}
void LangtonsAnt::update() { step(); }

void LangtonsAnt::step() {
  int idx = antPosition.y * wymiartyPlanszy.x + antPosition.x;
  // jeżeli stoi na pełnym
  if (board[idx]) {
    antsDirection.turnLeft();
  }
  // jeżeli stoi na pustym
  else {
    antsDirection.turnRight();
  }
  board[idx] = !board[idx];
  antPosition = {antPosition.x + antsDirection.x,
                 antPosition.y + antsDirection.y};
};
