#include "controls_view.h"

ControlsView::ControlsView(wxWindow* parent) : wxPanel(parent) {
    sizer_main = new wxBoxSizer(wxHORIZONTAL);

    test_button = new wxButton(this, wxID_ANY, "Controls View");
    sizer_main->Add(test_button, wxEXPAND);

    SetSizer(sizer_main);
}

ControlsView::~ControlsView() { }
