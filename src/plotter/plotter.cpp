#include "plotter.h"
#include "ode.h"

BEGIN_EVENT_TABLE(Plotter, wxPanel)

    EVT_PAINT(Plotter::paintEvent)

END_EVENT_TABLE()

Plotter::Plotter(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
    settings = Settings_Plotter();
}

Plotter::~Plotter() {

}

void Plotter::on_settings_update(SettingsPlotterEvent& evt) {
    settings = evt.get_settings();
    paintNow();
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
    render_markings(dc);
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

void Plotter::render_markings(wxDC& dc) {
    // y-Axis

    const int border = 10;

    wxCoord width, height;
    dc.GetSize(&width, &height);
    width -= border * 2;
    height -= border * 2;

    double y_step = 0.5;

    int n_lines_y = settings.view_y / y_step;

    dc.SetPen(*wxWHITE_PEN);

    for (int i = 0; i <= n_lines_y; i++) {
        double height_relative = (double)i / (double)n_lines_y;
        double height_pixel_lower = (0.5 *  height_relative + 0.5) * height + border;
        double height_pixel_upper = (0.5 * -height_relative + 0.5) * height + border;

        wxPoint left_lower = wxPoint(border, height_pixel_lower);
        wxPoint right_lower = wxPoint(border + width, height_pixel_lower);
        wxPoint left_upper = wxPoint(border, height_pixel_upper);
        wxPoint right_upper = wxPoint(border + width, height_pixel_upper);

        dc.DrawLine(left_lower, right_lower);
        dc.DrawLine(left_upper, right_upper);
    }
}

void Plotter::render_function(wxDC& dc) {
    const int border = 10;

    wxCoord width, height;
    dc.GetSize(&width, &height);
    width -= border * 2;
    height -= border * 2;

    wxPoint left = wxPoint(border, border + height / 2);
    wxPoint right = wxPoint(border + width, border + height / 2);

    // TODO: Dynamically change resolution to fill whole width
    int resolution = 100;

    double* values_harmonic = test_harmonic(resolution, 10, settings.step_x);
    double* values_triangle = test_function(resolution, 10, settings.step_x);

    wxPoint test_points_harmonic[resolution];
    wxPoint test_points_triangle[resolution];

    for (int i = 0; i < resolution; i++) {
        double x = (double)i / (settings.view_x / settings.step_x);
        double y_harmonic = values_harmonic[i] / settings.view_y;
        double y_triangle = values_triangle[i] / settings.view_y;

        test_points_harmonic[i] = wxPoint(x * width + border, (0.5 - y_harmonic * 0.5) * height + border);
        test_points_triangle[i] = wxPoint(x * width + border, (0.5 - y_triangle * 0.5) * height + border);
    }

    dc.SetPen(*wxBLUE_PEN);
    dc.DrawLines(resolution, test_points_harmonic);
    dc.SetPen(*wxRED_PEN);
    dc.DrawLines(resolution, test_points_triangle);

    delete[] values_harmonic;
    delete[] values_triangle;
}
