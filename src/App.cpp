#include "App.h"

App::App(Simulation simulation, Display display) {
  
  
}

template<typename simulation, typename display>
App App::makeApp() {
  return App(std::make_unique<simulation>(), std::make_unique<display>());
}

// App::App() : display(), simulation(display.get_displayDimensions()) {}

// NOTE
// turn on -Wreorder (GCC/Clang) - powiadamia o kolejności wywoływania i
// deklarowania. ważne xd
//----------------------------------------------------------------------
//
void App::update() {
  simulation.update();
  display.update();
}
