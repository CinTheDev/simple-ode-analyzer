#include "ode_oscillation_harmonic_electomagnetic.h"
#include <math.h>

ODE_Oscillation_Harmonic_Electromagnetic::ODE_Oscillation_Harmonic_Electromagnetic()
: ODE() {

    std::string names[] = {
        "L [H]",
        "C [F]",
        "Q_0 [C]",
        "I_0 [A]",
    };

    double values[] = {
        0.1,
        0.1,
        1.0,
        0.0,
    };

    size_t count = sizeof(values) / sizeof(double);

    init_variables(count, names, values);
}

ODE_Oscillation_Harmonic_Electromagnetic::~ODE_Oscillation_Harmonic_Electromagnetic() { }

OscillationHarmonicVariables ODE_Oscillation_Harmonic_Electromagnetic::read_variables() {
    OscillationHarmonicVariables variables = OscillationHarmonicVariables();

    variables.omega = 1.0 / sqrt(variable_values[0] * variable_values[1]);
    variables.s_0 = variable_values[2];
    variables.v_0 = variable_values[3];

    return variables;
}
