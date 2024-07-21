#include "ode_oscillation_gravitational.h"

Ode_Oscillation_Gravitational::Ode_Oscillation_Gravitational(wxWindow* parent) : OdeFunction(parent, "Gravitational Oscillation") {
    label_a = new wxStaticText(this, wxID_ANY, "a [m * s^-2]");
    input_a = new wxTextCtrl(this, wxID_ANY, "80");

    add_option(label_a, input_a);

    // Edit options
    label_initial_s->SetLabel("s_0 [m]");
    label_initial_v->SetLabel("v_0 [m * s^-1]");
}

Ode_Oscillation_Gravitational::~Ode_Oscillation_Gravitational() { }

double Ode_Oscillation_Gravitational::evaluate_function(double fx, double dfx) {
    double a = get_a();
    return -a * (abs(fx) / fx);
}

double Ode_Oscillation_Gravitational::get_a() {
    return get_input_double(input_a, label_a);
}
