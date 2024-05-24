#include "ode_oscillation_harmonic_mechanical.h"

ODE_Oscillation_Harmonic_Mechanical::ODE_Oscillation_Harmonic_Mechanical()
: ODE(Settings_Common(), Settings_Approx()) {

    std::string names[] = {
        "D",
        "m",
        "s_0",
        "v_0",
    };

    double values[] = {
        100.0,
        1.0,
        1.0,
        0.0,
    };

    size_t count = sizeof(values) / sizeof(double);

    init_variables(count, names, values);
}

ODE_Oscillation_Harmonic_Mechanical::~ODE_Oscillation_Harmonic_Mechanical() { }
