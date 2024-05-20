#ifndef CONTROLS_ODE
#define CONTROLS_ODE

#include <wx/wx.h>
#include "controls.h"
#include "settings.h"
#include "ode.h"

class ControlsODE : public Controls {
public:
    ControlsODE(wxWindow* parent);
    ~ControlsODE();

    wxButton* button_calculate;

    wxTextCtrl* input_step_x;
    wxTextCtrl* input_subdivision;

    wxStaticText* label_step_x;
    wxStaticText* label_subdivision;

    void SendResults();

    Settings_Common construct_common_settings();
    Settings_Approximation construct_approx_settings();
    void update_values(Settings_Common settings_common);
    void update_values(Settings_Approximation settings_approx);

    void on_text_input(wxEvent& evt);

private:
    ODE* ode;

    void init_elements();
    void update_ode();
};

#endif
