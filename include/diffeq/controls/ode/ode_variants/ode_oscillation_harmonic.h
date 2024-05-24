#ifndef DIFFEQ_ODE_OSCILLATION_HARMONIC
#define DIFFEQ_ODE_OSCILLATION_HARMONIC

#include "ode.h"

class ODE_Oscillation_Harmonic : public ODE {
public:
    ODE_Oscillation_Harmonic();
    ODE_Oscillation_Harmonic(Settings_Common settings_common, Settings_Approx settings_approx);
    ~ODE_Oscillation_Harmonic();

    std::string get_calculate_method_label(size_t index);
    const size_t get_methods_amount();

    void calculate();

private:
    void calculate_solved();
    void calculate_euler();
};

#endif
