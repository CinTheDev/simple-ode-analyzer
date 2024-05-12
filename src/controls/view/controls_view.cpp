#include "controls_view.h"
#include "events.h"

ControlsView::ControlsView(wxWindow* parent) : wxScrolledWindow(parent) {
    init_elements();
    init_sizers();

    Bind(wxEVT_TEXT, &ControlsView::on_text_input, this);
}

ControlsView::~ControlsView() { }

void ControlsView::init_elements() {
    input_view_x = new wxTextCtrl(this, wxID_ANY, "view x");
    input_view_y = new wxTextCtrl(this, wxID_ANY, "view y");

    Settings_Plotter default_settings = Settings_Plotter();
    update_values(default_settings);
}

void ControlsView::init_sizers() {
    sizer_main = new wxFlexGridSizer(2, 5, 5);
    sizer_main->AddGrowableCol(0, 1);

    wxStaticText* temp_ptr_label;

    temp_ptr_label = new wxStaticText(this, wxID_ANY, "Visible X space");
    sizer_main->Add(temp_ptr_label);
    sizer_main->Add(input_view_x);

    temp_ptr_label = new wxStaticText(this, wxID_ANY, "Visible Y space");
    sizer_main->Add(temp_ptr_label);
    sizer_main->Add(input_view_y);

    SetSizer(sizer_main);

    FitInside();
    SetScrollRate(5, 5);
}

void ControlsView::construct_plotter_settings(Settings_Plotter* settings_plotter) {
    *settings_plotter = Settings_Plotter();

    try { settings_plotter->view_x = std::stod(input_view_x->GetValue().ToStdString()); }
    catch (...) {
        // TODO Outline textctrl red or similar
    }

    try { settings_plotter->view_y = std::stod(input_view_y->GetValue().ToStdString()); }
    catch (...) {
        // TODO Outline textctrl red or similar
    }
}

void ControlsView::update_values(Settings_Plotter settings_plotter) {
    input_view_x->SetValue(std::to_string(settings_plotter.view_x));
    input_view_y->SetValue(std::to_string(settings_plotter.view_y));

    // TODO: update other fields as well
}

void ControlsView::on_text_input(wxEvent& evt) {
    Settings_Plotter settings_plotter;
    construct_plotter_settings(&settings_plotter);

    SettingsPlotterEvent settings_plotter_event = SettingsPlotterEvent(SETTINGS_PLOTTER_UPDATE, GetId(), settings_plotter);
    settings_plotter_event.SetEventObject(this);
    ProcessEvent(settings_plotter_event);
}
