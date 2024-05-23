#include "ode.h"
#include <math.h>

ODE::ODE() : ODE(Settings_Common(), Settings_Approximation()) { }

ODE::ODE(Settings_Common settings_common, Settings_Approximation settings_approx) {
    result = new double[1];

    apply_settings(settings_common);
    apply_settings(settings_approx);
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

double* ODE::get_result() {
    return result;
}

double* ODE::get_variable_values() {
    return variable_values;
}

std::string* ODE::get_variable_names() {
    return variable_names;
}

size_t ODE::get_amount_variables() {
    return amount_variables;
}

void ODE::apply_settings(Settings_Common settings_common) {
    this->settings_common = settings_common;
}

void ODE::apply_settings(Settings_Approximation settings_approx) {
    this->settings_approx = settings_approx;

    set_length(settings_approx.amount);
}

void ODE::calculate() { }
