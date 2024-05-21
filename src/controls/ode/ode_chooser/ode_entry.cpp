#include "ode_entry.h"

OdeEntry::OdeEntry(wxWindow* parent) : wxPanel(parent) {
    sizer_main = new wxBoxSizer(wxHORIZONTAL);

    test_button = new wxButton(this, wxID_ANY, "Ima entry");
    sizer_main->Add(test_button, 1);

    SetSizer(sizer_main);
}

OdeEntry::~OdeEntry() { }
