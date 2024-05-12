#include "controls_view.h"

ControlsView::ControlsView(wxWindow* parent) : wxScrolledWindow(parent) {
    init_elements();
    init_sizers();
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

void ControlsView::construct_plotter_settings(Settings_Plotter& settings_plotter) {

}

void ControlsView::update_values(Settings_Plotter settings_plotter) {
    input_view_x->SetValue(std::to_string(settings_plotter.view_x));
    input_view_y->SetValue(std::to_string(settings_plotter.view_y));

    // TODO: update other fields as well
}
