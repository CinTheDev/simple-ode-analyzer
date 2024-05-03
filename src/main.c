#include <stdio.h>
#include <math.h>
#include "plotter.h"

double test_function(double val) {
    return sin(val);
}

int main() {
    plot_function(40, 5, 0.25, 0.25, test_function);

    return 0;
}
