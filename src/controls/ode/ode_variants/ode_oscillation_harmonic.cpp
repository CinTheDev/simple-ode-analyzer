#include "ode_oscillation_harmonic.h"

ODE_Oscillation_Harmonic::ODE_Oscillation_Harmonic() : ODE_Oscillation_Harmonic(Settings_Common(), Settings_Approx()) { }

ODE_Oscillation_Harmonic::ODE_Oscillation_Harmonic(Settings_Common settings_common, Settings_Approx settings_approx)
: ODE(settings_common, settings_approx) {
    amount_variables = 2;
    variable_values = new double[amount_variables];
    variable_names = new std::string[amount_variables];

    variable_names[0] = "D [kg * s^-2]";
    variable_names[1] = "m [kg]";

    variable_values[0] = 100.0;
    variable_values[1] = 1.0;
}

ODE_Oscillation_Harmonic::~ODE_Oscillation_Harmonic() {
    delete[] variable_values;
    delete[] variable_names;
}

void ODE_Oscillation_Harmonic::calculate() {
    double dt = settings_common.step_x / (double)settings_approx.subdivision;

    double D = variable_values[0];
    double m = variable_values[1];

    double current_s = 1.0;
    double current_ds = 0.0;

    for (int i = 0; i < result_length; i++) {
        result[i] = current_s;

        for (int j = 0; j < settings_approx.subdivision; j++) {
            double dds = (-D / m) * current_s;
            current_ds += dds * dt;

            current_s += current_ds * dt;
        }
    }
}
