#include "ode_oscillation_harmonic.h"

Ode_Oscillation_Harmonic::Ode_Oscillation_Harmonic(wxWindow* parent) : OdeFunction(parent, "Harmonic Oscillation") {
    some_label = new wxStaticText(this, wxID_ANY, "Some label");
    some_option = new wxTextCtrl(this, wxID_ANY, "Some option");

    add_option(some_label, some_option);

    set_result_length(100);
}

Ode_Oscillation_Harmonic::~Ode_Oscillation_Harmonic() { }

double Ode_Oscillation_Harmonic::evaluate_function(double x) {
    return -10.0 * 10.0 * x;
}
