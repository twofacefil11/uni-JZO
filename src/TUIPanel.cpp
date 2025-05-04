#include "TUIPanel.h"
#include "utils.h"

TUIPanel::TUIPanel(Dim dim, UIAlignment al)
    : dimensions(dim), align(al), contents(dim.area(), ' ') {}
