#include "ode.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double* get_function_array(int width, double step, unsigned int subdivision) {
    double* func_array = malloc(sizeof(double) * width);

    double current_s = 1.0;
    double current_ds = 0.0;

    double dt = step / (double)subdivision;

    double g = 9.81;
    double angle = 30 * (3.141 / 180);

    // Plot
    for (int i = 0; i < width; i++) {
        func_array[i] = current_s;

        // Iterate function
        for (int j = 0; j < subdivision; j++) {
            double dds = -g * sin(angle) * (abs(current_s) / current_s);
            current_ds += dds * dt;

            current_s += current_ds * dt;
        }
    }

    return func_array;
}
