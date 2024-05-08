#include "controls.h"
#include "events.h"

wxBEGIN_EVENT_TABLE(Controls, wxPanel)

    //EVT_BUTTON(11000, Controls::on_button_test)

wxEND_EVENT_TABLE()

Controls::Controls(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
    //test_button = new wxButton(this, 11000, "Controls");
    init_settings_plotter();
    init_elements();

    sizer_main = new wxBoxSizer(wxVERTICAL);
    //sizer_main->Add(test_button, 1, wxEXPAND);
    sizer_main->Add(input_step_x, wxEXPAND);
    sizer_main->Add(input_step_y, wxEXPAND);
    SetSizer(sizer_main);
}

Controls::~Controls() {

}

void Controls::init_elements() {
    input_step_x = new wxTextCtrl(this, wxID_ANY, std::to_string(settings_plotter.step_x));
    input_step_y = new wxTextCtrl(this, wxID_ANY, std::to_string(settings_plotter.step_y));
}

Settings_Plotter Controls::get_settings_plotter() {
    return settings_plotter;
}

void Controls::init_settings_plotter() {
    settings_plotter = Settings_Plotter();
}

/*
void Controls::on_button_test(wxCommandEvent& evt) {
    // Test event
    SettingsPlotterEvent settings_plotter_event = SettingsPlotterEvent(SETTINGS_PLOTTER_UPDATE, GetId(), settings_plotter);
    settings_plotter_event.SetEventObject(this);
    ProcessEvent(settings_plotter_event);
}
*/

void Controls::update_settings_plotter() {
    settings_plotter.step_x = std::stod(input_step_x->GetValue().ToStdString());
    settings_plotter.step_y = std::stod(input_step_y->GetValue().ToStdString());
}

void Controls::on_controls_plotter_changed(wxEvent& evt) {
    update_settings_plotter();

    SettingsPlotterEvent settings_plotter_event = SettingsPlotterEvent(SETTINGS_PLOTTER_UPDATE, GetId(), settings_plotter);
    settings_plotter_event.SetEventObject(this);
    ProcessEvent(settings_plotter_event);
}
