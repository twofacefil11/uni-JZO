#pragma once

#include <memory>

#include "Display.h"
#include "Simulation.h"

#ifndef APP_H
#define APP_H

// ist gonna hold the state somehow? i dont fucking know
class App {

public:
  App(std::unique_ptr<Simulation> sinulation, std::unique_ptr<Display> display);
  template <typename Sim, typename Dis> App makeApp();
  void update();

private:
  std::unique_ptr<Display> display;
  std::unique_ptr<Simulation> simulation;
};

#endif // APP_H
