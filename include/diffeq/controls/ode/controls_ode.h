#ifndef CONTROLS_ODE
#define CONTROLS_ODE

#include <wx/wx.h>
#include "events.h"
#include "controls.h"
#include "settings.h"

class ControlsODE : public Controls {
public:
    ControlsODE(wxWindow* parent);
    ~ControlsODE();

    wxButton* button_calculate;

    wxTextCtrl* input_amount;
    wxTextCtrl* input_step_x;
    wxTextCtrl* input_subdivision;

    wxStaticText* label_amount;
    wxStaticText* label_step_x;
    wxStaticText* label_subdivision;

    Settings_Common construct_common_settings();
    Settings_Approx construct_approx_settings();
    void update_values(Settings_Common settings_common);
    void update_values(Settings_Approx settings_approx);

    void on_text_input(wxEvent& evt);
    void on_settings_request(SettingsOdeRequest& evt);

private:
    void init_elements();
};

#endif
