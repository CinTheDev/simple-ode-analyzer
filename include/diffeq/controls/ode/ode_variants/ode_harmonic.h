#ifndef DIFFEQ_ODE_HARMONIC
#define DIFFEQ_ODE_HARMONIC

#include "ode.h"

class ODE_Harmonic : public ODE {
public:
    ODE_Harmonic();
    ODE_Harmonic(Settings_Common settings_common, Settings_Approximation settings_approx);
    ~ODE_Harmonic();

    void calculate();
};

#endif
