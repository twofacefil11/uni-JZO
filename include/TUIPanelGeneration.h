#pragma once

#ifndef TUIPANELGENERATION_H
#define TUIPANELGENERATION_H

#include "TUIPanel.h"

class TUIPanelGeneration : public TUIPanel {
public:
  TUIPanelGeneration(Dim dim , UIAlignment al);
  void update() override;
};

#endif // TUIPANELGENERATION_H
