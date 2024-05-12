#ifndef CONTROLS_VIEW
#define CONTROLS_VIEW

#include <wx/wx.h>
#include "settings.h"

class ControlsView : public wxScrolledWindow {
public:
    ControlsView(wxWindow* parent);
    ~ControlsView();

    wxTextCtrl* input_view_x;
    wxTextCtrl* input_view_y;

    wxFlexGridSizer* sizer_main;

public:
    void construct_plotter_settings(Settings_Plotter* settings_plotter);
    void update_values(Settings_Plotter settings_plotter);

private:
    void init_elements();
    void init_sizers();
};

#endif
