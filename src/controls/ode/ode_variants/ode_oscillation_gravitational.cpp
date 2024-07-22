#include "ode_oscillation_gravitational.h"

Ode_Oscillation_Gravitational::Ode_Oscillation_Gravitational(wxWindow* parent) : OdeFunction(parent, "Gravitational Oscillation") {
    label_a = new wxStaticText(this, wxID_ANY, "a [m * s^-2]");
    label_m = new wxStaticText(this, wxID_ANY, "m [kg]");
    label_c = new wxStaticText(this, wxID_ANY, "c [kg * s^-1]");

    input_a = new wxTextCtrl(this, wxID_ANY, "10");
    input_m = new wxTextCtrl(this, wxID_ANY, "1");
    input_c = new wxTextCtrl(this, wxID_ANY, "0");

    add_option(label_a, input_a);
    add_option(label_m, input_m);
    add_option(label_c, input_c);

    // Edit options
    label_initial_s->SetLabel("s_0 [m]");
    label_initial_v->SetLabel("v_0 [m * s^-1]");
}

Ode_Oscillation_Gravitational::~Ode_Oscillation_Gravitational() { }

double Ode_Oscillation_Gravitational::evaluate_function(double fx, double dfx) {
    double a = get_a();
    double m = get_m();
    double c = get_c();

    return -a * (abs(fx) / fx) - (c / m) * dfx;
}

double Ode_Oscillation_Gravitational::get_a() {
    return get_input_double(input_a, label_a);
}

double Ode_Oscillation_Gravitational::get_m() {
    return get_input_double(input_m, label_m);
}

double Ode_Oscillation_Gravitational::get_c() {
    return get_input_double(input_c, label_c);
}
