#include "ode_v_oscillation.h"
#include <math.h>

ODE_V_Oscillation::ODE_V_Oscillation(size_t length, Settings_Common settings_common) : ODE(length, settings_common) { }

ODE_V_Oscillation::~ODE_V_Oscillation() { }

void ODE_V_Oscillation::calculate() {
    // TODO: Have subdivision as setting
    int subdivision = 1;

    double dt = settings_common.step_x / (double)subdivision;

    double g = 80.0;
    double angle = 90 * (3.141 / 180.0);

    double current_s = 1.0;
    double current_ds = 0.0;

    for (int i = 0; i < result_length; i++) {
        result[i] = current_s;

        for (int j = 0; j < subdivision; j++) {
            double dds = -g * sin(angle) * (abs(current_s) / current_s);
            current_ds += dds * dt;

            current_s += current_ds * dt;
        }
    }
}
