#ifndef ODE_OSCILLATION_SWING
#define ODE_OSCILLATION_SWING

#include "ode.h"

class ODE_Oscillation_Swing : public ODE {
public:
    ODE_Oscillation_Swing();
    ~ODE_Oscillation_Swing();

    std::string get_calculate_method_label(size_t index);
    const size_t get_methods_amount();

    void calculate();

private:
    void calculate_euler();
    void calculate_midpoint();
};

#endif
