#ifndef DIFFEQ_PLOTTER
#define DIFFEQ_PLOTTER

#include <wx/wx.h>
#include "events.h"

class Plotter : public wxPanel {
public:
    Plotter(wxWindow* parent);
    ~Plotter();

private:
    Settings_Plotter settings;

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
};

#endif
