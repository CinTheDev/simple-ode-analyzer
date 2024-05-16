#include "ode.h"
#include <math.h>

ODE::ODE(size_t length, Settings_Common settings_common) {
    create_array(length);
    this->settings_common = settings_common;
}

ODE::~ODE() {
    delete[] result;
}

size_t ODE::get_length() {
    return result_length;
}

void ODE::set_length(size_t length) {
    delete[] result;
    create_array(length);
}

void ODE::clear_result() {
    for (int i = 0; i < result_length; i++) {
        result[i] = 0.0;
    }
}

double* ODE::get_result() {
    return result;
}

void ODE::create_array(size_t length) {
    result = new double[length];
    result_length = length;
}

void ODE::calculate() { }
