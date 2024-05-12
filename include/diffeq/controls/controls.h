#ifndef DIFFEQ_CONTROLS
#define DIFFEQ_CONTROLS

#include <wx/wx.h>
#include "settings.h"
#include "controls_view.h"
#include "controls_ode.h"

class Controls : public wxPanel {
public:
    Controls(wxWindow* parent);
    ~Controls();

    Settings_Plotter get_settings_plotter();

public:
    ControlsODE* controls_ode;
    ControlsView* controls_view;

    wxBoxSizer* sizer_main;

private:
    Settings_Plotter settings_plotter;

private:
    void init_elements();
    void init_sizers();
    void init_settings_plotter();
};

#endif
