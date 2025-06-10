#pragma once

#ifndef DISPLAYTUI_H
#define DISPLAYTUI_H

#ifdef _WIN32
// TODO

#elif __linux__
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#endif
#include "TUIPanel.h"
#include "TUIPanelGeneration.h"
#include "TUIPanelInfo.h"
#include "TUIPanelMain.h"

#include "Display.h"
#include <map>
#include <memory>
#include <stdio.h>

class DisplayTUI : public Display {

public:
  DisplayTUI();
  ~DisplayTUI();

  void draw() override;
  void init() override; // ???
  void update() override;

  // void get_userWorkingArea() override; // to możliwe że powinno być w BOX, po
  // dodaniu ramki

  Dim get_displayDimensions() override;

private:
  // std::vector<Drawable> elementQue; // to nie jest struktura, que, to tylko
  std::vector<TUIPanel *> UIElements;
  // jeżeli tak to
  char *displayBuffer = nullptr;

  void terminalTakeOver();
  void terminalRelease();

  char *remakeDisplayBuffer(Dim dimensions) override;
  void set_resizePendingFlag(bool flag) override; // well see
  void handleResize() override;

  // void writeToDisplayBuffer(Dim size, char *inBuffer, enum UIAlignment
  // align);
  void writeToDisplayBuffer(const TUIPanel &);
  void flattenDrawables();

  Pos calculateTopLeft(Dim dim, enum UIAlignment align);
  Dim set_displayDimensions() override;
#ifdef _WIN32
#elif __linux__
  struct termios normal_mode; // set by terminalTakeOver() do przywołania
#endif
};

#endif // DISPLAYTUI_H
