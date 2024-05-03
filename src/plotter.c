#include "plotter.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool compare_doubles(double a, double b, double epsilon) {
    double val = abs(a - b);
    return val < epsilon;
}

void plot_function(uint16_t width, uint16_t height, double step, double (*function)(double)) {
    uint16_t x_axis_index = height + 1;
    uint16_t y_axis_index = 0;

    for (uint16_t y = 0; y < height * 2 + 1; y++) {
        for (uint16_t x = 0; x < width * 2 + 1; x++) {

            double coord_x = x * step;
            double coord_y = (y - height - 1) * -step;

            double epsilon = step;

            double func_val = function(coord_x);
            if (compare_doubles(func_val, coord_y, epsilon)) {
                printf("*");
            } 
            else if (x == y_axis_index) {
                printf("|");
            }
            else if (y == x_axis_index) {
                printf("-");
            }
            else {
                printf(" ");
            }
        }

        printf("\n");
    }
}
