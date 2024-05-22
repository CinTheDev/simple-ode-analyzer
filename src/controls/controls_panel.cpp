#include "controls_panel.h"
#include "events.h"

ControlsPanel::ControlsPanel(wxWindow* parent) : wxPanel(parent) {
    init_elements();
    init_sizers();
}

ControlsPanel::~ControlsPanel() {

}

void ControlsPanel::init_elements() {
    controls_ode = new ControlsODE(this);
    controls_choose = new ControlsChoose(this);
    //controls_special = new ControlsSpecialized(this);
    controls_view = new ControlsView(this);

    controls_choose->Bind(EVT_ODE_LIST, &ControlsODE::on_ode_list, controls_ode);
}

void ControlsPanel::init_sizers() {
   sizer_main = new wxBoxSizer(wxHORIZONTAL);

   sizer_main->Add(controls_ode, 2, wxEXPAND | wxALL, 5);
   sizer_main->Add(controls_choose, 1, wxEXPAND | wxALL, 5);
   //sizer_main->Add(controls_special, 1, wxEXPAND | wxALL, 5);
   sizer_main->Add(controls_view, 1, wxEXPAND | wxALL, 5);

   SetSizer(sizer_main);
}

void ControlsPanel::on_plotter_update(SettingsPlotterEvent& evt) {
    controls_view->update_values(evt.get_settings());
}
