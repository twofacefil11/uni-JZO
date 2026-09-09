#include "Diamoeba.h"

Diamoeba::Diamoeba(Dim plansza) {
  std::srand(std::time(nullptr));
  wymiaryPlanszy = plansza;
  board = new bool[plansza.x * plansza.y];

  for (int i = 0; i < plansza.x * plansza.y; i++) {
    board[i] = (rand() % 2) == 0;
  }
}

void Diamoeba::update() { step(); } 


void Diamoeba::step() {
  bool *newBoard = new bool[wymiaryPlanszy.x * wymiaryPlanszy.y];

  for (int y = 0; y < wymiaryPlanszy.y; y++) {
    for (int x = 0; x < wymiaryPlanszy.x; x++) {
      int idx = y * wymiaryPlanszy.x + x;
      int count = countAround(idx);

      if (!board[idx]) {
        // Birth conditions
        newBoard[idx] = (count == 3 || count == 5 || count == 6 ||
                         count == 7 || count == 8);
      } else {
        // Survival condition
        newBoard[idx] = (count >= 5);  // stays alive only if 5–8 neighbors
      }
    }
  }

  delete[] board;
  board = newBoard;
}


int Diamoeba::countAround(int i) {
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
