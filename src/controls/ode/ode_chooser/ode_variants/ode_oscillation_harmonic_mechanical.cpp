#include "ode_oscillation_harmonic_mechanical.h"

Ode_Oscillation_Harmonic_Mechanical::Ode_Oscillation_Harmonic_Mechanical(wxWindow* parent) : OdeFunction(parent, "Harmonic Oscillation - Mechanical") {
    label_D = new wxStaticText(this, wxID_ANY, "D [kg * s^-2]");
    label_m = new wxStaticText(this, wxID_ANY, "m [kg]");

    input_D = new wxTextCtrl(this, wxID_ANY, "100");
    input_m = new wxTextCtrl(this, wxID_ANY, "1");

    add_option(label_D, input_D);
    add_option(label_m, input_m);

    // Edit options
    label_initial_s->SetLabel("s_0 [m]");
    label_initial_v->SetLabel("v_0 [m * s^-1]");
}

Ode_Oscillation_Harmonic_Mechanical::~Ode_Oscillation_Harmonic_Mechanical() { }

double Ode_Oscillation_Harmonic_Mechanical::evaluate_function(double fx) {
    double D = get_D();
    double m = get_m();
    return -(D / m) * fx;
}

double Ode_Oscillation_Harmonic_Mechanical::get_D() {
    return get_input_double(input_D, label_D);
}

double Ode_Oscillation_Harmonic_Mechanical::get_m() {
    return get_input_double(input_m, label_m);
}
