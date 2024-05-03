#include "plotter.h"
#include <stdio.h>

void plot_function(uint16_t width, uint16_t height, uint16_t step, double (*function)(double)) {
    double test = function(0.0);
    printf("Test value: %lf\n", test);
}
