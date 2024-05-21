#include "ode_entry.h"

const wxString test_options[] = {
    "Option A",
    "Option B",
    "idk more options",
};

#define AMOUNT_TEST_OPTIONS 3

OdeEntry::OdeEntry(wxWindow* parent) : wxPanel(parent) {
    sizer_main = new wxBoxSizer(wxHORIZONTAL);

    dropdown_test = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, AMOUNT_TEST_OPTIONS, test_options);
    sizer_main->Add(dropdown_test, 1);

    SetSizer(sizer_main);
}

OdeEntry::~OdeEntry() { }
