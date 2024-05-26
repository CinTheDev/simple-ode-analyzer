#ifndef DIFFEQ_ODE_OSCILLATION_HARMONIC
#define DIFFEQ_ODE_OSCILLATION_HARMONIC

#include <wx/wx.h>
#include "ode_function.h"

class Ode_Oscillation_Harmonic : public OdeFunction {
public:
    Ode_Oscillation_Harmonic(wxWindow* parent);
    ~Ode_Oscillation_Harmonic();

    wxStaticText* some_label;
    wxTextCtrl* some_option;

protected:
    double evaluate_function(double x);
};

#endif
