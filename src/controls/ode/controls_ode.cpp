#include "controls_ode.h"
#include "ode_harmonic.h"
#include "ode_v_oscillation.h"
#include <iostream>

ControlsODE::ControlsODE(wxWindow* parent) : Controls(parent, "Approximation controls") {
    init_elements();

    amount_odes = 0;
    odes = new ODE*[1];

    amount_new_odes = 0;
    new_ode_structure = new OdeListValues[1];

    Bind(wxEVT_BUTTON, &ControlsODE::on_button_calculate, this);
}

void ControlsODE::init_elements() {
    button_calculate = new wxButton(this, wxID_ANY, "Calculate");

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

    Settings_Common default_common_settings = Settings_Common();
    Settings_Approximation default_approx_settings = Settings_Approximation();
    update_values(default_common_settings);
    update_values(default_approx_settings);
}

ControlsODE::~ControlsODE() {
    purge_odes();
}

void ControlsODE::SendResults() {
    // ODE pointer
    size_t amount_results, result_length;
    double** ode_results = get_all_results(amount_results, result_length);

    OdePointerEvent evt_ode_pointer(EVT_ODE_POINTER, GetId(), ode_results, amount_results, result_length);
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

double** ControlsODE::get_all_results(size_t& amount_results, size_t& result_length) {
    amount_results = amount_odes;

    if (amount_results < 1) return nullptr;

    result_length = odes[0]->get_length();

    double** results = new double*[amount_results];

    for (size_t i = 0; i < amount_results; i++) {
        results[i] = odes[i]->get_result();
    }

    return results;
}

void ControlsODE::on_button_calculate(wxCommandEvent& evt) {
    if (odes_changed) regenerate_odes();

    update_ode_settings();

    for (int i = 0; i < amount_odes; i++) {
        odes[i]->calculate();
    }

    SendResults();
}

void ControlsODE::on_ode_list(OdeListUpdateEvent& evt) {
    delete[] new_ode_structure;

    odes_changed = true;
    amount_new_odes = evt.get_amount();
    new_ode_structure = evt.get_values();
}

ODE* ControlsODE::instance_ode(OdeTypes ode_type) {
    switch (ode_type) {
        case OdeTypes::HarmonicOscillation:
            return new ODE_Harmonic(Settings_Common(), Settings_Approximation());

        case OdeTypes::GravitationalOscillation:
            return new ODE_V_Oscillation(Settings_Common(), Settings_Approximation());

        default:
            std::cout << "WARNING [ControlsODE::instance_ode()]: Unhandled OdeTypes enum" << std::endl;
            return nullptr;
    }
}

void ControlsODE::update_ode_settings() {
    Settings_Common settings_common = construct_common_settings();
    Settings_Approximation settings_ode = construct_approx_settings();

    for(int i = 0; i < amount_odes; i++) {
        odes[i]->apply_settings(settings_common);
        odes[i]->apply_settings(settings_ode);
    }
}

void ControlsODE::regenerate_odes() {
    purge_odes();

    amount_odes = amount_new_odes;
    odes = new ODE*[amount_odes];
    ode_colours = new uint32_t[amount_odes];

    for (size_t i = 0; i < amount_odes; i++) {
        OdeListValues values = new_ode_structure[i];

        odes[i] = instance_ode(values.ode_type);

        ode_colours[i] = values.color;
    }
}

void ControlsODE::purge_odes() {
    for (int i = 0; i < amount_odes; i++) {
        delete odes[i];
    }

    delete[] odes;

    delete[] ode_colours;
}
