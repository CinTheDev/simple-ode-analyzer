#ifndef CONTROLS_ODE
#define CONTROLS_ODE

#include <wx/wx.h>

class ControlsODE : public wxPanel {
public:
    ControlsODE(wxWindow* parent);
    ~ControlsODE();

    wxButton* test_button;
    wxBoxSizer* sizer_main;
};

#endif
