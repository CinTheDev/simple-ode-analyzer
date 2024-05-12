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
    input_offset_x = new wxTextCtrl(this, wxID_ANY, "offset x");
    input_axis_offset = new wxTextCtrl(this, wxID_ANY, "offset axis");

    Settings_Plotter default_settings = Settings_Plotter();
    update_values(default_settings);
}

void ControlsView::init_sizers() {
    sizer_grid = new wxFlexGridSizer(2, 5, 5);
    sizer_grid->AddGrowableCol(0, 1);

    wxStaticText* temp_ptr_label;

    temp_ptr_label = new wxStaticText(this, wxID_ANY, "Visible X space");
    sizer_grid->Add(temp_ptr_label);
    sizer_grid->Add(input_view_x);

    temp_ptr_label = new wxStaticText(this, wxID_ANY, "Visible Y space");
    sizer_grid->Add(temp_ptr_label);
    sizer_grid->Add(input_view_y);

    temp_ptr_label = new wxStaticText(this, wxID_ANY, "X start value");
    sizer_grid->Add(temp_ptr_label);
    sizer_grid->Add(input_offset_x);

    temp_ptr_label = new wxStaticText(this, wxID_ANY, "Axis offset");
    sizer_grid->Add(temp_ptr_label);
    sizer_grid->Add(input_axis_offset);

    sizer_main = new wxStaticBoxSizer(wxVERTICAL, this, "View");
    sizer_main->Add(sizer_grid, 1, wxEXPAND);

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

    try { settings_plotter->view_start_x = std::stod(input_offset_x->GetValue().ToStdString()); }
    catch (...) {

    }

    try { settings_plotter->axis_offset = std::stoi(input_axis_offset->GetValue().ToStdString()); }
    catch (...) {

    }
}

void ControlsView::update_values(Settings_Plotter settings_plotter) {
    input_view_x->ChangeValue(std::to_string(settings_plotter.view_x));
    input_view_y->ChangeValue(std::to_string(settings_plotter.view_y));
    input_offset_x->ChangeValue(std::to_string(settings_plotter.view_start_x));
    input_axis_offset->ChangeValue(std::to_string(settings_plotter.axis_offset));
}

void ControlsView::on_text_input(wxEvent& evt) {
    Settings_Plotter settings_plotter;
    construct_plotter_settings(&settings_plotter);

    SettingsPlotterEvent settings_plotter_event = SettingsPlotterEvent(SETTINGS_PLOTTER_UPDATE, GetId(), settings_plotter);
    settings_plotter_event.SetEventObject(this);
    settings_plotter_event.ResumePropagation(__INT_MAX__);
    ProcessEvent(settings_plotter_event);
}
