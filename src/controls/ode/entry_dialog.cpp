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

    ode_entry = nullptr;
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
    return ode_entry;
}

void EntryDialog::on_button_choose(wxCommandEvent& evt) {
    create_entry();
    EndModal(wxID_OK);
}

void EntryDialog::create_entry() {
    int selection = list_options->GetSelection();
    if (selection == wxNOT_FOUND) return;

    switch (selection) {
        case OPTION_OSCILLATION_HARMONIC:
            ode_entry = new Ode_Oscillation_Harmonic(GetParent());
            break;

        case OPTION_OSCILLATION_HARMONIC_MECHANICAL:
            ode_entry = new Ode_Oscillation_Harmonic_Mechanical(GetParent());
            break;

        case OPTION_OSCILLATION_HARMONIC_ELECTROMAGNETIC:
            ode_entry = new Ode_Oscillation_Harmonic_Electromagnetic(GetParent());
            break;

        case OPTION_OSCILLATION_PENDULUM:
            ode_entry = new Ode_Oscillation_Pendulum(GetParent());
            break;

        case OPTION_OSCILLATION_GRAVITATIONAL:
            ode_entry = new Ode_Oscillation_Gravitational(GetParent());
            break;

        default:
            std::cout << "WARNING: Unhandled selection of " << selection << " in EntryDialog::create_entry()";
            break;
    }
}
