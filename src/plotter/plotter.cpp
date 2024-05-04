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

    render_axes(dc);
    render_function(dc);
}

void Plotter::render_axes(wxDC& dc) {
    dc.SetPen(*wxWHITE_PEN);

    const int border = 10;

    wxCoord width, height;
    dc.GetSize(&width, &height);
    width -= border * 2;
    height -= border * 2;

    wxPoint upper_left = wxPoint(border, border);
    wxPoint lower_left = wxPoint(border, border + height);

    wxPoint middle_left = wxPoint(border, border + height / 2);
    wxPoint middle_right = wxPoint(border + width, border + height / 2);

    dc.DrawLine(lower_left, upper_left); // y-Axis
    dc.DrawLine(middle_left, middle_right); // x-Axis
}

void Plotter::render_function(wxDC& dc) {
    dc.SetPen(*wxRED_PEN);

    const int border = 10;

    wxCoord width, height;
    dc.GetSize(&width, &height);
    width -= border * 2;
    height -= border * 2;

    wxPoint left = wxPoint(border, border + height / 2);
    wxPoint right = wxPoint(border + width, border + height / 2);

    int resolution = 5;

    wxPoint test_points[resolution];
    for (int i = 0; i < resolution; i++) {
        double x = (double)i / (double)(resolution - 1);
        double y = x * x;
        test_points[i] = wxPoint(x * width + border, height - y * height + border);
    }

    dc.DrawLines(resolution, test_points);
}
