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

int OdeFunction::get_length() {
    return get_input_int(input_length, label_length);
}

double OdeFunction::get_step_x() {
    return get_input_double(input_step_x, label_step_x);
}

double OdeFunction::evaluate_function(double fx) { }

void OdeFunction::calculate() {

}

void OdeFunction::calculate_euler() {

}
