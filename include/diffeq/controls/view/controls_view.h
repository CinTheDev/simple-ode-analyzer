#ifndef CONTROLS_VIEW
#define CONTROLS_VIEW

#include <wx/wx.h>
#include "controls.h"
#include "settings.h"

class ControlsView : public Controls {
public:
    ControlsView(wxWindow* parent);
    ~ControlsView();

    wxStaticText* label_view_x;
    wxStaticText* label_view_y;
    wxStaticText* label_offset_x;
    wxStaticText* label_axis_offset;

    wxTextCtrl* input_view_x;
    wxTextCtrl* input_view_y;
    wxTextCtrl* input_offset_x;
    wxTextCtrl* input_axis_offset;

public:
    Settings_Plotter construct_plotter_settings();
    void update_values(Settings_Plotter settings_plotter);

    void on_text_input(wxEvent& evt);

private:
    void init_elements();
};

#endif
