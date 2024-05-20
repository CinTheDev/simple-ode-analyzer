#ifndef DIFFEQ_ODE
#define DIFFEQ_ODE

#include <cstddef>
#include "settings.h"

class ODE {
public:
    ODE(size_t length, Settings_Common settings_common, Settings_Approximation settings_approx);
    ~ODE();

    size_t get_length();
    void set_length(size_t length);

    void clear_result();
    double* get_result();

    void apply_settings(Settings_Common settings_common);
    void apply_settings(Settings_Approximation settings_approx);

    virtual void calculate();

protected:
    double* result;
    size_t result_length;

    Settings_Common settings_common;
    Settings_Approximation settings_approx;

private:
    void create_array(size_t length);
};

#endif
