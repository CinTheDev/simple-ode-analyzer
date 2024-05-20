#ifndef CONTROLS_ODE
#define CONTROLS_ODE

#include <wx/wx.h>
#include "controls.h"
#include "ode.h"
#include "settings.h"

class ControlsODE : public Controls {
public:
    ControlsODE(wxWindow* parent);
    ~ControlsODE();

    wxTextCtrl* input_step_x;
    wxTextCtrl* input_subdivision;

    wxStaticText* label_step_x;
    wxStaticText* label_subdivision;

    void SendResults();

    Settings_Common construct_common_settings();

private:
    ODE* ode;

    void init_elements();
    void init_sizers();
};

#endif
