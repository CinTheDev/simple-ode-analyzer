#include "ode_oscillation_harmonic_mechanical.h"
#include <math.h>

ODE_Oscillation_Harmonic_Mechanical::ODE_Oscillation_Harmonic_Mechanical()
: ODE() {

    std::string names[] = {
        "D [kg * s^-2]",
        "m [kg]",
        "s_0 [m]",
        "v_0 [m * s^-1]",
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

OscillationHarmonicVariables ODE_Oscillation_Harmonic_Mechanical::read_variables() {
    OscillationHarmonicVariables variables = OscillationHarmonicVariables();

    variables.omega = sqrt(variable_values[0] / variable_values[1]);
    variables.s_0 = variable_values[2];
    variables.ds_0 = variable_values[3];

    return variables;
}
