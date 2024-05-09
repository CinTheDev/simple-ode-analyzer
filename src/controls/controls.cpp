#include "controls.h"
#include "events.h"

Controls::Controls(wxWindow* parent) : wxScrolledWindow(parent, wxID_ANY) {
    init_settings_plotter();
    init_elements();
    init_sizers();

    Bind(wxEVT_TEXT, &Controls::on_controls_plotter_changed, this);
}

Controls::~Controls() {

}

void Controls::init_elements() {
    input_step_x = new wxTextCtrl(this, wxID_ANY, std::to_string(settings_plotter.step_x));
    input_view_x = new wxTextCtrl(this, wxID_ANY, std::to_string(settings_plotter.view_x));
    input_view_y = new wxTextCtrl(this, wxID_ANY, std::to_string(settings_plotter.view_y));
}

void Controls::init_sizers() {
    sizer_main = new wxFlexGridSizer(2, 5, 5);

    sizer_main->Add(new wxStaticText(this, wxID_ANY, "Step x"));
    sizer_main->Add(input_step_x);
    sizer_main->Add(new wxStaticText(this, wxID_ANY, "View x"));
    sizer_main->Add(input_view_x);
    sizer_main->Add(new wxStaticText(this, wxID_ANY, "View y"));
    sizer_main->Add(input_view_y);

    SetSizer(sizer_main);

    FitInside();
    SetScrollRate(5, 5);
}

Settings_Plotter Controls::get_settings_plotter() {
    return settings_plotter;
}

void Controls::init_settings_plotter() {
    settings_plotter = Settings_Plotter();
}

void Controls::update_settings_plotter() {
    try { settings_plotter.step_x = std::stod(input_step_x->GetValue().ToStdString()); }
    catch (...) {
        // TODO: Outline textCtrl red
    }
    
    try { settings_plotter.view_x = std::stod(input_view_x->GetValue().ToStdString()); }
    catch (...) {
        // TODO: Outline textCtrl red
    }

    try { settings_plotter.view_y = std::stod(input_view_y->GetValue().ToStdString()); }
    catch (...) {
        // TODO: Outline textCtrl red
    }
}

void Controls::on_controls_plotter_changed(wxEvent& evt) {
    update_settings_plotter();

    SettingsPlotterEvent settings_plotter_event = SettingsPlotterEvent(SETTINGS_PLOTTER_UPDATE, GetId(), settings_plotter);
    settings_plotter_event.SetEventObject(this);
    ProcessEvent(settings_plotter_event);
}
