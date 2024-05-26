#include "ode_function.h"

OdeFunction::OdeFunction(wxWindow* parent, wxString label) : OdeEntry(parent, label) {
    label_length = new wxStaticText(this, wxID_ANY, "Amount calculated values");
    label_step_x = new wxStaticText(this, wxID_ANY, "Step along x");

    input_length = new wxTextCtrl(this, wxID_ANY, "l");
    input_step_x = new wxTextCtrl(this, wxID_ANY, "x");

    add_option(label_length, input_length);
    add_option(label_step_x, input_step_x);
}

OdeFunction::~OdeFunction() { }
