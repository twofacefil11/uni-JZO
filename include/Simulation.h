#pragma once

#ifndef SIMULATION_H
#define SIMULATION_H

class Simulation {
protected:
  bool *board;

public:
  int generationCount = 0;
  virtual void step() = 0;
  virtual void update() = 0;
  bool *shareBoardState();
};

#endif // SIMULATION_H
