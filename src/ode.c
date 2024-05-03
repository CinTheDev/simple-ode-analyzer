#include "ode.h"
#include <stdlib.h>
#include <stdio.h>

double* get_function_array(int width, double step, unsigned int subdivision) {
    double* func_array = malloc(sizeof(double) * width);

    double current_s = 1.0;
    double current_ds = 0.0;

    double dt = step / (double)subdivision;

    double D = 1.0;
    double m = 5.0;

    // Plot
    for (int i = 0; i < width; i++) {
        func_array[i] = current_s;

        // Iterate function
        for (int j = 0; j < subdivision; j++) {
            double dds = -(D / m) * current_s;
            current_ds += dds * dt;

            current_s += current_ds * dt;
        }
    }

    return func_array;
}
