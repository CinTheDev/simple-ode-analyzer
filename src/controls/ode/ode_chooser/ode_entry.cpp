#include "ode_entry.h"
#include "events.h"

const wxString ode_options[] = {
    "Harmonic Oscillation",
    "Gravitational Oscillation",
};

const wxString approx_options[] = {
    "Euler",
    "TODO",
};

const OdeTypes ode_types[] = {
    OdeTypes::HarmonicOscillation,
    OdeTypes::GravitationalOscillation,
};

const ApproxTypes approx_types[] = {
    ApproxTypes::Euler,
    ApproxTypes::Test,
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

    // Default selection
    dropdown_ode->SetSelection(0);
    dropdown_approx->SetSelection(0);
}

void OdeEntry::init_sizers() {
    sizer_main = new wxBoxSizer(wxVERTICAL);
    sizer_options = new wxBoxSizer(wxHORIZONTAL);

    sizer_options->Add(dropdown_ode, 0);
    sizer_options->Add(dropdown_approx, 0);
    sizer_options->Add(colour_picker, 0);
    sizer_options->Add(button_remove, 0);

    sizer_main->Add(sizer_options, 0, wxEXPAND);

    SetSizer(sizer_main);
}

OdeListValues OdeEntry::construct_values() {
    OdeListValues values = OdeListValues();

    int ode_type_selection = dropdown_ode->GetSelection();
    int approx_type_selection = dropdown_approx->GetSelection();

    values.ode_type = ode_types[ode_type_selection];
    values.approx_type = approx_types[approx_type_selection];
    values.colour = colour_picker->GetColour().GetRGBA();

    return values;
}
