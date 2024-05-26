#include "entry_dialog.h"
#include "ode_variants.h"

EntryDialog::EntryDialog(wxWindow* parent) : wxDialog(parent, wxID_ANY, "Choose ODE type") {
    test_button = new wxButton(this, wxID_ANY, "Dialog");
    test_button->Bind(wxEVT_BUTTON, &EntryDialog::on_test_button, this);

    sizer_main = new wxBoxSizer(wxVERTICAL);

    sizer_main->Add(test_button, 1, wxEXPAND);

    SetSizer(sizer_main);
}

EntryDialog::~EntryDialog() { }

OdeEntry* EntryDialog::get_entry() {
    return new Ode_Oscillation_Harmonic(GetParent());
}

void EntryDialog::on_test_button(wxCommandEvent& evt) {
    EndModal(wxID_OK);
}
