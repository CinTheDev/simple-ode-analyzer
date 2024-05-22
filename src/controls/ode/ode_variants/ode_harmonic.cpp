#include "ode_harmonic.h"

ODE_Harmonic::ODE_Harmonic(Settings_Common settings_common, Settings_Approximation settings_approx)
: ODE(settings_common, settings_approx) {
    amount_variables = 2;
    variable_values = new double[amount_variables];
    variable_names = new std::string[amount_variables];

    variable_names[0] = "D";
    variable_names[1] = "m";

    variable_values[0] = 100.0;
    variable_values[1] = 1.0;
}

ODE_Harmonic::~ODE_Harmonic() {
    delete[] variable_values;
    delete[] variable_names;
}

void ODE_Harmonic::calculate() {
    double dt = settings_common.step_x / (double)settings_approx.subdivision;

    //double D = 100.0;
    //double m = 1.0;
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
