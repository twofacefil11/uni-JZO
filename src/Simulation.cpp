#include "Simulation.h"

// nie wiem czy zastąpiuć to init(); wyjdzie w praniu
Simulation::Simulation(Dim drawableAreaDim)
    : board(drawableAreaDim), ant(drawableAreaDim.center()) {};

Simulation::Simulation(Dim drawableAreaDim, Pos antPosition)
    : board(drawableAreaDim), ant(antPosition) {};
