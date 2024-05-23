#ifndef DIFFEQ_ODE_OSCILLATION_GRAVITATIONAL
#define DIFFEQ_ODE_OSCILLATION_GRAVITATIONAL

#include "ode.h"

class ODE_Oscillation_Gravitational : public ODE {
public:
    ODE_Oscillation_Gravitational();
    ODE_Oscillation_Gravitational(Settings_Common settings_common, Settings_Approx settings_approx);
    ~ODE_Oscillation_Gravitational();

    void calculate();
};

#endif
