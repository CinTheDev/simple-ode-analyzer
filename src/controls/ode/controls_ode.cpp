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
    OdePointerEvent event(EVT_ODE_POINTER, GetId(), ode->get_result(), ode->get_length());
    event.SetEventObject(this);
    event.ResumePropagation(__INT_MAX__);
    ProcessEvent(event);
}

void ControlsODE::construct_common_settings(Settings_Common* settings) {
    // TODO: Implement custom values
    settings->step_x = 0.01;
}

void ControlsODE::on_test_button(wxCommandEvent& evt) {
    SendResults();
}
