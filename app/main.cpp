#include "main.h"

Diffeq_Main::Diffeq_Main() : wxFrame(nullptr, wxID_ANY, "Differential Equation analyzer", wxDefaultPosition, wxSize(1280, 720)) {
    instance_layout();
}

Diffeq_Main::~Diffeq_Main() {

}

void Diffeq_Main::instance_layout() {
    plotter = new Plotter(this);
    controls = new ControlsPanel(this);

    // Bind events between both
    controls->Bind(SETTINGS_PLOTTER_UPDATE, &Plotter::on_settings_update, plotter);
    controls->Bind(SETTINGS_COMMON_UPDATE, &Plotter::on_settings_common_update, plotter);
    controls->Bind(EVT_ODE_POINTER, &Plotter::on_function_update, plotter);
    plotter->Bind(PLOTTER_GRAPHICS_UPDATE, &ControlsPanel::on_plotter_update, controls);

    sizer_main = new wxBoxSizer(wxVERTICAL);

    sizer_main->Add(plotter, 3, wxEXPAND);
    sizer_main->Add(controls, 1, wxEXPAND);

    SetSizer(sizer_main);
}
