#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "plotter.h"

double* test_function() {
    double* func_values = malloc(sizeof(double) * 80);

    for (int x = 0; x < 80; x++) {
        func_values[x] = sin(x * 0.25);
    }

    return func_values;
}

int main() {
    double* func_values = test_function();
    plot_function(80, 5, 0.25, 0.2, func_values);
    free(func_values);

    return 0;
}
