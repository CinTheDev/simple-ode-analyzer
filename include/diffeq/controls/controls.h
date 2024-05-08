#ifndef DIFFEQ_CONTROLS
#define DIFFEQ_CONTROLS

#include <wx/wx.h>

struct Settings_Plotter {
public:
    double step_x;
    double step_y;
};

class Controls : public wxPanel {
public:
    Controls(wxWindow* parent);
    ~Controls();

public:
    wxButton* test_button;

    wxBoxSizer* sizer_main;

private:
    Settings_Plotter settings_plotter;

private:
    void init_settings_plotter();
};

#endif
