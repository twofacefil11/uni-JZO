#pragma once

#ifndef SEEDS_H
#define SEEDS_H 

#include <cstdlib>
#include <ctime>
#include "Simulation.h"
#include "utils.h"


class Seeds : public Simulation {
private:
    int countAround(int i);
    void step() override;
public:
    Seeds(Dim plansza);
    Dim wymiaryPlanszy;
    void update() override;
};

#endif // SEEDS_H
