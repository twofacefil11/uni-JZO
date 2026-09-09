#pragma once

#ifndef RULE90_H
#define RULE90_H

#include <cstdlib>
#include <ctime>

#include "Simulation.h"
#include "utils.h"

class Rule90 : public Simulation {

private:
  void step() override;
  int currRow = 1;

public:
  Rule90(Dim plansza);
  Dim wymiaryPlanszy;
  void update() override;
};

#endif // RULE90_H
