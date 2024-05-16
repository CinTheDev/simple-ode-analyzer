#ifndef CONTROLS_ODE
#define CONTROLS_ODE

#include <wx/wx.h>
#include "ode.h"
#include "settings.h"

class ControlsODE : public wxPanel {
public:
    ControlsODE(wxWindow* parent);
    ~ControlsODE();

    wxButton* test_button;
    wxBoxSizer* sizer_main;

    void SendResults();

    void construct_common_settings(Settings_Common* settings);

private:
    ODE* ode;

    void on_test_button(wxCommandEvent& evt);
};

#endif
