#pragma once

#ifndef TUIPANELINFO_H
#define TUIPANELINFO_H

#include "TUIPanel.h"

class TUIPanelInfo : public TUIPanel {
public:
  TUIPanelInfo();
  void update() override;
};

#endif // TUIPANELINFO_H
