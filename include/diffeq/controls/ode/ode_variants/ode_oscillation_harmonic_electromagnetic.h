#ifndef ODE_OSCILLATION_HARMONIC_ELECTROMAGNETIC
#define ODE_OSCILLATION_HARMONIC_ELECTROMAGNETIC

#include <wx/wx.h>
#include "ode_function.h"

class Ode_Oscillation_Harmonic_Electromagnetic : public OdeFunction {
public:
    Ode_Oscillation_Harmonic_Electromagnetic(wxWindow* parent);
    ~Ode_Oscillation_Harmonic_Electromagnetic();

    wxStaticText* label_L;
    wxStaticText* label_C;

    wxTextCtrl* input_L;
    wxTextCtrl* input_C;

protected:
    double evaluate_function(double fx, double dfx);

    double get_L();
    double get_C();
};

#endif
