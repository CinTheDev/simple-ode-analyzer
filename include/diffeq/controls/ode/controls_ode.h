#ifndef CONTROLS_ODE
#define CONTROLS_ODE

#include <wx/wx.h>
#include "ode.h"

class ControlsODE : public wxPanel {
public:
    ControlsODE(wxWindow* parent);
    ~ControlsODE();

    wxButton* test_button;
    wxBoxSizer* sizer_main;

private:
    ODE ode = ODE(1);
};

#endif
