#ifndef ODE_OSCILLATION_HARMONIC_MECHANICAL
#define ODE_OSCILLATION_HARMONIC_MECHANICAL

#include <wx/wx.h>
#include "ode_function.h"

class Ode_Oscillation_Harmonic_Mechanical : public OdeFunction {
public:
    Ode_Oscillation_Harmonic_Mechanical(wxWindow* parent);
    ~Ode_Oscillation_Harmonic_Mechanical();

    wxStaticText* label_D;
    wxStaticText* label_m;

    wxTextCtrl* input_D;
    wxTextCtrl* input_m;

protected:
    double evaluate_function(double fx, double dfx);

    double get_D();
    double get_m();
};

#endif
