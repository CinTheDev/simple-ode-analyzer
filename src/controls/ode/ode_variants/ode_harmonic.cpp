#include "ode_harmonic.h"

ODE_Harmonic::ODE_Harmonic(size_t length, Settings_Common settings_common) : ODE(length, settings_common) { }

ODE_Harmonic::~ODE_Harmonic() { }

void ODE_Harmonic::calculate() {
    // TODO: Have subdivision as setting
    int subdivision = 1;

    double dt = settings_common.step_x / (double)subdivision;

    double D = 100.0;
    double m = 1.0;

    double current_s = 1.0;
    double current_ds = 0.0;

    for (int i = 0; i < result_length; i++) {
        result[i] = current_s;

        for (int j = 0; j < subdivision; j++) {
            double dds = (-D / m) * current_s;
            current_ds += dds * dt;

            current_s += current_ds * dt;
        }
    }
}
