#include "controls_view.h"

ControlsView::ControlsView(wxWindow* parent) : wxPanel(parent) {
    sizer_main = new wxBoxSizer(wxVERTICAL);

    test_button = new wxButton(this, wxID_ANY, "Controls View");
    sizer_main->Add(test_button, 1, wxEXPAND);

    SetSizer(sizer_main);
}

ControlsView::~ControlsView() { }
