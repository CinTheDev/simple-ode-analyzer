#include <stdio.h>
#include <math.h>
#include "plotter.h"

double test_function(double val) {
    return sin(val);
}

int main() {
    plot_function(80, 5, 0.25, 0.2, test_function);

    return 0;
}
