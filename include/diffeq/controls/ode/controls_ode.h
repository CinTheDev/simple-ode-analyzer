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
    Settings_Approximation construct_approx_settings();
    void update_values(Settings_Common settings_common);
    void update_values(Settings_Approximation settings_approx);

    //void on_button_calculate(wxCommandEvent& evt);
    //void on_ode_list(OdeListUpdateEvent& evt);

private:
    // TODO: Move ODES to controls_choose
    void init_elements();
};

#endif
