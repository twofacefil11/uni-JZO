#pragma onc

#ifndef SIMULATION_H
#define SIMULATION_H

#include "Ant.h"
#include "Buffer.h"

class Simulation {
public:
  Simulation(Dim drawableArea);
  Simulation(Dim drawableArea, Pos antPosition);
  

  // jak dodam ID to będzie można puszczać kilka symulacja na raz
  void start();
  void step(); // TODO please cap the ant... 
  void stop();
  void restart();
  void quit();

  unsigned int get_generation();

  void handleResize();                         //???????
  void fastForeward(unsigned int generations); // ?????????????????

private:
  Ant ant;
  Buffer board;

  bool is_running = 0;
  bool shouldQuit = 0;

  unsigned int generation = 0;
};

#endif // SIMULATION_H
