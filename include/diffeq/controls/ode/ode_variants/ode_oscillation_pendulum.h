#ifndef ODE_OSCILLATION_PENDULUM
#define ODE_OSCILLATION_PENDULUM

#include <wx/wx.h>
#include "ode_function.h"

class Ode_Oscillation_Pendulum : public OdeFunction {
public:
    Ode_Oscillation_Pendulum(wxWindow* parent);
    ~Ode_Oscillation_Pendulum();

    wxStaticText* label_g;
    wxStaticText* label_l;
    wxStaticText* label_m;
    wxStaticText* label_c;

    wxTextCtrl* input_g;
    wxTextCtrl* input_l;
    wxTextCtrl* input_m;
    wxTextCtrl* input_c;

protected:
    double evaluate_function(double fx, double dfx);

    double get_g();
    double get_l();
    double get_m();
    double get_c();
};

#endif
