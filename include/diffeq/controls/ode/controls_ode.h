#ifndef CONTROLS_ODE
#define CONTROLS_ODE

#include <wx/wx.h>
#include "events.h"
#include "controls.h"
#include "settings.h"
#include "ode.h"

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

    void SendResults();

    Settings_Common construct_common_settings();
    Settings_Approximation construct_approx_settings();
    void update_values(Settings_Common settings_common);
    void update_values(Settings_Approximation settings_approx);

    void on_button_calculate(wxCommandEvent& evt);
    void on_ode_list(OdeListUpdateEvent& evt);

private:
    ODE** odes;
    uint32_t* ode_colors;
    size_t amount_odes;

    bool odes_changed;
    size_t amount_new_odes;
    OdeListValues* new_ode_structure;

    double** get_all_results(size_t& amount_results, size_t& result_length);
    void init_elements();
    void update_ode_settings();
    void regenerate_odes();
    void purge_odes();
};

#endif
