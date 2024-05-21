#include "controls_choose.h"

ControlsChoose::ControlsChoose(wxWindow* parent) : Controls(parent, "Select ODEs") {
    button_create_entry = new wxButton(this, wxID_ANY, "Add ODE");

    entries = std::vector<OdeEntry>();

    sizer_main->Add(button_create_entry, 1, wxEXPAND);
}

ControlsChoose::~ControlsChoose() { }
