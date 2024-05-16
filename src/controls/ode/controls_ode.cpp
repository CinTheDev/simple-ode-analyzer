#include "controls_ode.h"
#include "ode_harmonic.h"
#include "events.h"

ControlsODE::ControlsODE(wxWindow* parent) : wxPanel(parent) {
    sizer_main = new wxBoxSizer(wxVERTICAL);

    test_button = new wxButton(this, 12000, "Controls ODE");
    sizer_main->Add(test_button, 1, wxEXPAND);

    SetSizer(sizer_main);

    ode = new ODE_Harmonic(10);
    ode->calculate();

    SendResults();

    Bind(wxEVT_BUTTON, &ControlsODE::on_test_button, this);
}

ControlsODE::~ControlsODE() {
    delete ode;
}

void ControlsODE::SendResults() {
    // ODE pointer
    OdePointerEvent evt_ode_pointer(EVT_ODE_POINTER, GetId(), ode->get_result(), ode->get_length());
    evt_ode_pointer.SetEventObject(this);
    evt_ode_pointer.ResumePropagation(__INT_MAX__);
    ProcessEvent(evt_ode_pointer);

    // Step x
    Settings_Common settings_common;
    construct_common_settings(&settings_common);

    SettingsCommonEvent evt_settings_common(SETTINGS_COMMON_UPDATE, GetId(), settings_common);
    evt_settings_common.SetEventObject(this);
    evt_settings_common.ResumePropagation(__INT_MAX__);
    ProcessEvent(evt_settings_common);
}

void ControlsODE::construct_common_settings(Settings_Common* settings) {
    // TODO: Implement custom values
    settings->step_x = 0.1;
}

void ControlsODE::on_test_button(wxCommandEvent& evt) {
    SendResults();
}
