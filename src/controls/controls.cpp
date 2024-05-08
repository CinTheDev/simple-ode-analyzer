#include "controls.h"
#include "events.h"

Controls::Controls(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
    test_button = new wxButton(this, wxID_ANY, "Controls");

    sizer_main = new wxBoxSizer(wxHORIZONTAL);
    sizer_main->Add(test_button, 1, wxEXPAND);
    SetSizer(sizer_main);

    init_settings_plotter();

    // Test event
    SettingsPlotterEvent settings_plotter_event = SettingsPlotterEvent(SETTINGS_PLOTTER_UPDATE, GetId());
    settings_plotter_event.SetEventObject(this);
    ProcessEvent(settings_plotter_event);
}

Controls::~Controls() {

}

Settings_Plotter Controls::get_settings_plotter() {
    return settings_plotter;
}

void Controls::init_settings_plotter() {
    settings_plotter = Settings_Plotter();
    settings_plotter.step_x = 1.0;
    settings_plotter.step_y = 1.0;
}
