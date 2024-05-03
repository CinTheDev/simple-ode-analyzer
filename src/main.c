#include <stdio.h>
#include "plotter.h"

double test_function(double val) {
    return val * 0.5;
}

int main() {
    plot_function(40, 5, 0.25, 1.0, test_function);

    return 0;
}
