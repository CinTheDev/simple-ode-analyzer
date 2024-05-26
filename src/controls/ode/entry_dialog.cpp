#include "entry_dialog.h"
#include "ode_variants.h"

wxString options[] = {
    "Harmonic Oscillation - Generic",
    "Harmonic Oscillation - Mechanical",
    "Harmonic Oscillation - Electromagnetic",
    "Oscillation of a pendulum / swing",
    "Gravitational Oscillation",
};

enum {
    OPTION_OSCILLATION_HARMONIC,
    OPTION_OSCILLATION_HARMONIC_MECHANICAL,
    OPTION_OSCILLATION_HARMONIC_ELECTROMAGNETIC,
    OPTION_OSCILLATION_PENDULUM,
    OPTION_OSCILLATION_GRAVITATIONAL
};

EntryDialog::EntryDialog(wxWindow* parent) : wxDialog(parent, wxID_ANY, "Choose ODE type") {
    init_elements();
    init_sizers();
}

EntryDialog::~EntryDialog() { }

void EntryDialog::init_elements() {
    size_t amount_options = sizeof(options) / sizeof(options[0]);

    list_options = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, amount_options, options, wxLB_SINGLE);
    button_choose = new wxButton(this, wxID_ANY, "Select");

    // Default selection
    list_options->SetSelection(0);

    button_choose->Bind(wxEVT_BUTTON, &EntryDialog::on_button_choose, this);
}

void EntryDialog::init_sizers() {
    sizer_main = new wxBoxSizer(wxVERTICAL);

    sizer_main->Add(list_options, 1, wxEXPAND);
    sizer_main->Add(button_choose, 0, wxEXPAND);

    SetSizer(sizer_main);
}

OdeEntry* EntryDialog::get_entry() {
    return new Ode_Oscillation_Harmonic(GetParent());
}

void EntryDialog::on_button_choose(wxCommandEvent& evt) {
    EndModal(wxID_OK);
}
