#ifndef DIFFEQ_ODE_OSCILLATION_HARMONIC
#define DIFFEQ_ODE_OSCILLATION_HARMONIC

#include "ode.h"

struct OscillationHarmonicVariables {
    double omega;
    double s_0;
    double ds_0;
};

class ODE_Oscillation_Harmonic : virtual public ODE {
public:
    ODE_Oscillation_Harmonic();
    ODE_Oscillation_Harmonic(Settings_Common settings_common, Settings_Approx settings_approx);
    ~ODE_Oscillation_Harmonic();

    std::string get_calculate_method_label(size_t index);
    const size_t get_methods_amount();

    void calculate();

protected:
    virtual OscillationHarmonicVariables read_variables();

private:
    void calculate_solved(OscillationHarmonicVariables variables);
    void calculate_euler(OscillationHarmonicVariables variables);
};

#endif
