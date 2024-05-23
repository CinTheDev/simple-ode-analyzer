#ifndef DIFFEQ_ODE_V_OSCILLATION
#define DIFFEQ_ODE_V_OSCILLATION

#include "ode.h"

class ODE_V_Oscillation : public ODE {
public:
    ODE_V_Oscillation();
    ODE_V_Oscillation(Settings_Common settings_common, Settings_Approximation settings_approx);
    ~ODE_V_Oscillation();

    void calculate();
};

#endif
