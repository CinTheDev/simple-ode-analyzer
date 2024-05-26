#ifndef DIFFEQ_ODE_OSCILLATION_HARMONIC
#define DIFFEQ_ODE_OSCILLATION_HARMONIC

#include <wx/wx.h>
#include "ode_entry.h"

class Ode_Oscillation_Harmonic : public OdeEntry {
public:
    Ode_Oscillation_Harmonic(wxWindow* parent);
    ~Ode_Oscillation_Harmonic();

    wxStaticText* some_label;
    wxTextCtrl* some_option;

protected:
    void calculate();
};

#endif
