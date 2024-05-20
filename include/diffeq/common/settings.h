#ifndef DIFFEQ_SETTINGS
#define DIFFEQ_SETTINGS

struct Settings_Common {
public:
    double step_x = 0.01;
};

struct Settings_Approximation {
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

#endif
