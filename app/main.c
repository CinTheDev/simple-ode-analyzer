#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "plotter.h"
#include "ode.h"

double* test_function() {
    double* func_values = malloc(sizeof(double) * 80);

    for (int x = 0; x < 80; x++) {
        func_values[x] = sin(x * 0.25);
    }

    return func_values;
}

int main() {
    double* func_values = get_function_array(140, 0.5, 10);
    plot_function(140, 5, 0.5, 0.25, func_values);
    free(func_values);

    return 0;
}
