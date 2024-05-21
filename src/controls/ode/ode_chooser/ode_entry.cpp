#include "ode_entry.h"

const wxString ode_options[] = {
    "Option A",
    "Option B",
    "idk more options",
};

const wxString approx_options[] = {
    "Euler",
    "Test",
};

OdeEntry::OdeEntry(wxWindow* parent) : wxPanel(parent) {
    init_elements();
    init_sizers();
}

OdeEntry::~OdeEntry() { }

void OdeEntry::init_elements() {
    size_t amount_ode_options = sizeof(ode_options) / sizeof(wxString);
    size_t amount_approx_options = sizeof(approx_options) / sizeof(wxString);

    dropdown_ode = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, amount_ode_options, ode_options);
    dropdown_approx = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, amount_approx_options, approx_options);

    colour_picker = new wxColourPickerCtrl(this, wxID_ANY, *wxRED);
    button_remove = new wxButton(this, wxID_ANY, "Remove");

    button_remove->Bind(wxEVT_BUTTON, &OdeEntry::on_button_remove, this);
}

void OdeEntry::init_sizers() {
    sizer_main = new wxBoxSizer(wxHORIZONTAL);

    sizer_main->Add(dropdown_ode, 0);
    sizer_main->Add(dropdown_approx, 0);
    sizer_main->Add(colour_picker, 0);
    sizer_main->Add(button_remove, 0);

    SetSizer(sizer_main);
}

void OdeEntry::on_button_remove(wxCommandEvent& evt) {
    
}
