#pragma once

#ifndef APP_H
#define APP_H

#include "Display.h"
#include "Simulation.h"
#include <cstdio>
#include <memory>

class App {
public:
  App(Simulation *sim, Dim plansza);
  void update();
  
  void onStart();
  void onClose();

private:
  Display display;
  Simulation *simulation;
};

#endif // APP_H
