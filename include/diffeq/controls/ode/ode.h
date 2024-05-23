#ifndef DIFFEQ_ODE
#define DIFFEQ_ODE

#include <cstddef>
#include <string>
#include "settings.h"

class ODE {
public:
    ODE();
    ODE(Settings_Common settings_common, Settings_Approx settings_approx);
    ~ODE();

    size_t get_length();
    void set_length(size_t length);

    void clear_result();
    double* get_result();

    double* get_variable_values();
    std::string* get_variable_names();
    size_t get_amount_variables();

    void apply_settings(Settings_Common settings_common);
    void apply_settings(Settings_Approx settings_approx);

    virtual void calculate();

protected:
    void init_variables(size_t n, std::string* names, double* values);

    double* result = nullptr;
    size_t result_length = 0;

    double* variable_values = nullptr;
    std::string* variable_names = nullptr;
    size_t amount_variables = 0;

    Settings_Common settings_common;
    Settings_Approx settings_approx;
};

#endif
