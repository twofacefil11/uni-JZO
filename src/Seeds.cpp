#include "Seeds.h"

Seeds::Seeds(Dim plansza) {
  std::srand(std::time(nullptr));

  wymiaryPlanszy = plansza;
  board = new bool[plansza.x * plansza.y];

  for (int i = 0; i < plansza.x * plansza.y; i++) {
    board[i] = (rand() % 100) == 1;
  }
}

void Seeds::update() { step(); }

void Seeds::step() {
  bool *newBoard = new bool[wymiaryPlanszy.x * wymiaryPlanszy.y];
  int count = 0;
  int idx = 0;
  for (int y = 0; y < this->wymiaryPlanszy.y; y++) {
    for (int x = 0; x < this->wymiaryPlanszy.x; x++) {
      idx = y * wymiaryPlanszy.x + x;
      count = countAround(idx);

      // jeżeli żeyje
      if (!board[idx]) {
        newBoard[idx] = (count == 2);
      }
    }
  }
  delete[] board;
  board = newBoard;
}

int Seeds::countAround(int i) {
  int x = i % wymiaryPlanszy.x;
  int y = i / wymiaryPlanszy.x;
  int sum = 0;
  for (int dy = -1; dy <= 1; dy++) {
    int ny = y + dy;
    if (ny < 0 || ny >= wymiaryPlanszy.y)
      continue;
    for (int dx = -1; dx <= 1; dx++) {
      int nx = x + dx;
      if (nx < 0 || nx >= wymiaryPlanszy.x)
        continue;
      if (dx == 0 && dy == 0)
        continue;
      int idx = ny * wymiaryPlanszy.x + nx;
      if (board[idx])
        sum++;
    }
  }
  return sum;
}
