#include "controls_ode.h"
#include "ode_harmonic.h"
#include "ode_v_oscillation.h"
#include "events.h"

ControlsODE::ControlsODE(wxWindow* parent) : wxScrolledWindow(parent) {
    init_elements();
    init_sizers();
    //sizer_main = new wxBoxSizer(wxVERTICAL);

    //test_button = new wxButton(this, 12000, "Controls ODE");
    //sizer_main->Add(test_button, 1, wxEXPAND);

    //SetSizer(sizer_main);

    ode = new ODE_V_Oscillation(100, Settings_Common());
    ode->calculate();

    SendResults();

    //Bind(wxEVT_BUTTON, &ControlsODE::on_test_button, this);
}

void ControlsODE::init_elements() {
    input_step_x = new wxTextCtrl(this, wxID_ANY, "step x");
    input_subdivision = new wxTextCtrl(this, wxID_ANY, "subdivision");

    // TODO: Put default values inside text fields
}

void ControlsODE::init_sizers() {
    sizer_grid = new wxFlexGridSizer(2, 5, 5);
    sizer_grid->AddGrowableCol(0, 1);

    label_step_x = new wxStaticText(this, wxID_ANY, "Step along x");
    sizer_grid->Add(label_step_x);
    sizer_grid->Add(input_step_x);

    label_subdivision = new wxStaticText(this, wxID_ANY, "Subdivisions between every point");
    sizer_grid->Add(label_subdivision);
    sizer_grid->Add(input_subdivision);

    sizer_main = new wxStaticBoxSizer(wxVERTICAL, this, "Approximation controls");
    sizer_main->Add(sizer_grid, 1, wxEXPAND | wxALL, 10);

    SetSizer(sizer_main);

    FitInside();
    SetScrollRate(5, 5);
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
    SettingsCommonEvent evt_settings_common(SETTINGS_COMMON_UPDATE, GetId(), construct_common_settings());
    evt_settings_common.SetEventObject(this);
    evt_settings_common.ResumePropagation(__INT_MAX__);
    ProcessEvent(evt_settings_common);
}

Settings_Common ControlsODE::construct_common_settings() {
    Settings_Common settings_common;

    // TODO: Implement custom values
    settings_common.step_x = 0.01;

    return settings_common;
}

void ControlsODE::on_test_button(wxCommandEvent& evt) {
    SendResults();
}
