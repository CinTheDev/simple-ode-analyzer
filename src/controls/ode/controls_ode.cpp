#include "controls_ode.h"
#include <iostream>

ControlsODE::ControlsODE(wxWindow* parent) : Controls(parent, "Approximation controls") {
    init_elements();

    //Bind(wxEVT_BUTTON, &ControlsODE::on_button_calculate, this);
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

ControlsODE::~ControlsODE() { }

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
    // TODO: Send event with settings
    
}

/*
void ControlsODE::on_button_calculate(wxCommandEvent& evt) {
    if (odes_changed) regenerate_odes();

    update_ode_settings();

    for (int i = 0; i < amount_odes; i++) {
        odes[i]->calculate();
    }

    SendResults();
}
*/

/*
void ControlsODE::on_ode_list(OdeListUpdateEvent& evt) {
    delete[] new_ode_structure;

    odes_changed = true;
    amount_new_odes = evt.get_amount();
    new_ode_structure = evt.get_values();
}
*/
