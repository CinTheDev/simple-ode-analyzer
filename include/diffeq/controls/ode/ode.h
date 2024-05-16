#ifndef DIFFEQ_ODE
#define DIFFEQ_ODE

#include <cstddef>
#include "settings.h"

class ODE {
public:
    ODE(size_t length, Settings_Common settings_common);
    ~ODE();

    size_t get_length();
    void set_length(size_t length);

    void clear_result();
    double* get_result();

    virtual void calculate();

protected:
    double* result;
    size_t result_length;

    Settings_Common settings_common;

private:
    void create_array(size_t length);
};

double* test_harmonic(int sample_num, int subdivision, double step);
double* test_function(int sample_num, int subdivision, double step);

#endif
