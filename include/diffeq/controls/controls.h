#ifndef DIFFEQ_CONTROLS
#define DIFFEQ_CONTROLS

#include <wx/wx.h>
#include "events.h"
#include "controls_view.h"
#include "controls_ode.h"

class Controls : public wxPanel {
public:
    Controls(wxWindow* parent);
    ~Controls();

public:
    ControlsODE* controls_ode;
    ControlsView* controls_view;

    wxBoxSizer* sizer_main;

public:
    void on_plotter_update(SettingsPlotterEvent& evt);

private:
    void init_elements();
    void init_sizers();
};

#endif
