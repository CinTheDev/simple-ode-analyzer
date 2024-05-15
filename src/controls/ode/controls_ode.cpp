#include "controls_ode.h"
#include "ode_harmonic.h"
#include "events.h"

ControlsODE::ControlsODE(wxWindow* parent) : wxPanel(parent) {
    sizer_main = new wxBoxSizer(wxVERTICAL);

    test_button = new wxButton(this, 12000, "Controls ODE");
    sizer_main->Add(test_button, 1, wxEXPAND);

    SetSizer(sizer_main);

    ode = ODE_Harmonic(10);
    ode.calculate();

    SendResults();

    Bind(wxEVT_BUTTON, &ControlsODE::on_test_button, this);
}

ControlsODE::~ControlsODE() { }

void ControlsODE::SendResults() {
    OdePointerEvent event(EVT_ODE_POINTER, GetId(), ode.get_result(), ode.get_length());
    event.SetEventObject(this);
    event.ResumePropagation(__INT_MAX__);
    ProcessEvent(event);
}

void ControlsODE::on_test_button(wxCommandEvent& evt) {
    SendResults();
}
