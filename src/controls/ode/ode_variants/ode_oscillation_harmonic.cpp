#include "ode_oscillation_harmonic.h"

ODE_Oscillation_Harmonic::ODE_Oscillation_Harmonic() : ODE_Oscillation_Harmonic(Settings_Common(), Settings_Approx()) { }

ODE_Oscillation_Harmonic::ODE_Oscillation_Harmonic(Settings_Common settings_common, Settings_Approx settings_approx)
: ODE(settings_common, settings_approx) {
    amount_variables = 4;
    variable_values = new double[amount_variables];
    variable_names = new std::string[amount_variables];

    variable_names[0] = "D [kg * s^-2]";
    variable_names[1] = "m [kg]";
    variable_names[2] = "s_0 [m]";
    variable_names[3] = "d/dt s_0 [m * s^-1]";

    variable_values[0] = 100.0;
    variable_values[1] = 1.0;
    variable_values[2] = 1.0;
    variable_values[3] = 0.0;
}

ODE_Oscillation_Harmonic::~ODE_Oscillation_Harmonic() {
    delete[] variable_values;
    delete[] variable_names;
}

void ODE_Oscillation_Harmonic::calculate() {
    double dt = settings_common.step_x / (double)settings_approx.subdivision;

    double D = variable_values[0];
    double m = variable_values[1];

    double current_s = variable_values[2];
    double current_ds = variable_values[3];

    for (int i = 0; i < result_length; i++) {
        result[i] = current_s;

        for (int j = 0; j < settings_approx.subdivision; j++) {
            double dds = (-D / m) * current_s;
            current_ds += dds * dt;

            current_s += current_ds * dt;
        }
    }
}
