#include "controls_specialized.h"

ControlsSpecialized::ControlsSpecialized(wxWindow* parent) : wxPanel(parent) {
    sizer_main = new wxFlexGridSizer(2, 5, 5);
    sizer_main->AddGrowableCol(0, 1);

    SetSizer(sizer_main);
}

ControlsSpecialized::~ControlsSpecialized() { }
