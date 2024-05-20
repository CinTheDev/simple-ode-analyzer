#include "ode_harmonic.h"

ODE_Harmonic::ODE_Harmonic(size_t length, Settings_Common settings_common, Settings_Approximation settings_approx)
 : ODE(length, settings_common, settings_approx) { }

ODE_Harmonic::~ODE_Harmonic() { }

void ODE_Harmonic::calculate() {
    double dt = settings_common.step_x / (double)settings_approx.subdivision;

    double D = 100.0;
    double m = 1.0;

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
