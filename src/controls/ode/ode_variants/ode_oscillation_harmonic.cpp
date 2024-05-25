#include "ode_oscillation_harmonic.h"
#include <iostream>
#include <math.h>

enum CALCULATION_SELECTION {
    SOLVED,
    EULER,
    MIDPOINT,
};

const std::string calculation_labels[] = {
    "Solved",
    "Euler",
    "Midpoint",
};

ODE_Oscillation_Harmonic::ODE_Oscillation_Harmonic() : ODE_Oscillation_Harmonic(Settings_Common(), Settings_Approx()) { }

ODE_Oscillation_Harmonic::ODE_Oscillation_Harmonic(Settings_Common settings_common, Settings_Approx settings_approx)
: ODE(settings_common, settings_approx) {

    std::string names[] = {
        "w [s^-1]",
        "s_0 [m]",
        "ds_0 [m * s^-1]",
    };

    double values[] = {
        10.0,
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
    OscillationHarmonicVariables variables = read_variables();

    switch (selected_calculate)
    {
    case SOLVED:
        calculate_solved(variables);
        break;

    case EULER:
        calculate_euler(variables);
        break;

    case MIDPOINT:
        calculate_midpoint(variables);
        break;

    default:
        std::cout << "WARNING: Unhandled calculation selection of " << selected_calculate << " in ODE_Oscillation_Harmonic::calculate()" << std::endl;
        break;
    }
}

OscillationHarmonicVariables ODE_Oscillation_Harmonic::read_variables() {
    OscillationHarmonicVariables variables = OscillationHarmonicVariables();

    variables.omega = variable_values[0];
    variables.s_0 = variable_values[1];
    variables.ds_0 = variable_values[2];

    return variables;
}

void ODE_Oscillation_Harmonic::calculate_solved(OscillationHarmonicVariables variables) {
    double phi_not = atan(-variables.ds_0 / (variables.s_0 * variables.omega));
    double s_max = variables.s_0 / cos(phi_not);

    for (size_t i = 0; i < result_length; i++) {
        double t = i * settings_common.step_x;
        result[i] = s_max * cos(variables.omega * t + phi_not);
    }
}

void ODE_Oscillation_Harmonic::calculate_euler(OscillationHarmonicVariables variables) {
    double dt = settings_common.step_x / (double)settings_approx.subdivision;

    double current_s = variables.s_0;
    double current_ds = variables.ds_0;

    for (size_t i = 0; i < result_length; i++) {
        result[i] = current_s;

        for (size_t j = 0; j < settings_approx.subdivision; j++) {
            double dds = -variables.omega * variables.omega * current_s;
            current_ds += dds * dt;

            double ds = current_ds;
            current_s += ds * dt;
        }
    }
}

void ODE_Oscillation_Harmonic::calculate_midpoint(OscillationHarmonicVariables variables) {
    double dt = settings_common.step_x / (double)settings_approx.subdivision;

    double current_s = variables.s_0;
    double current_ds = variables.ds_0;

    for (size_t i = 0; i < result_length; i++) {
        result[i] = current_s;

        for (size_t j = 0; j < settings_approx.subdivision; j++) {
            double dds_1 = -variables.omega * variables.omega * current_s;

            double ds_1 = current_ds;
            double ds_2 = (current_ds + dt * 0.5 * dds_1);

            double dds_2 = -variables.omega * variables.omega * (current_s + dt * 0.5 * ds_2);

            current_ds += dds_2 * dt;
            current_s += ds_2 * dt;
        }
    }
}
