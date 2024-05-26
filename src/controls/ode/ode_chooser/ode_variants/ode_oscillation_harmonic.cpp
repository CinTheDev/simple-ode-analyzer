#include "ode_oscillation_harmonic.h"

Ode_Oscillation_Harmonic::Ode_Oscillation_Harmonic(wxWindow* parent) : OdeEntry(parent, "Harmonic Oscillation") {
    some_label = new wxStaticText(this, wxID_ANY, "Some label");
    some_option = new wxTextCtrl(this, wxID_ANY, "Some option");

    add_option(some_label, some_option);

    set_result_length(100);
}

Ode_Oscillation_Harmonic::~Ode_Oscillation_Harmonic() { }

void Ode_Oscillation_Harmonic::calculate() {
    for (size_t i = 0; i < result_length; i++) {
        result[i] = (double)i / (double)result_length;
    }
}
