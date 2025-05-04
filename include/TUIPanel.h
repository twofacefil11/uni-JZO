#pragma once

#ifndef TUIPANEL_H
#define TUIPANEL_H

#include "utils.h"
#include <vector>

enum class UIAlignment { MAIN, TL, TR, BL, BR, OVER, size };


class TUIPanel {
public:
  TUIPanel(Dim dimensions, UIAlignment al);
 
  virtual void update() = 0;

  std::vector<char> contents;
  Dim dimensions;
  UIAlignment align;
private:

  // wydaje mi się ze konstruktorze powinno być dla każdego z nich osobno zchardkodowane co będzie wyświtlał ków ai gdzie. indexy innych żeczy mogą być ważne kórwa nie wiem for real może będdę to dopominał będe kórwa uważał na samym końcu anyway there needds to be a way of knowing whats the size of me and aslo what is the content size and the full zize with the order and if so wha is gonna be firs. so i guess the display initializes the stuff . it only can kno w the hardcoded  lsize of itsself, the rst like in eneration might change. and i would like it to resize acdcordingly so why dont i do this when i implement the update for everything fuck that for fucking real lest go back to displaytui
};

#endif // TUIPANEL_H
