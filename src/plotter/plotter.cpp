#include "plotter.h"

BEGIN_EVENT_TABLE(Plotter, wxPanel)

EVT_PAINT(Plotter::paintEvent)

END_EVENT_TABLE()

Plotter::Plotter(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
    
}

Plotter::~Plotter() {

}

void Plotter::paintEvent(wxPaintEvent& evt) {
    wxPaintDC dc = wxPaintDC(this);
    render(dc);
}

void Plotter::paintNow() {
    wxClientDC dc = wxClientDC(this);
    render(dc);
}

void Plotter::render(wxDC& dc) {
    dc.SetBackground(*wxBLACK_BRUSH);
    dc.Clear();
}
