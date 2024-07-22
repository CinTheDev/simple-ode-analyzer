#include "ode_oscillation_pendulum.h"

Ode_Oscillation_Pendulum::Ode_Oscillation_Pendulum(wxWindow* parent) : OdeFunction(parent, "Oscillation of a pendulum / swing") {
    label_g = new wxStaticText(this, wxID_ANY, "g [m * s^-2]");
    label_l = new wxStaticText(this, wxID_ANY, "l [m]");
    label_m = new wxStaticText(this, wxID_ANY, "m [kg]");
    label_c = new wxStaticText(this, wxID_ANY, "c [kg * s^-1]");

    input_g = new wxTextCtrl(this, wxID_ANY, "9.81");
    input_l = new wxTextCtrl(this, wxID_ANY, "1");
    input_m = new wxTextCtrl(this, wxID_ANY, "1");
    input_c = new wxTextCtrl(this, wxID_ANY, "0");

    add_option(label_g, input_g);
    add_option(label_l, input_l);
    add_option(label_m, input_m);
    add_option(label_c, input_c);

    // Edit options
    label_initial_s->SetLabel("s_0 [m]");
    label_initial_v->SetLabel("v_0 [m * s^-1]");
}

Ode_Oscillation_Pendulum::~Ode_Oscillation_Pendulum() { }

double Ode_Oscillation_Pendulum::evaluate_function(double fx, double dfx) {
    double g = get_g();
    double l = get_l();

    return -g * sin(fx / l);
}

double Ode_Oscillation_Pendulum::get_g() {
    return get_input_double(input_g, label_g);
}

double Ode_Oscillation_Pendulum::get_l() {
    return get_input_double(input_l, label_l);
}

double Ode_Oscillation_Pendulum::get_m() {
    return get_input_double(input_m, label_m);
}

double Ode_Oscillation_Pendulum::get_c() {
    return get_input_double(input_c, label_c);
}
