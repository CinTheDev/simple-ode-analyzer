#ifndef DIFFEQ_CONTROLS_PANEL
#define DIFFEQ_CONTROLS_PANEL

#include <wx/wx.h>
#include "events.h"
#include "controls_view.h"
#include "controls_ode.h"
#include "controls_choose.h"

class ControlsPanel : public wxPanel {
public:
    ControlsPanel(wxWindow* parent);
    ~ControlsPanel();

public:
    ControlsODE* controls_ode;
    ControlsChoose* controls_choose;
    ControlsView* controls_view;

    wxBoxSizer* sizer_main;

public:
    void on_plotter_update(SettingsPlotterEvent& evt);

private:
    void init_elements();
    void init_sizers();
};

#endif
