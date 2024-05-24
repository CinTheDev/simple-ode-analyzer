#include "ode_oscillation_harmonic.h"
#include <iostream>
#include <math.h>

enum CALCULATION_SELECTION {
    SOLVED,
    EULER,
};

const std::string calculation_labels[] = {
    "Solved",
    "Euler",
};

ODE_Oscillation_Harmonic::ODE_Oscillation_Harmonic() : ODE_Oscillation_Harmonic(Settings_Common(), Settings_Approx()) { }

ODE_Oscillation_Harmonic::ODE_Oscillation_Harmonic(Settings_Common settings_common, Settings_Approx settings_approx)
: ODE(settings_common, settings_approx) {

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

ODE_Oscillation_Harmonic::~ODE_Oscillation_Harmonic() { }

std::string ODE_Oscillation_Harmonic::get_calculate_method_label(size_t index) {
    return calculation_labels[index];
}

const size_t ODE_Oscillation_Harmonic::get_methods_amount() {
    return sizeof(calculation_labels) / sizeof(calculation_labels[0]);
}

void ODE_Oscillation_Harmonic::calculate() {
    switch (selected_calculate)
    {
    case SOLVED:
        calculate_solved();
        break;

    case EULER:
        calculate_euler();
        break;

    default:
        std::cout << "WARNING: Unhandled calculation selection of " << selected_calculate << " in ODE_Oscillation_Harmonic::calculate()" << std::endl;
        break;
    }
}

void ODE_Oscillation_Harmonic::calculate_solved() {
    double D = variable_values[0];
    double m = variable_values[1];

    double s_0 = variable_values[2];
    // TODO: Do not neglect v_0 in calculation
    double v_0 = variable_values[3];

    double omega = sqrt(D / m);

    for (size_t i = 0; i < result_length; i++) {
        double t = i * settings_common.step_x;
        result[i] = s_0 * cos(omega * t);
    }
}

void ODE_Oscillation_Harmonic::calculate_euler() {
    double dt = settings_common.step_x / (double)settings_approx.subdivision;

    double D = variable_values[0];
    double m = variable_values[1];

    double current_s = variable_values[2];
    double current_ds = variable_values[3];

    for (size_t i = 0; i < result_length; i++) {
        result[i] = current_s;

        for (size_t j = 0; j < settings_approx.subdivision; j++) {
            double dds = (-D / m) * current_s;
            current_ds += dds * dt;

            current_s += current_ds * dt;
        }
    }
}
