#ifndef DIFFEQ_MAIN
#define DIFFEQ_MAIN

#include <wx/wx.h>
#include "plotter.h"
#include "controls_panel.h"

// TODO: Fix memory issue that makes the program crash sometimes on startup

class Diffeq_Main : public wxFrame {
public:
    Diffeq_Main();
    ~Diffeq_Main();

public:
    wxBoxSizer* sizer_main;

    Plotter* plotter;
    ControlsPanel* controls;

private:
    void instance_layout();
};

#endif
