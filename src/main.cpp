#include "App.h"

#include "LangtonsAnt.h"
#include "GameOfLife.h"
#include "Rule90.h"
#include "Diamoeba.h"
#include "Seeds.h"

#include <cstdio>
#include <windows.h>

int main(void) {

  // Dim plansza = {100, 100};
  Dim plansza = getScreenDim();

  // LangtonsAnt *simulation = new LangtonsAnt(plansza);
  // GameOfLife *simulation = new GameOfLife(plansza);
  // Seeds *simulation = new Seeds(plansza);
  // Rule90 *simulation = new Rule90(plansza);
  Diamoeba *simulation = new Diamoeba(plansza);

  App app(simulation, plansza);
  app.onStart();

  int generations = 0;

  while (generations < 2000) {
    app.update();
    generations++;
    Sleep(1000/75);
  }

  app.onClose();
  printf("\n");
  delete simulation;
}
