#include "ode_oscillation_harmonic_electromagnetic.h"
#include <math.h>

Ode_Oscillation_Harmonic_Electromagnetic::Ode_Oscillation_Harmonic_Electromagnetic(wxWindow* parent) : OdeFunction(parent, "Harmonic Oscillation") {
    label_L = new wxStaticText(this, wxID_ANY, "L [H]");
    label_C = new wxStaticText(this, wxID_ANY, "C [C]");

    input_L = new wxTextCtrl(this, wxID_ANY, "0.1");
    input_C = new wxTextCtrl(this, wxID_ANY, "0.1");

    add_option(label_L, input_L);
    add_option(label_C, input_C);

    // Edit options
    label_initial_s->SetLabel("Q_0 [C]");
    label_initial_v->SetLabel("I_0 [A]");
}

Ode_Oscillation_Harmonic_Electromagnetic::~Ode_Oscillation_Harmonic_Electromagnetic() { }

double Ode_Oscillation_Harmonic_Electromagnetic::evaluate_function(double fx) {
    double L = get_L();
    double C = get_C();
    return -1.0 / (L * C) * fx;
}

double Ode_Oscillation_Harmonic_Electromagnetic::get_L() {
    return get_input_double(input_L, label_L);
}

double Ode_Oscillation_Harmonic_Electromagnetic::get_C() {
    return get_input_double(input_C, label_C);
}
