#include "ode_oscillation_gravitational.h"
#include <math.h>

ODE_Oscillation_Gravitational::ODE_Oscillation_Gravitational() : ODE_Oscillation_Gravitational(Settings_Common(), Settings_Approx()) { }

ODE_Oscillation_Gravitational::ODE_Oscillation_Gravitational(Settings_Common settings_common, Settings_Approx settings_approx)
: ODE(settings_common, settings_approx) {

    std::string names[] = {
        "a [m * s^-2]",
        "s_0 [m]",
        "v_0 [m * s^-1]",
    };

    double values[] = {
        80.0,
        1.0,
        0.0,
    };

    size_t count = sizeof(values) / sizeof(double);

    init_variables(count, names, values);
}

ODE_Oscillation_Gravitational::~ODE_Oscillation_Gravitational() { }

void ODE_Oscillation_Gravitational::calculate() {
    double dt = settings_common.step_x / (double)settings_approx.subdivision;

    double a = variable_values[0];

    double current_s = variable_values[1];
    double current_ds = variable_values[2];

    for (size_t i = 0; i < result_length; i++) {
        result[i] = current_s;

        for (size_t j = 0; j < settings_approx.subdivision; j++) {
            double dds = -a * (abs(current_s) / current_s);
            current_ds += dds * dt;

            current_s += current_ds * dt;
        }
    }
}
