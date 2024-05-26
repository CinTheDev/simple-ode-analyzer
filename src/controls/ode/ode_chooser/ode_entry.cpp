#include "ode_entry.h"
#include "events.h"

OdeEntry::OdeEntry(wxWindow* parent) : Controls(parent, "") {
    init_elements();
    init_sizers();
}

OdeEntry::~OdeEntry() { }

void OdeEntry::init_elements() {
    colour_picker = new wxColourPickerCtrl(this, wxID_ANY, *wxRED);
    button_up = new wxButton(this, wxID_ANY, "Up");
    button_down = new wxButton(this, wxID_ANY, "Down");
    button_remove = new wxButton(this, wxID_ANY, "Remove");
}

void OdeEntry::init_sizers() {
    sizer_options_vertical = new wxBoxSizer(wxVERTICAL);
    sizer_options_horizontal = new wxBoxSizer(wxHORIZONTAL);

    sizer_options_horizontal->Add(colour_picker, 1);
    sizer_options_horizontal->Add(button_up, 0);
    sizer_options_horizontal->Add(button_down, 0);
    sizer_options_horizontal->Add(button_remove, 0);

    sizer_options_vertical->Add(sizer_options_horizontal, 0, wxEXPAND);

    sizer_main->Prepend(sizer_options_vertical, 0, wxEXPAND | wxALL & ~wxTOP, 10);
    sizer_main->GetItem(1)->SetFlag(wxEXPAND | wxALL & ~wxTOP); // Flags of sizer_grid

    SetSizer(sizer_main);
}

uint32_t OdeEntry::get_colour() {
    return colour_picker->GetColour().GetRGBA();
}

void OdeEntry::enable_buttons(bool button_up, bool button_down) {
    this->button_up->Enable(button_up);
    this->button_down->Enable(button_down);
}
