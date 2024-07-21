#ifndef ODE_OSCILLATION_GRAVITATIONAL
#define ODE_OSCILLATION_GRAVITATIONAL

#include <wx/wx.h>
#include "ode_function.h"

class Ode_Oscillation_Gravitational : public OdeFunction {
public:
    Ode_Oscillation_Gravitational(wxWindow* parent);
    ~Ode_Oscillation_Gravitational();

    wxStaticText* label_a;

    wxTextCtrl* input_a;

protected:
    double evaluate_function(double fx, double dfx);

    double get_a();
};

#endif
