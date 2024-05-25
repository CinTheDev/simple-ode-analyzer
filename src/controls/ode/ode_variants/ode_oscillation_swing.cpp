#include "ode_oscillation_swing.h"
#include <iostream>
#include <math.h>

enum CALCULATION_SELECTION {
    EULER,
    MIDPOINT,
};

const std::string calculation_labels[] = {
    "Euler",
    "Midpoint",
};

ODE_Oscillation_Swing::ODE_Oscillation_Swing() : ODE() {
    std::string names[] = {
        "g [m * s^-2]",
        "l [m]",
        "s_0 [m]",
        "v_0 [m * s^-1]",
    };

    double values[] = {
        9.81,
        10.0,
        1.0,
        0.0,
    };

    size_t count = sizeof(values) / sizeof(double);

    init_variables(count, names, values);
}

ODE_Oscillation_Swing::~ODE_Oscillation_Swing() { }

std::string ODE_Oscillation_Swing::get_calculate_method_label(size_t index) {
    return calculation_labels[index];
}

const size_t ODE_Oscillation_Swing::get_methods_amount() {
    return sizeof(calculation_labels) / sizeof(calculation_labels[0]);
}

void ODE_Oscillation_Swing::calculate() {
    switch (selected_calculate) {
    case EULER:
        calculate_euler();
        break;

    case MIDPOINT:
        calculate_midpoint();
        break;

    default:
        std::cout << "WARNING: Unhandled calculation selection of " << selected_calculate << " in ODE_Oscillation_Swing::calculate()" << std::endl;
        break;
    }
}

void ODE_Oscillation_Swing::calculate_euler() {
    double dt = settings_common.step_x / (double) settings_approx.subdivision;

    double g = variable_values[0];
    double l = variable_values[1];

    double current_s = variable_values[2];
    double current_ds = variable_values[3];

    for (size_t i = 0; i < result_length; i++) {
        result[i] = current_s;

        for (size_t j = 0; j < settings_approx.subdivision; j++) {
            double dds = -g * sin(current_s / l);

            current_ds += dds * dt;
            current_s += current_ds * dt;
        }
    }
}

void ODE_Oscillation_Swing::calculate_midpoint() {
    double dt = settings_common.step_x / (double) settings_approx.subdivision;

    double g = variable_values[0];
    double l = variable_values[1];

    double current_s = variable_values[2];
    double current_ds = variable_values[3];

    for (size_t i = 0; i < result_length; i++) {
        result[i] = current_s;

        for (size_t j = 0; j < settings_approx.subdivision; j++) {
            double dds_1 = -g * sin(current_s / l);

            double ds_1 = current_ds;
            double ds_2 = current_ds + dt * 0.5 * dds_1;

            double dds_2 = -g * sin((current_s + dt * 0.5 * ds_2) / l);

            current_ds += dds_2 * dt;
            current_s += ds_2 * dt;
        }
    }
}
