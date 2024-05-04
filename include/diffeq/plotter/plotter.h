#ifndef DIFFEQ_PLOTTER
#define DIFFEQ_PLOTTER

#include <wx/wx.h>

class Plotter : public wxPanel {
public:
    Plotter(wxWindow* parent);
    ~Plotter();

public:
    void paintEvent(wxPaintEvent& evt);
    void paintNow();

    void render(wxDC& dc);

    DECLARE_EVENT_TABLE()

private:
    void render_axes(wxDC& dc);
    void render_function(wxDC& dc);
};

#endif
