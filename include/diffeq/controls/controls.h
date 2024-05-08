#ifndef DIFFEQ_CONTROLS
#define DIFFEQ_CONTROLS

#include <wx/wx.h>
#include "settings.h"

class Controls : public wxPanel {
public:
    Controls(wxWindow* parent);
    ~Controls();

    Settings_Plotter get_settings_plotter();

public:
    wxButton* test_button;

    wxBoxSizer* sizer_main;

private:
    Settings_Plotter settings_plotter;

private:
    void init_settings_plotter();
};

#endif
