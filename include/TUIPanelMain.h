#pragma once

#ifndef TUIPANELMAIN_H
#define TUIPANELMAIN_H

#include "TUIPanel.h"

class TUIPanelMain : public TUIPanel {
public:
  TUIPanelMain(Dim dimensions, UIAlignment al);
  void update() override;

};

#endif // TUIPANELMAIN_H
