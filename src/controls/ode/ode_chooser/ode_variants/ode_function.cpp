#include "ode_function.h"

const wxString numerical_method_labels[] = {
    "Euler",
};

OdeFunction::OdeFunction(wxWindow* parent, wxString label) : OdeEntry(parent, label) {
    label_length = new wxStaticText(this, wxID_ANY, "Amount calculated values");
    label_step_x = new wxStaticText(this, wxID_ANY, "Step along x");

    input_length = new wxTextCtrl(this, wxID_ANY, "l");
    input_step_x = new wxTextCtrl(this, wxID_ANY, "x");

    add_option(label_length, input_length);
    add_option(label_step_x, input_step_x);

    const size_t amount_options = sizeof(numerical_method_labels) / sizeof(numerical_method_labels[0]);
    dropdown_numerical_method = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, amount_options, numerical_method_labels);
    dropdown_numerical_method->SetSelection(0);
    sizer_main->Prepend(dropdown_numerical_method, 0, wxEXPAND | wxALL & ~wxBOTTOM, 10);
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
