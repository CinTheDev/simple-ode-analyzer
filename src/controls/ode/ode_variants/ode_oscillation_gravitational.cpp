#include "ode_oscillation_gravitational.h"
#include <iostream>
#include <math.h>

enum CALCULATION_SELECTION {
    EULER,
};

std::string calculation_labels[] = {
    "Euler",
};

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

std::string ODE_Oscillation_Gravitational::get_calculate_method_label(size_t index) {
    return calculation_labels[index];
}

const size_t ODE_Oscillation_Gravitational::get_methods_amount() {
    return sizeof(calculation_labels) / sizeof(calculation_labels[0]);
}

void ODE_Oscillation_Gravitational::calculate() {
    switch (selected_calculate) {
    case EULER:
        calculate_euler();
        break;

    default:
        std::cout << "WARNING: Unhandled calculation selection of " << selected_calculate << " in ODE_Oscillation_Gravitational::calculate()" << std::endl;
        break;
    }
}

void ODE_Oscillation_Gravitational::calculate_euler() {
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
