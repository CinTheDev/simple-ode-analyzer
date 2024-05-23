#include "ode_oscillation_gravitational.h"
#include <math.h>

ODE_Oscillation_Gravitational::ODE_Oscillation_Gravitational() : ODE_Oscillation_Gravitational(Settings_Common(), Settings_Approx()) { }

ODE_Oscillation_Gravitational::ODE_Oscillation_Gravitational(Settings_Common settings_common, Settings_Approx settings_approx)
: ODE(settings_common, settings_approx) {
    std::string names[] = {
        "a [m * s^-2]",
    };

    double values[] = {
        80.0,
    };

    size_t count = sizeof(values) / sizeof(double);

    init_variables(count, names, values);
}

ODE_Oscillation_Gravitational::~ODE_Oscillation_Gravitational() { }

void ODE_Oscillation_Gravitational::calculate() {
    double dt = settings_common.step_x / (double)settings_approx.subdivision;

    double a = variable_values[0];

    double current_s = 1.0;
    double current_ds = 0.0;

    for (int i = 0; i < result_length; i++) {
        result[i] = current_s;

        for (int j = 0; j < settings_approx.subdivision; j++) {
            double dds = -a * (abs(current_s) / current_s);
            current_ds += dds * dt;

            current_s += current_ds * dt;
        }
    }
}
