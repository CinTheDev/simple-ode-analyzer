#include "ode.h"
#include <stdlib.h>

double* get_function_array(int width, double step, unsigned int subdivision) {
    double* func_array = malloc(sizeof(double) * width);

    double current_s = 0.0;
    double last_s = 0.0;
    double last_ds = 0.0;
    double last_dds = 0.0;

    double dt = step / (double)subdivision;

    double D = 1.0;
    double m = 1.0;

    // Plot
    for (int i = 0; i < width; i++) {
        func_array[i] = current_s;

        // Iterate function
        for (int j = 0; j < subdivision; j++) {
            double delta_s = current_s - last_s;

            double ds = delta_s / dt;
            double delta_ds = ds - last_ds;

            double dds = delta_ds / dt;

            double s = -D / m * dds;

            last_dds = dds;
            last_ds = ds;

            last_s = current_s;
            current_s = s;
        }
    }

    return func_array;
}
