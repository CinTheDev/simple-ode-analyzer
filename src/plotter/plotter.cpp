#include "plotter.h"
#include "ode.h"
#include <math.h>

BEGIN_EVENT_TABLE(Plotter, wxPanel)

    EVT_KEY_DOWN(Plotter::on_key_pressed)
    EVT_LEFT_DOWN(Plotter::on_mouse_click)
    EVT_MOTION(Plotter::on_mouse_moved)
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

void Plotter::on_key_pressed(wxKeyEvent& evt) {
    switch (evt.GetUnicodeKey()) {
        case 'S':
            if (shortcut_state.active_shortcut != ActiveShortcut::FREE) break;
            shortcut_state.active_shortcut = ActiveShortcut::ZOOM_UNSPECIFIED;
            break;

        case 'X':
            if (shortcut_state.active_shortcut != ActiveShortcut::ZOOM_UNSPECIFIED) break;
            shortcut_state.active_shortcut = ActiveShortcut::ZOOM_X;
            shortcut_state.mouse_initial = evt.GetPosition();
            shortcut_state.settings_initial = settings;
            break;

        case 'Y':
            if (shortcut_state.active_shortcut != ActiveShortcut::ZOOM_UNSPECIFIED) break;
            shortcut_state.active_shortcut = ActiveShortcut::ZOOM_Y;
            shortcut_state.mouse_initial = evt.GetPosition();
            shortcut_state.settings_initial = settings;
            break;

        case 'G':
            if (shortcut_state.active_shortcut != ActiveShortcut::FREE) break;
            shortcut_state.active_shortcut = ActiveShortcut::MOVE_X;
            shortcut_state.mouse_initial = evt.GetPosition();
            shortcut_state.settings_initial = settings;
            break;
    }

    paintNow();
}

void Plotter::on_mouse_click(wxMouseEvent& evt) {
    shortcut_state.active_shortcut = ActiveShortcut::FREE;
    paintNow();
}

void Plotter::on_mouse_moved(wxMouseEvent& evt) {
    handle_input(evt);
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
    // TODO: Use shortcuts for zooming / navigating the graph
    dc.SetBackground(*wxBLACK_BRUSH);
    dc.Clear();

    render_axes(dc);
    render_markings(dc);
    render_function(dc);
}

void Plotter::render_axes(wxDC& dc) {
    int axis_offset = settings.axis_offset;

    wxCoord width, height;
    dc.GetSize(&width, &height);

    wxPoint upper_left = wxPoint(axis_offset, 0);
    wxPoint lower_left = wxPoint(axis_offset, height);

    wxPoint middle_left = wxPoint(axis_offset, height / 2);
    wxPoint middle_right = wxPoint(width, height / 2);

    dc.SetPen(*wxWHITE_PEN);
    if (shortcut_state.active_shortcut == ActiveShortcut::ZOOM_Y)
        dc.SetPen(*wxGREEN_PEN);
    if (shortcut_state.active_shortcut == ActiveShortcut::ZOOM_UNSPECIFIED)
        dc.SetPen(*wxLIGHT_GREY_PEN);
    
    dc.DrawLine(lower_left, upper_left); // y-Axis

    dc.SetPen(*wxWHITE_PEN);
    if (shortcut_state.active_shortcut == ActiveShortcut::ZOOM_X)
        dc.SetPen(*wxGREEN_PEN);
    if (shortcut_state.active_shortcut == ActiveShortcut::ZOOM_UNSPECIFIED)
        dc.SetPen(*wxLIGHT_GREY_PEN);

    dc.DrawLine(middle_left, middle_right); // x-Axis
}

void Plotter::render_markings(wxDC& dc) {
    dc.SetPen(*wxGREY_PEN);
    int axis_offset = settings.axis_offset;

    wxCoord width, height;
    dc.GetSize(&width, &height);

    wxSize text_size = wxSize(axis_offset, 30);

    // x-Axis
    int n_lines_x = 15;
    double x_step = round_to_nice_number((double)settings.view_x / (double)n_lines_x);

    for (int i = 1; i <= n_lines_x; i++) {
        // Vertical lines
        double x_relative = x_step * i / (double)settings.view_x;
        double x_pixel = x_relative * (width - axis_offset) + axis_offset;

        wxPoint upper = wxPoint(x_pixel, 0);
        wxPoint lower = wxPoint(x_pixel, height);

        dc.DrawLine(upper, lower);

        // Text below x-Axis
        wxPoint text_pos = wxPoint(x_pixel - text_size.x / 2, height / 2 + 5);
        wxRect text_rect = wxRect(text_pos, text_size);

        double x_value = x_step * i;
        wxString text_yeah = wxString(std::to_string(x_value)).Truncate(4);
        dc.DrawLabel(text_yeah, text_rect, wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
    }

    // y-Axis
    int n_lines_y = 5;
    double y_step = round_to_nice_number((double)settings.view_y / (double)n_lines_y);

    for (int i = 1; i <= n_lines_y; i++) {
        // Horizontal lines
        double height_relative = y_step * i / (double)settings.view_y;
        double height_pixel_lower = (0.5 *  height_relative + 0.5) * height;
        double height_pixel_upper = (0.5 * -height_relative + 0.5) * height;

        wxPoint left_lower = wxPoint(axis_offset, height_pixel_lower);
        wxPoint right_lower = wxPoint(width, height_pixel_lower);
        wxPoint left_upper = wxPoint(axis_offset, height_pixel_upper);
        wxPoint right_upper = wxPoint(width, height_pixel_upper);

        dc.DrawLine(left_lower, right_lower);
        dc.DrawLine(left_upper, right_upper);

        // Text on the left
        wxPoint text_pos_lower = wxPoint(0, height_pixel_lower - text_size.y / 2);
        wxPoint text_pos_upper = wxPoint(0, height_pixel_upper - text_size.y / 2);
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
    int axis_offset = settings.axis_offset;

    wxCoord width, height;
    dc.GetSize(&width, &height);

    wxPoint left = wxPoint(axis_offset, height / 2);
    wxPoint right = wxPoint(width, height / 2);

    // TODO: Dynamically change resolution to fill whole width
    int resolution = 100;

    double* values_harmonic = test_harmonic(resolution, 10, settings.step_x);
    double* values_triangle = test_function(resolution, 10, settings.step_x);

    wxPoint test_points_harmonic[resolution];
    wxPoint test_points_triangle[resolution];

    for (int i = 0; i < resolution; i++) {
        double x = (double)i / (settings.view_x / settings.step_x);
        double x_pixel = x * (width - axis_offset) + axis_offset;
        double y_harmonic = values_harmonic[i] / settings.view_y;
        double y_triangle = values_triangle[i] / settings.view_y;

        test_points_harmonic[i] = wxPoint(x_pixel, (0.5 - y_harmonic * 0.5) * height);
        test_points_triangle[i] = wxPoint(x_pixel, (0.5 - y_triangle * 0.5) * height);
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

void Plotter::handle_input(wxMouseEvent& evt) {
    int mouse_delta_x = evt.GetPosition().x - shortcut_state.mouse_initial.x;
    double zoom_factor_x = (double)mouse_delta_x / 50.0;

    int mouse_delta_y = evt.GetPosition().y - shortcut_state.mouse_initial.y;
    double zoom_factor_y = (double)mouse_delta_y / 50.0;

    switch (shortcut_state.active_shortcut) {
        case ActiveShortcut::ZOOM_UNSPECIFIED:
            break;

        case ActiveShortcut::ZOOM_X:
            settings.view_x = shortcut_state.settings_initial.view_x + zoom_factor_x;
            settings.view_x = std::max(0.0, settings.view_x);
            paintNow();
            break;

        case ActiveShortcut::ZOOM_Y:
            settings.view_y = shortcut_state.settings_initial.view_y + zoom_factor_y;
            settings.view_y = std::max(0.0, settings.view_y);
            paintNow();
            break;

        case ActiveShortcut::MOVE_X:
            paintNow();
            break;

        case ActiveShortcut::FREE:
            // Do nothing
            break;

        default:
            printf("Warning: unhandled input\n");
    }
}
