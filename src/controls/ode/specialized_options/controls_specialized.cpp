#include "controls_specialized.h"

ControlsSpecialized::ControlsSpecialized(wxWindow* parent) : wxPanel(parent) {
    sizer_main = new wxStaticBoxSizer(wxVERTICAL, this, "ODE specific values");

    sizer_grid = new wxFlexGridSizer(2, 5, 5);
    sizer_grid->AddGrowableCol(0, 1);

    sizer_main->Add(sizer_grid);

    SetSizer(sizer_main);
}

ControlsSpecialized::~ControlsSpecialized() { }

void ControlsSpecialized::create_options(size_t options, wxString* labels) {

}

void ControlsSpecialized::purge() {

}
