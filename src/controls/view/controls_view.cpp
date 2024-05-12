#include "controls_view.h"

ControlsView::ControlsView(wxWindow* parent) : wxScrolledWindow(parent) {
    init_elements();
    init_sizers();
}

ControlsView::~ControlsView() { }

void ControlsView::init_elements() {
    input_view_x = new wxTextCtrl(this, wxID_ANY, "view x");
    input_view_y = new wxTextCtrl(this, wxID_ANY, "view y");
}

void ControlsView::init_sizers() {
    sizer_main = new wxFlexGridSizer(2, 5, 5);

    sizer_main->Add(new wxStaticText(this, wxID_ANY, "Visible X space"));
    sizer_main->Add(input_view_x);
    sizer_main->Add(new wxStaticText(this, wxID_ANY, "Visible Y space"));
    sizer_main->Add(input_view_y);

    SetSizer(sizer_main);

    FitInside();
    SetScrollRate(5, 5);
}
