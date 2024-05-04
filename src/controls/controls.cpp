#include "controls.h"

Controls::Controls(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
    test_button = new wxButton(this, wxID_ANY, "Controls");

    sizer_main = new wxBoxSizer(wxHORIZONTAL);
    sizer_main->Add(test_button, 1, wxEXPAND);
    SetSizer(sizer_main);
}

Controls::~Controls() {

}
