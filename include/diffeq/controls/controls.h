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
    wxTextCtrl* input_step_x;
    wxTextCtrl* input_step_y;

    wxBoxSizer* sizer_main;

private:
    Settings_Plotter settings_plotter;

private:
    void init_elements();
    void init_sizers();
    void init_settings_plotter();
    void update_settings_plotter();
    void on_controls_plotter_changed(wxEvent& evt);
};

#endif
