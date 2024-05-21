#include "controls_choose.h"

ControlsChoose::ControlsChoose(wxWindow* parent) : Controls(parent, "Select ODEs") {
    button_create_entry = new wxButton(this, wxID_ANY, "Add ODE");

    entries = std::vector<OdeEntry*>();

    sizer_main->Add(button_create_entry, 0, wxEXPAND);

    add_entry();
}

ControlsChoose::~ControlsChoose() { }

void ControlsChoose::add_entry() {
    OdeEntry* new_entry = new OdeEntry(this);

    entries.push_back(new_entry);

    sizer_main->Add(new_entry, 0, wxEXPAND);
}
