#include "DisplayTUI.h"
#include <iostream>

#ifdef _WIN32
DisplayTUI::DisplayTUI() {
  // Najwazniejsze to inicjalizacja stanu display.
}

#elif __linux__

DisplayTUI::DisplayTUI() {

  terminalTakeOver();

  remakeDisplayBuffer(get_displayDimensions());

  TUIPanelMain mainPanel(displayDimensions, 
                         UIAlignment::MAIN);

  // TODO
  // TUIPanelInfo infoPanel(displayDimensions, UIAlignment::TL);
  // TUIPanelGeneration generationPanel(displayDimensions, UIAlignment::BR);

  UIElements.push_back(&mainPanel);

  // TODO
  // UIElements.push_back(&generationPanel);
  // UIElements.push_back(&infoPanel);
}

DisplayTUI::~DisplayTUI() {
  terminalRelease();
  delete[] displayBuffer;
}

char *DisplayTUI::remakeDisplayBuffer(Dim dimensions) {
  delete[] displayBuffer;
  displayBuffer = new char[dimensions.area()]; // TODO:
  return displayBuffer;
}

Pos DisplayTUI::calculateTopLeft(Dim dim, enum UIAlignment align) {
  // TEST THISSSSS
  switch (align) {
  case UIAlignment::MAIN:
    return {0, 0};

  case UIAlignment::TL:
    return {0, 0};

  case UIAlignment::TR:
    return {displayDimensions.width - dim.width, 0};

  case UIAlignment::BL:
    return {0, displayDimensions.height - dim.height};

  case UIAlignment::BR:
    return {displayDimensions.width - dim.width,
            displayDimensions.height - dim.height};

  case UIAlignment::OVER:
    return {displayDimensions.center().x - dim.center().x,
            displayDimensions.center().y - dim.center().y};
  default:
    break;
  }

  return {0, 0};
}

void DisplayTUI::writeToDisplayBuffer(const TUIPanel &e) {
  Pos topLeft = calculateTopLeft(e.dimensions, e.align);

  // TEST: should be right? this might go off might not
  for (int y = 0; y < e.dimensions.height; y++)
    for (int x = 0; x < e.dimensions.width; x++)
      displayBuffer[(displayDimensions.width * topLeft.y) + topLeft.x + x] =
          e.contents[(y * e.dimensions.width) + x];
}

void DisplayTUI::draw() {
  flattenDrawables();
  std::cout.write(displayBuffer, displayDimensions.area());
  std::cout.flush();
}

// writeToDisplayBuffer();
// TODO
//
// for shure iteracja po jakiejś podwójnej array, może lepiej będzie po
// pojedyczej zobaczymy. calls like that będą na pewno:
//
// // ROUTINE
// fflush(stdout);

// FIX // nevermind?jjgg
void DisplayTUI::flattenDrawables() {
  for (int i = 0; i < UIElements.size(); i++) {
    writeToDisplayBuffer(*UIElements[i]); // TODO
  }
  // writeToDisplayBuffer(Dim size, char *inBuffer) //calculateTopLeft  TODO
}

void DisplayTUI::terminalTakeOver() {

  printf("\x1b[?25l"); // cursor invisible

  // tcgetattr(STDIN_FILENO, &normal_mode);

  // kopia poprzedniego stanu i wejście w raw mode
  struct termios raw = normal_mode;
  raw.c_lflag &= ~(ECHO | ICANON);
  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 1;
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void DisplayTUI::terminalRelease() {
  printf("\x1b[?25h\x1b[2J\x1b[H"); // cursor visible // clear scr // go 00
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &normal_mode);
}

Dim DisplayTUI::set_displayDimensions() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  displayDimensions = {w.ws_col, w.ws_row};
  return displayDimensions;
}

Dim DisplayTUI::get_displayDimensions() {
  return displayDimensions;
}

void DisplayTUI::handleResize() {

  // TODO
}

void DisplayTUI::set_resizePendingFlag(bool flag) { shouldResize = flag; }

#else
#endif
