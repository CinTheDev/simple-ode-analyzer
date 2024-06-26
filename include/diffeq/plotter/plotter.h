#ifndef DIFFEQ_PLOTTER
#define DIFFEQ_PLOTTER

#include <wx/wx.h>
#include "events.h"

enum ActiveShortcut {
    FREE,

    ZOOM_UNSPECIFIED,
    ZOOM_X,
    ZOOM_Y,

    MOVE_X,
};

struct ShortcutState {
    ActiveShortcut active_shortcut = ActiveShortcut::FREE;
    wxPoint mouse_initial;
    Settings_Plotter settings_initial;
};

class Plotter : public wxPanel {
public:
    Plotter(wxWindow* parent);
    ~Plotter();

private:
    Settings_Plotter settings;
    ShortcutState shortcut_state;

    OdeData ode_data;

public:
    void on_settings_update(SettingsPlotterEvent& evt);
    void on_function_update(OdePointerEvent& evt);

    void on_key_pressed(wxKeyEvent& evt);

    void on_mouse_leftclick(wxMouseEvent& evt);
    void on_mouse_rightclick(wxMouseEvent& evt);
    void on_mouse_moved(wxMouseEvent& evt);

    void paintEvent(wxPaintEvent& evt);
    void paintNow();

    void render(wxDC& dc);

    DECLARE_EVENT_TABLE()

private:
    void render_axes(wxDC& dc);
    void render_markings(wxDC& dc);
    void render_function(wxDC& dc);

    double round_to_nice_number(double val);

    void handle_input(wxMouseEvent& evt);
    void handle_zoom_x(wxMouseEvent& evt);
    void handle_zoom_y(wxMouseEvent& evt);
    void handle_move_x(wxMouseEvent& evt);

    void update_control_settings();
    wxString double_truncate(double val);

    void clear_function_data();
};

#endif
