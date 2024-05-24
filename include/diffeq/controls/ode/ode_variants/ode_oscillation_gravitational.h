#ifndef DIFFEQ_ODE_OSCILLATION_GRAVITATIONAL
#define DIFFEQ_ODE_OSCILLATION_GRAVITATIONAL

#include "ode.h"

class ODE_Oscillation_Gravitational : public ODE {
public:
    ODE_Oscillation_Gravitational();
    ODE_Oscillation_Gravitational(Settings_Common settings_common, Settings_Approx settings_approx);
    ~ODE_Oscillation_Gravitational();

    std::string get_calculate_method_label(size_t index);
    const size_t get_methods_amount();

    void calculate();

private:
    void calculate_euler();
};

#endif
