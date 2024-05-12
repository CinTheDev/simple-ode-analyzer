#include "controls_ode.h"

ControlsODE::ControlsODE(wxWindow* parent) : wxPanel(parent) {
    sizer_main = new wxBoxSizer(wxHORIZONTAL);

    test_button = new wxButton(this, wxID_ANY, "Controls ODE");
    sizer_main->Add(test_button, wxEXPAND);

    SetSizer(sizer_main);
}

ControlsODE::~ControlsODE() { }
