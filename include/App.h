#pragma once

#include "Display.h"
#include "Simulation.h"

#ifndef APP_H
#define APP_H

// ist gonna hold the state somehow? i dont fucking know
class App {

public:
  App();
  void run();
  void init();


private:
  Display display;
  //
  //aplikacja będzie zażądzać wymianą informacji między sim a disp.
  
  Simulation simulation();
};

#endif // APP_H
