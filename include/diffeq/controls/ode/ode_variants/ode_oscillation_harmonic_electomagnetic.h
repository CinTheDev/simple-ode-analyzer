#ifndef ODE_OSCILLATION_HARMONIC_ELECTROMAGNETIC
#define ODE_OSCILLATION_HARMONIC_ELECTROMAGNETIC

#include "ode_oscillation_harmonic.h"

class ODE_Oscillation_Harmonic_Electromagnetic : public ODE_Oscillation_Harmonic {
public:
    ODE_Oscillation_Harmonic_Electromagnetic();
    ~ODE_Oscillation_Harmonic_Electromagnetic();

protected:
    OscillationHarmonicVariables read_variables();
};

#endif
