#ifndef DIFFEQ_ODE_OSCILLATION_HARMONIC
#define DIFFEQ_ODE_OSCILLATION_HARMONIC

#include <wx/wx.h>
#include "ode_function.h"

class Ode_Oscillation_Harmonic : public OdeFunction {
public:
    Ode_Oscillation_Harmonic(wxWindow* parent);
    ~Ode_Oscillation_Harmonic();

    wxStaticText* label_omega;
    wxStaticText* label_damping;

    wxTextCtrl* input_omega;
    wxTextCtrl* input_damping;

protected:
    double evaluate_function(double fx, double dfx);

    double get_omega();
    double get_damping();
};

#endif
