#include "App.h"

App::App() : display(), simulation(display.get_displayDimensions()) {}
 
// NOTE
// turn on -Wreorder (GCC/Clang) - powiadamia o kolejności wywoływania i
// deklarowania. ważne xd
