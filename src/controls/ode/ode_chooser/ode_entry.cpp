#include "ode_entry.h"

const wxString test_options[] = {
    "Option A",
    "Option B",
    "idk more options",
};

OdeEntry::OdeEntry(wxWindow* parent) : wxPanel(parent) {
    sizer_main = new wxBoxSizer(wxHORIZONTAL);

    size_t amount_test_options = sizeof(test_options) / sizeof(wxString);

    dropdown_test = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, amount_test_options, test_options);
    sizer_main->Add(dropdown_test, 1);

    SetSizer(sizer_main);
}

OdeEntry::~OdeEntry() { }
