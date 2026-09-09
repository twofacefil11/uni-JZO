#pragma once

#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <cstdlib>
#include <ctime>

#include "Simulation.h"
#include "utils.h"

class GameOfLife : public Simulation {
private:
    int countAround(int i);
    void step() override;
public:
    GameOfLife(Dim plansza);
    Dim wymiaryPlanszy;
    void update() override;
};

#endif // GAMEOFLIFE_H
