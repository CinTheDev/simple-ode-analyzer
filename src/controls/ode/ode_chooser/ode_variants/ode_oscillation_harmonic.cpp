#include "ode_oscillation_harmonic.h"

Ode_Oscillation_Harmonic::Ode_Oscillation_Harmonic(wxWindow* parent) : OdeEntry(parent, "Harmonic Oscillation") {
    some_label = new wxStaticText(this, wxID_ANY, "Some label");
    some_option = new wxTextCtrl(this, wxID_ANY, "Some option");
}

Ode_Oscillation_Harmonic::~Ode_Oscillation_Harmonic() { }
