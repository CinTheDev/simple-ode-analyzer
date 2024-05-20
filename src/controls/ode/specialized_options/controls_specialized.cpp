#include "controls_specialized.h"

ControlsSpecialized::ControlsSpecialized(wxWindow* parent) : Controls(parent, "ODE specific values") {
    wxString test_labels[] = { "First option", "Second option", "Third option" };
    create_options(3, test_labels);
}

ControlsSpecialized::~ControlsSpecialized() {
    purge();
}

void ControlsSpecialized::create_options(size_t number, wxString* labels) {
    purge();

    this->labels = new wxStaticText*[number];
    this->inputs = new wxTextCtrl*[number];

    for (int i = 0; i < number; i++) {
        this->labels[i] = new wxStaticText(this, wxID_ANY, labels[i]);
        this->inputs[i] = new wxTextCtrl(this, wxID_ANY, labels[i]);

        sizer_grid->Add(this->labels[i]);
        sizer_grid->Add(this->inputs[i]);
    }
}

void ControlsSpecialized::purge() {
    // TODO
}
