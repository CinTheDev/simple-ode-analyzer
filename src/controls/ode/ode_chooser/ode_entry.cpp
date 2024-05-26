#include "ode_entry.h"
#include "events.h"

OdeEntry::OdeEntry(wxWindow* parent, wxString name) : Controls(parent, name) {
    init_elements();
    init_sizers();

    result_length = 0;
    result = new double[1];
}

OdeEntry::~OdeEntry() {
    delete[] result;
}

void OdeEntry::init_elements() {
    colour_picker = new wxColourPickerCtrl(this, wxID_ANY, *wxRED);
    button_up = new wxButton(this, wxID_ANY, "Up");
    button_down = new wxButton(this, wxID_ANY, "Down");
    button_remove = new wxButton(this, wxID_ANY, "Remove");
}

void OdeEntry::init_sizers() {
    sizer_options = new wxBoxSizer(wxHORIZONTAL);

    sizer_options->Add(colour_picker, 1);
    sizer_options->Add(button_up, 0);
    sizer_options->Add(button_down, 0);
    sizer_options->Add(button_remove, 0);

    sizer_main->Prepend(sizer_options, 0, wxEXPAND | wxALL, 10);
    sizer_main->GetItem(1)->SetFlag(wxEXPAND | wxALL & ~wxTOP); // Flags of sizer_grid

    SetSizer(sizer_main);
}

void OdeEntry::add_option(wxStaticText* label, wxTextCtrl* input) {
    sizer_grid->Add(label);
    sizer_grid->Add(input);
}

size_t OdeEntry::get_result_length() {
    return result_length;
}

double* OdeEntry::get_result(size_t& result_length) {
    calculate();
    result_length = this->result_length;
    return result;
}

void OdeEntry::set_result_length(size_t new_length) {
    delete[] result;
    result = new double[new_length];

    result_length = new_length;
}

uint32_t OdeEntry::get_colour() {
    return colour_picker->GetColour().GetRGBA();
}

void OdeEntry::enable_buttons(bool button_up, bool button_down) {
    this->button_up->Enable(button_up);
    this->button_down->Enable(button_down);
}

void OdeEntry::calculate() { }
