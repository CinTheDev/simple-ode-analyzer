#ifndef DIFFEQ_ODE
#define DIFFEQ_ODE

#include <cstddef>
#include "settings.h"

class ODE {
public:
    ODE(Settings_Common settings_common, Settings_Approximation settings_approx);
    ~ODE();

    size_t get_length();
    void set_length(size_t length);

    void clear_result();
    double* get_result();

    double* get_variable_values();
    std::string get_variable_names();
    size_t get_amount_variables();

    void apply_settings(Settings_Common settings_common);
    void apply_settings(Settings_Approximation settings_approx);

    virtual void calculate();

protected:
    double* result;
    size_t result_length;

    double* variable_values;
    std::string* variable_names;
    size_t amount_variables;

    Settings_Common settings_common;
    Settings_Approximation settings_approx;
};

#endif
