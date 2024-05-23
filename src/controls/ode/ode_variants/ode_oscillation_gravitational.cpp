#include "ode_oscillation_gravitational.h"
#include <math.h>

ODE_V_Oscillation::ODE_V_Oscillation() : ODE_V_Oscillation(Settings_Common(), Settings_Approx()) { }

ODE_V_Oscillation::ODE_V_Oscillation(Settings_Common settings_common, Settings_Approx settings_approx)
 : ODE(settings_common, settings_approx) { }

ODE_V_Oscillation::~ODE_V_Oscillation() { }

void ODE_V_Oscillation::calculate() {
    double dt = settings_common.step_x / (double)settings_approx.subdivision;

    double g = 80.0;
    double angle = 90 * (3.141 / 180.0);

    double current_s = 1.0;
    double current_ds = 0.0;

    for (int i = 0; i < result_length; i++) {
        result[i] = current_s;

        for (int j = 0; j < settings_approx.subdivision; j++) {
            double dds = -g * sin(angle) * (abs(current_s) / current_s);
            current_ds += dds * dt;

            current_s += current_ds * dt;
        }
    }
}
