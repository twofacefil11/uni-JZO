#pragma once

#ifndef DIAMOEBA_H
#define DIAMOEBA_H


#include <cstdlib>
#include <ctime>

#include "Simulation.h"
#include "utils.h"

class Diamoeba : public Simulation {
    private:
    void step() override;
    int countAround(int i);
    
public:
    Diamoeba(Dim plansza);
    Dim wymiaryPlanszy;
    void update() override;

};

#endif // DIAMOEBA_H
