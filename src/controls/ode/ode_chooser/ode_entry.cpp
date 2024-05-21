#include "ode_entry.h"

const wxString test_options[] = {
    "Option A",
    "Option B",
    "idk more options",
};

OdeEntry::OdeEntry(wxWindow* parent) : wxPanel(parent) {
    init_elements();
    init_sizers();
    //size_t amount_test_options = sizeof(test_options) / sizeof(wxString);

    //dropdown_test = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, amount_test_options, test_options);
    //sizer_main->Add(dropdown_test, 1);
}

OdeEntry::~OdeEntry() { }

void OdeEntry::init_elements() {
    dropdown_ode = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, amount_ode_options, ode_options);
    dropdown_approx = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, amount_approx_options, approx_options);

    placeholder_colorpicker = new wxButton(this, wxID_ANY, "Placeholder Color picker");
    button_remove = new wxButton(this, wxID_ANY, "Remove");
}

void OdeEntry::init_sizers() {
    sizer_main = new wxBoxSizer(wxHORIZONTAL);

    sizer_main->Add(dropdown_ode, 1);
    sizer_main->Add(dropdown_approx, 1);
    sizer_main->Add(placeholder_colorpicker, 1);
    sizer_main->Add(button_remove, 0);

    SetSizer(sizer_main);
}
