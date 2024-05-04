#include "main.h"

Diffeq_Main::Diffeq_Main() : wxFrame(nullptr, wxID_ANY, "Differential Equation analyzer", wxDefaultPosition, wxSize(1280, 720)) {
    instance_layout();
}

Diffeq_Main::~Diffeq_Main() {

}

void Diffeq_Main::instance_layout() {
    plotter = new Plotter(this);
    controls = new Controls(this);

    sizer_main = new wxBoxSizer(wxVERTICAL);

    sizer_main->Add(plotter, 3, wxEXPAND);
    sizer_main->Add(controls, 1, wxEXPAND);

    SetSizer(sizer_main);
}
