#include "App.h"
App::App(Simulation *sim, Dim plansza) : display(plansza) { simulation = sim; }
void App::update() {

  simulation->update();
  display.board = simulation->shareBoardState();

  display.clearScreen();
   display.update();
}

void App::onStart() {
  display.hideCursor();
}

void App::onClose() {
  display.showCursor();
}
