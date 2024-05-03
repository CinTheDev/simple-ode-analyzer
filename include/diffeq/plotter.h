#ifndef DIFFEQ_PLOTTER
#define DIFFEQ_PLOTTER

#include <stdint.h>

void plot_function(uint16_t width, uint16_t height, double step, double (*function)(double));

#endif
