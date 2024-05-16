#include "ode_harmonic.h"

ODE_Harmonic::ODE_Harmonic(size_t length, Settings_Common settings_common) : ODE(length, settings_common) { }

ODE_Harmonic::~ODE_Harmonic() { }

void ODE_Harmonic::calculate() {
    for (int i = 0; i < result_length; i++) {
        result[i] = (double)i / (double)result_length;
    }
}
