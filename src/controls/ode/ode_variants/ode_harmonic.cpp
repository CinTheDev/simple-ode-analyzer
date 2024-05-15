#include "ode_harmonic.h"

ODE_Harmonic::ODE_Harmonic(size_t length) : ODE(length) { }

ODE_Harmonic::~ODE_Harmonic() { }

void ODE_Harmonic::calculate() {
    for (int i = 0; i < result_length; i++) {
        result[i] = result_length / (i + 1);
    }
}
