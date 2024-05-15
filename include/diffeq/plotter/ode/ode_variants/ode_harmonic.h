#ifndef DIFFEQ_ODE_HARMONIC
#define DIFFEQ_ODE_HARMONIC

#include "ode.h"

class ODE_Harmonic : public ODE {
public:
    ODE_Harmonic(size_t length);
    ~ODE_Harmonic();
};

#endif
