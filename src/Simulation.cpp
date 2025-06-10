#include "Simulation.h"

// nie wiem czy zastąpiuć to init(); wyjdzie w praniu
Simulation::Simulation(Dim drawableAreaDim)
    : board({drawableAreaDim.width - 2, drawableAreaDim.height - 2}),
      ant(drawableAreaDim.center()) {};

Simulation::Simulation(Dim drawableAreaDim, Pos antPosition)
    : board({drawableAreaDim.width - 2, drawableAreaDim.height - 2}),
      ant(antPosition) {};

void Simulation::update() {
  ant.update();
  board.update();
}
// overload? - maybe later

// THIS MIGHT BELONG IN THE BASE CLASS. TODO
