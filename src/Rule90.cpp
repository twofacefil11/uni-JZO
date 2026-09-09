#include "Rule90.h"

Rule90::Rule90(Dim plansza) {
  std::srand(std::time(nullptr));
  wymiaryPlanszy = plansza;
  board = new bool[plansza.x * plansza.y];

  for (int i = 0; i < plansza.x * plansza.y; i++) {
    if (i < plansza.x)
      board[i] = (rand() % 30) == 1;
    else
      board[i] = 0;
  }
}

void Rule90::update() { step(); };

void Rule90::step() {
  if (currRow >= wymiaryPlanszy.y)
    return; // stop if bottom reached

  for (int x = 0; x < wymiaryPlanszy.x; x++) {
    int idx = currRow * wymiaryPlanszy.x + x;

    bool left =
        (x == 0) ? 0 : board[(currRow - 1) * wymiaryPlanszy.x + (x - 1)];
    bool right = (x == wymiaryPlanszy.x - 1)
                     ? 0
                     : board[(currRow - 1) * wymiaryPlanszy.x + (x + 1)];

    board[idx] = left ^ right;
  }

  currRow++;
}
