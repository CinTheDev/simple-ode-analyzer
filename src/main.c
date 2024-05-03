#include <stdio.h>
#include "plotter.h"

double test_function(double val) {
    return val * 2.0 + 1.0;
}

int main() {
    plot_function(10, 10, 0.5, test_function);

    return 0;
}
