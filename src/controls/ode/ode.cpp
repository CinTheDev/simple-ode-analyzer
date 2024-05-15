#include "ode.h"
#include <math.h>

ODE::ODE(size_t length) {
    result = new double[length];
    result_length = length;
}

ODE::~ODE() {
    delete[] result;
}

size_t ODE::get_length() {
    return result_length;
}

void ODE::set_length(size_t length) {
    delete[] result;
    result = new double[length];
    result_length = length;
}

void ODE::clear_result() {
    for (int i = 0; i < result_length; i++) {
        result[i] = 0.0;
    }
}

void ODE::calculate() { }

double* test_harmonic(int sample_num, int subdivision, double step) {
    double* func_array = new double[sample_num];

    double dt = step / (double)subdivision;

    double D = 100.0;
    double m = 1.0;

    double current_s = 1.0;
    double current_ds = 0.0;

    for (int i = 0; i < sample_num; i++) {
        func_array[i] = current_s;

        for (int j = 0; j < subdivision; j++) {
            double dds = -(D / m) * current_s;
            current_ds += dds * dt;

            current_s += current_ds * dt;
        }
    }

    return func_array;
}

double* test_function(int sample_num, int subdivision, double step) {
    double* func_array = new double[sample_num];

    double dt = step / (double)subdivision;

    double g = 80.0;
    double angle = 90 * (3.141 / 180.0);

    double current_s = 1.0;
    double current_ds = 0.0;

    for (int i = 0; i < sample_num; i++) {
        func_array[i] = current_s;

        for (int j = 0; j < subdivision; j++) {
            double dds = -g * sin(angle) * (abs(current_s) / current_s);
            current_ds += dds * dt;

            current_s += current_ds * dt;
        }
    }

    return func_array;
}
