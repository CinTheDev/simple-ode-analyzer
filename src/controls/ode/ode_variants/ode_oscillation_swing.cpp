#include "ode_oscillation_swing.h"

enum CALCULATION_SELECTION {
    EULER,
};

const std::string calculation_labels[] = {
    "Euler",
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
