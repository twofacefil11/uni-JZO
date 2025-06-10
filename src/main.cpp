
#include "App.h"

int main() {
  // the main should only create the app and run it.
  // teoretycznie w każdym razie
  //
  //
  //  gdzieś apka musi definiować w jaki sposób będzie odpalana.
  //  podejrzewam że command line arguments to będzie to
  //
  //  anyways keep it simple.

  App app;
  app.update();
  // simulation and display may have init.
  // simualtion may initialize with the constructor,
  // the display rather cant or shouldnt.
  // app.display.init();

  // the app needs to know:
  //  - the simulatiion type
  //  - the operating system
  //  - the sisplay way.
  //
  //  - it may be done by asking on the screen or by the
  //  - command line argumenst ideally i would make it so that it wont be a
  //  hustle to port it later.
}
