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
    //wxButton* test_button;
    wxTextCtrl* input_step_x;
    wxTextCtrl* input_step_y;

    wxBoxSizer* sizer_main;

    DECLARE_EVENT_TABLE();

private:
    Settings_Plotter settings_plotter;

private:
    void init_elements();
    void init_settings_plotter();
    void update_settings_plotter();
    //void on_button_test(wxCommandEvent& evt);
    void on_controls_plotter_changed(wxEvent& evt);
};

#endif
