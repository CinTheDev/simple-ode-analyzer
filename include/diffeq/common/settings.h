#ifndef DIFFEQ_SETTINGS
#define DIFFEQ_SETTINGS

#include <cstdint>

struct Settings_Common {
public:
    double step_x = 0.01;
};

struct Settings_Approx {
public:
    int amount = 100;
    int subdivision = 1;
};

struct Settings_Plotter {
public:
    int axis_offset = 50;

    double view_x_exp = 0.0;
    double view_y_exp = 0.0;
    
    double view_x = 1.0;
    double view_y = 1.0;

    double view_start_x = 0.0;
};

enum class OdeTypes {
    HarmonicOscillationGeneric,
    HarmonicOscillationMechanical,
    HarmonicOscillationElectromagnetic,
    OscillationSwing,
    OscillationGravitational,
};

struct OdePointer {
public:
    double** results_x;
    double** results_y;
    size_t* results_length;
    uint32_t* colours;
    size_t amount_results;
};

#endif
