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
    dc.DrawText(wxT("Testing"), 40, 60);

    dc.SetBrush(*wxGREEN_BRUSH);
    dc.SetPen(wxPen(wxColor(255,0,0), 5));
    dc.DrawCircle(wxPoint(200,100), 25);
    
    dc.SetBrush(*wxBLUE_BRUSH);
    dc.SetPen(wxPen(wxColor(255,175,175), 10));
    dc.DrawRectangle(300, 100, 400, 200);
    
    dc.SetPen(wxPen(wxColor(0,0,0), 3));
    dc.DrawLine(300, 100, 700, 300);
}
