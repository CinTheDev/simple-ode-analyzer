#include "controls_ode.h"
#include "ode_harmonic.h"
#include "ode_v_oscillation.h"
#include "events.h"

ControlsODE::ControlsODE(wxWindow* parent) : Controls(parent, "Approximation controls") {
    init_elements();

    ode = new ODE_V_Oscillation(Settings_Common(), Settings_Approximation());
    ode->calculate();

    SendResults();

    Bind(wxEVT_BUTTON, &ControlsODE::on_button_calculate, this);
}

void ControlsODE::init_elements() {
    button_calculate = new wxButton(this, wxID_ANY, "Calculate");
    controls_specialized = new ControlsSpecialized(this);

    label_amount = new wxStaticText(this, wxID_ANY, "Amount of calculated values");
    label_step_x = new wxStaticText(this, wxID_ANY, "Step along x");
    label_subdivision = new wxStaticText(this, wxID_ANY, "Subdivisions between every point");

    input_amount = new wxTextCtrl(this, wxID_ANY, "amount");
    input_step_x = new wxTextCtrl(this, wxID_ANY, "step x");
    input_subdivision = new wxTextCtrl(this, wxID_ANY, "subdivision");

    sizer_main->Insert(0, button_calculate, 0, wxEXPAND | wxALL & ~wxBOTTOM, 10);

    sizer_grid->Add(label_amount);
    sizer_grid->Add(input_amount);

    sizer_grid->Add(label_step_x);
    sizer_grid->Add(input_step_x);

    sizer_grid->Add(label_subdivision);
    sizer_grid->Add(input_subdivision);

    sizer_main->Add(controls_specialized, 0, wxEXPAND);

    Settings_Common default_common_settings = Settings_Common();
    Settings_Approximation default_approx_settings = Settings_Approximation();
    update_values(default_common_settings);
    update_values(default_approx_settings);
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

    settings_common.step_x = get_input_double(input_step_x, label_step_x);

    return settings_common;
}

Settings_Approximation ControlsODE::construct_approx_settings() {
    Settings_Approximation settings_approx;

    settings_approx.amount = get_input_int(input_amount, label_amount);
    settings_approx.subdivision = get_input_int(input_subdivision, label_subdivision);

    return settings_approx;
}

void ControlsODE::update_values(Settings_Common settings_common) {
    input_step_x->ChangeValue(double_to_string(settings_common.step_x));
}

void ControlsODE::update_values(Settings_Approximation settings_approx) {
    input_amount->ChangeValue(std::to_string(settings_approx.amount));
    input_subdivision->ChangeValue(std::to_string(settings_approx.subdivision));
}

void ControlsODE::on_text_input(wxEvent& evt) {
    update_ode();
}

void ControlsODE::update_ode() {
    Settings_Common settings_common = construct_common_settings();
    Settings_Approximation settings_ode = construct_approx_settings();

    ode->apply_settings(settings_common);
    ode->apply_settings(settings_ode);
}

void ControlsODE::on_button_calculate(wxCommandEvent& evt) {
    ode->calculate();
    SendResults();
}
