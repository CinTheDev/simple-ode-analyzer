#include "controls_view.h"
#include "events.h"

ControlsView::ControlsView(wxWindow* parent) : Controls(parent, "View") {
    init_elements();
    init_sizers();
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
    label_view_x = new wxStaticText(this, wxID_ANY, "Visible X space");
    sizer_grid->Add(label_view_x);
    sizer_grid->Add(input_view_x);

    label_view_y = new wxStaticText(this, wxID_ANY, "Visible Y space");
    sizer_grid->Add(label_view_y);
    sizer_grid->Add(input_view_y);

    label_offset_x = new wxStaticText(this, wxID_ANY, "X start value");
    sizer_grid->Add(label_offset_x);
    sizer_grid->Add(input_offset_x);

    label_axis_offset = new wxStaticText(this, wxID_ANY, "Axis offset");
    sizer_grid->Add(label_axis_offset);
    sizer_grid->Add(input_axis_offset);
}

Settings_Plotter ControlsView::construct_plotter_settings() {
    Settings_Plotter settings_plotter;

    settings_plotter.view_x = get_input_double(input_view_x, label_view_x);
    settings_plotter.view_y = get_input_double(input_view_y, label_view_y);
    settings_plotter.view_start_x = get_input_double(input_offset_x, label_offset_x);
    settings_plotter.axis_offset = get_input_int(input_axis_offset, label_axis_offset);

    return settings_plotter;
}

void ControlsView::update_values(Settings_Plotter settings_plotter) {
    input_view_x->ChangeValue(double_to_string(settings_plotter.view_x));
    input_view_y->ChangeValue(double_to_string(settings_plotter.view_y));
    input_offset_x->ChangeValue(double_to_string(settings_plotter.view_start_x));
    input_axis_offset->ChangeValue(std::to_string(settings_plotter.axis_offset));
}

void ControlsView::on_text_input(wxEvent& evt) {
    SettingsPlotterEvent settings_plotter_event = SettingsPlotterEvent(SETTINGS_PLOTTER_UPDATE, GetId(), construct_plotter_settings());
    settings_plotter_event.SetEventObject(this);
    settings_plotter_event.ResumePropagation(__INT_MAX__);
    ProcessEvent(settings_plotter_event);
}
