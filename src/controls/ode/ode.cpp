#include "ode.h"
#include <math.h>

ODE::ODE() : ODE(Settings_Common(), Settings_Approx()) { }

ODE::ODE(Settings_Common settings_common, Settings_Approx settings_approx) {
    result = new double[1];

    apply_settings(settings_common);
    apply_settings(settings_approx);

    variable_names = new std::string[1];
    variable_values = new double[1];
}

ODE::~ODE() {
    delete[] result;
    delete[] variable_names;
    delete[] variable_values;
}

void ODE::init_variables(size_t n, std::string* names, double* values) {
    delete[] variable_names;
    delete[] variable_values;

    amount_variables = n;

    variable_names = new std::string[amount_variables];
    variable_values = new double[amount_variables];

    for (size_t i = 0; i < amount_variables; i++) {
        variable_names[i] = names[i];
        variable_values[i] = values[i];
    }
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
    for (size_t i = 0; i < result_length; i++) {
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

void ODE::set_selected_calculate(size_t index) {
    selected_calculate = index;
}

void ODE::apply_settings(Settings_Common settings_common) {
    this->settings_common = settings_common;
}

void ODE::apply_settings(Settings_Approx settings_approx) {
    this->settings_approx = settings_approx;

    set_length(settings_approx.amount);
}

void ODE::calculate() { }
