#include "controls_choose.h"

ControlsChoose::ControlsChoose(wxWindow* parent) : Controls(parent, "Select ODEs") {
    test_button = new wxButton(this, wxID_ANY, "ODE chooser");

    sizer_main->Add(test_button, 1, wxEXPAND);
}

ControlsChoose::~ControlsChoose() { }
