#include "ode_oscillation_harmonic.h"

Ode_Oscillation_Harmonic::Ode_Oscillation_Harmonic(wxWindow* parent) : OdeFunction(parent, "Harmonic Oscillation - Generic") {
    label_omega = new wxStaticText(this, wxID_ANY, "w [s^-1]");
    input_omega = new wxTextCtrl(this, wxID_ANY, "10.0");

    add_option(label_omega, input_omega);

    // Edit options
    label_initial_s->SetLabel("s_0 [m]");
    label_initial_v->SetLabel("v_0 [m * s^-1]");
}

Ode_Oscillation_Harmonic::~Ode_Oscillation_Harmonic() { }

double Ode_Oscillation_Harmonic::evaluate_function(double fx) {
    double w = get_omega();
    return -w * w * fx;
}

double Ode_Oscillation_Harmonic::get_omega() {
    return get_input_double(input_omega, label_omega);
}
