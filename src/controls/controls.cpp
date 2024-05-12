#include "controls.h"
#include "events.h"

Controls::Controls(wxWindow* parent) : wxPanel(parent) {
    init_elements();
    init_sizers();
}

Controls::~Controls() {

}

void Controls::init_elements() {
    controls_ode = new ControlsODE(this);
    controls_view = new ControlsView(this);
}

void Controls::init_sizers() {
   sizer_main = new wxBoxSizer(wxHORIZONTAL);

   sizer_main->Add(controls_ode, 2, wxEXPAND);
   sizer_main->Add(controls_view, 1, wxEXPAND);

   SetSizer(sizer_main);
}
