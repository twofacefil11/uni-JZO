#include "GameOfLife.h"

GameOfLife::GameOfLife(Dim plansza) {
  std::srand(std::time(nullptr));
  wymiaryPlanszy = plansza;
  board = new bool[plansza.x * plansza.y];

  for (int i = 0; i < plansza.x * plansza.y; i++) {
    board[i] = (rand() % 4) == 3;
  }
}

void GameOfLife::update() { step(); }

void GameOfLife::step() {
  bool *newBoard = new bool[wymiaryPlanszy.x * wymiaryPlanszy.y];
  int count = 0;
  int idx = 0;
  for (int y = 0; y < this->wymiaryPlanszy.y; y++) {
    for (int x = 0; x < this->wymiaryPlanszy.x; x++) {
      idx = y * wymiaryPlanszy.x + x;
      count = countAround(idx);
                
      if (board[idx]) {
        newBoard[idx] = (count == 2 || count == 3);
      } else {
        newBoard[idx] = (count == 3);
      }
    }
  }
  delete[] board;
  board = newBoard;
}

int GameOfLife::countAround(int i) {
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
