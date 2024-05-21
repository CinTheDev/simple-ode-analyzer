#include "controls_choose.h"

ControlsChoose::ControlsChoose(wxWindow* parent) : wxPanel(parent) {
    entries = std::vector<OdeEntry*>();

    sizer_main = new wxStaticBoxSizer(wxVERTICAL, this, "Select ODEs");

    button_create_entry = new wxButton(this, wxID_ANY, "Add ODE");
    sizer_main->Add(button_create_entry, 0, wxEXPAND);

    button_create_entry->Bind(wxEVT_BUTTON, &ControlsChoose::on_button_create, this);

    SetSizer(sizer_main);
}

ControlsChoose::~ControlsChoose() { }

void ControlsChoose::add_entry() {
    OdeEntry* new_entry = new OdeEntry(this);

    entries.push_back(new_entry);

    sizer_main->Add(new_entry, 0, wxEXPAND);

    Layout();
}

void ControlsChoose::on_button_create(wxCommandEvent& evt) {
    add_entry();
}
