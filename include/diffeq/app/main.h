#ifndef DIFFEQ_MAIN
#define DIFFEQ_MAIN

#include <wx/wx.h>
#include "plotter.h"
#include "controls.h"

class Diffeq_Main : public wxFrame {
public:
    Diffeq_Main();
    ~Diffeq_Main();

public:
    wxBoxSizer* sizer_main;

    Plotter* plotter;
    Controls* controls;

private:
    void instance_layout();
};

#endif
