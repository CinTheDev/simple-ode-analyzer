#ifndef DIFFEQ_SETTINGS
#define DIFFEQ_SETTINGS

struct Settings_Plotter {
public:
    int axis_offset = 50;

    double step_x = 0.01;
    
    double view_x = 1.0;
    double view_y = 1.0;

    double view_start_x = 0.0;
};

#endif
