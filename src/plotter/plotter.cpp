#include "plotter.h"
#include "ode.h"
#include <math.h>

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

    const int border = 50;

    wxCoord width, height;
    dc.GetSize(&width, &height);
    width -= border * 2;
    height -= border * 2;

    wxPoint upper_left = wxPoint(border, 0);
    wxPoint lower_left = wxPoint(border, border * 2 + height);

    wxPoint middle_left = wxPoint(border, border + height / 2);
    wxPoint middle_right = wxPoint(border * 2 + width, border + height / 2);

    dc.DrawLine(lower_left, upper_left); // y-Axis
    dc.DrawLine(middle_left, middle_right); // x-Axis
}

void Plotter::render_markings(wxDC& dc) {
    dc.SetPen(*wxGREY_PEN);
    const int border = 50;

    wxCoord width, height;
    dc.GetSize(&width, &height);
    width -= border * 2;
    height -= border * 2;

    // x-Axis
    int n_lines_x = 15;
    double x_step = round_to_nice_number((double)settings.view_x / (double)n_lines_x);

    for (int i = 1; i <= n_lines_x; i++) {
        double x_relative = x_step * i / (double)settings.view_x;
        double x_pixel = x_relative * width + border;

        wxPoint upper = wxPoint(x_pixel, 0);
        wxPoint lower = wxPoint(x_pixel, border * 2 + height);

        dc.DrawLine(upper, lower);
    }

    // y-Axis
    int n_lines_y = 5;
    double y_step = round_to_nice_number((double)settings.view_y / (double)n_lines_y);
    wxSize text_size = wxSize(border - 10, 30);

    for (int i = 1; i <= n_lines_y; i++) {
        // Horizontal lines
        double height_relative = y_step * i / (double)settings.view_y;
        double height_pixel_lower = (0.5 *  height_relative + 0.5) * height + border;
        double height_pixel_upper = (0.5 * -height_relative + 0.5) * height + border;

        wxPoint left_lower = wxPoint(border, height_pixel_lower);
        wxPoint right_lower = wxPoint(border * 2 + width, height_pixel_lower);
        wxPoint left_upper = wxPoint(border, height_pixel_upper);
        wxPoint right_upper = wxPoint(border * 2 + width, height_pixel_upper);

        dc.DrawLine(left_lower, right_lower);
        dc.DrawLine(left_upper, right_upper);

        // Text on the left
        wxPoint text_pos_lower = wxPoint(5, height_pixel_lower - text_size.y / 2);
        wxPoint text_pos_upper = wxPoint(5, height_pixel_upper - text_size.y / 2);
        wxRect text_rect_lower = wxRect(text_pos_lower, text_size);
        wxRect text_rect_upper = wxRect(text_pos_upper, text_size);
        
        double height = y_step * i;
        wxString text_height_lower = wxString(std::to_string(-height)).Truncate(5);
        wxString text_height_upper = wxString(std::to_string( height)).Truncate(4);

        dc.DrawLabel(text_height_lower, text_rect_lower, wxALIGN_RIGHT | wxALIGN_CENTER);
        dc.DrawLabel(text_height_upper, text_rect_upper, wxALIGN_RIGHT | wxALIGN_CENTER);
    }
}

void Plotter::render_function(wxDC& dc) {
    const int border = 50;

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

double Plotter::round_to_nice_number(double val) {
    // Round to closest power of 5
    double exponent = logf64(val) / logf64(5.0);
    double exponent_integer = ceilf64(exponent);
    return powf64(5.0, exponent_integer);
}
