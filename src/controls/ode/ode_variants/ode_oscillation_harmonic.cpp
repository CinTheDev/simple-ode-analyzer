#include "ode_oscillation_harmonic.h"

enum CALCULATION_SELECTION {
    EULER,
    TEST,
};

const std::string calculation_labels[] = {
    "Euler",
    "Test",
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
    calculation_labels[index];
}

void ODE_Oscillation_Harmonic::calculate() {
    switch (selected_calculate)
    {
    case EULER:
        calculate_euler();
        break;
    
    case TEST:
        calculate_test();
        break;

    default:
        std::cout << "WARNING: Unhandled calculation selection of " << selected_calculate << " in ODE_Oscillation_Harmonic::calculate()" << std::endl;
        break;
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

void ODE_Oscillation_Harmonic::calculate_test() {
    for (size_t i = 0; i < result_length; i++) {
        result[i] = (double)i / (double)result_length;
    }
}
