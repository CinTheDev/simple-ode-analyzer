#ifndef DIFFEQ_ODE_OSCILLATION_HARMONIC
#define DIFFEQ_ODE_OSCILLATION_HARMONIC

#include "ode.h"

class ODE_Oscillation_Harmonic : public ODE {
public:
    ODE_Oscillation_Harmonic();
    ODE_Oscillation_Harmonic(Settings_Common settings_common, Settings_Approx settings_approx);
    ~ODE_Oscillation_Harmonic();

    void calculate();
};

#endif
