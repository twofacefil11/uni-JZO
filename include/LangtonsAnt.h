#pragma once

#ifndef LANGTONSANT_H
#define LANGTONSANT_H

#include <cstdio>

#include "Simulation.h"
#include "utils.h"

class LangtonsAnt : public Simulation {
private:
  void step() override;
  Dim wymiartyPlanszy;
  Dir antsDirection = {0, 1};
  Dim antPosition;

public:
  LangtonsAnt(Dim plansza);
  void update() override;
};

#endif // LANGTONSANT_H
