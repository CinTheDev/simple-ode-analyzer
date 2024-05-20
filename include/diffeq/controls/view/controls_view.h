#ifndef CONTROLS_VIEW
#define CONTROLS_VIEW

#include <wx/wx.h>
#include "controls.h"
#include "settings.h"

class ControlsView : public Controls {
public:
    ControlsView(wxWindow* parent);
    ~ControlsView();

    wxTextCtrl* input_view_x;
    wxTextCtrl* input_view_y;
    wxTextCtrl* input_offset_x;
    wxTextCtrl* input_axis_offset;

    wxStaticText* label_view_x;
    wxStaticText* label_view_y;
    wxStaticText* label_offset_x;
    wxStaticText* label_axis_offset;

    //wxStaticBoxSizer* sizer_main;
    //wxFlexGridSizer* sizer_grid;

public:
    Settings_Plotter construct_plotter_settings();
    void update_values(Settings_Plotter settings_plotter);

    void on_text_input(wxEvent& evt);

private:
    //double get_input_double(wxTextCtrl* input_field, wxStaticText* label);
    //int get_input_int(wxTextCtrl* input_field, wxStaticText* label);

    //wxString double_to_string(double val);

    void init_elements();
    void init_sizers();
};

#endif
