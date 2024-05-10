#ifndef DIFFEQ_PLOTTER
#define DIFFEQ_PLOTTER

#include <wx/wx.h>
#include "events.h"

enum ShortcutState {
    FREE,
    
    ZOOM_UNSPECIFIED,
    ZOOM_X,
    ZOOM_Y,

    MOVE_X,
};

class Plotter : public wxPanel {
public:
    Plotter(wxWindow* parent);
    ~Plotter();

private:
    Settings_Plotter settings;
    ShortcutState shortcut_state = ShortcutState::FREE;

public:
    void on_settings_update(SettingsPlotterEvent& evt);

    void paintEvent(wxPaintEvent& evt);
    void paintNow();

    void render(wxDC& dc);

    DECLARE_EVENT_TABLE()

private:
    void render_axes(wxDC& dc);
    void render_markings(wxDC& dc);
    void render_function(wxDC& dc);
    double round_to_nice_number(double val);
};

#endif
