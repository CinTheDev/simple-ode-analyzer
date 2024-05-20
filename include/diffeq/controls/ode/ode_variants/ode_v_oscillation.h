#ifndef DIFFEQ_ODE_V_OSCILLATION
#define DIFFEQ_ODE_V_OSCILLATION

#include "ode.h"

class ODE_V_Oscillation : public ODE {
public:
    ODE_V_Oscillation(size_t length, Settings_Common settings_common, Settings_Approximation settings_approx);
    ~ODE_V_Oscillation();

    void calculate();
};

#endif
