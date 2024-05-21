#include "plotter.h"
#include <math.h>

BEGIN_EVENT_TABLE(Plotter, wxPanel)

    EVT_KEY_DOWN(Plotter::on_key_pressed)
    EVT_LEFT_DOWN(Plotter::on_mouse_leftclick)
    EVT_RIGHT_DOWN(Plotter::on_mouse_rightclick)
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

void Plotter::on_settings_common_update(SettingsCommonEvent& evt) {
    settings_common = evt.get_settings();
    paintNow();
}

void Plotter::on_function_update(OdePointerEvent& evt) {
    function_values = evt.get_result_pointer();
    function_length = evt.get_result_length();
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

void Plotter::on_mouse_leftclick(wxMouseEvent& evt) {
    SetFocus();
    
    if (shortcut_state.active_shortcut == ActiveShortcut::FREE) return;

    shortcut_state.active_shortcut = ActiveShortcut::FREE;
    update_control_settings();
    paintNow();
}

void Plotter::on_mouse_rightclick(wxMouseEvent& evt) {
    if (shortcut_state.active_shortcut == ActiveShortcut::FREE) return;

    settings = shortcut_state.settings_initial;
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
    this->Refresh();
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
    if (shortcut_state.active_shortcut == ActiveShortcut::MOVE_X)
        dc.SetPen(*wxRED_PEN);

    dc.DrawLine(middle_left, middle_right); // x-Axis
}

void Plotter::render_markings(wxDC& dc) {
    dc.SetPen(*wxGREY_PEN);
    int axis_offset = settings.axis_offset;

    wxCoord width, height;
    dc.GetSize(&width, &height);

    wxSize text_size = wxSize(axis_offset, 30);

    // x-Axis
    int n_lines_x = 17;
    double x_step = round_to_nice_number(settings.view_x / (double)n_lines_x);

    for (int i = 0; i < n_lines_x; i++) {
        // Vertical lines
        int index = i + (int)ceil(settings.view_start_x / x_step);
        double x_relative = (x_step * index - settings.view_start_x) / settings.view_x;
        double x_pixel = x_relative * (width - axis_offset) + axis_offset;

        wxPoint upper = wxPoint(x_pixel, 0);
        wxPoint lower = wxPoint(x_pixel, height);

        dc.DrawLine(upper, lower);

        // Text below x-Axis
        wxPoint text_pos = wxPoint(x_pixel - text_size.x / 2, height / 2 + 5);
        wxRect text_rect = wxRect(text_pos, text_size);

        double x_value = x_step * index;
        wxString text_yeah = double_truncate(x_value);
        dc.DrawLabel(text_yeah, text_rect, wxALIGN_CENTER_HORIZONTAL | wxALIGN_TOP);
    }

    // y-Axis
    int n_lines_y = 8;
    double y_step = round_to_nice_number(settings.view_y / (double)n_lines_y);

    for (int i = 1; i <= n_lines_y; i++) {
        // Horizontal lines
        double height_relative = y_step * i / settings.view_y;
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
        wxString text_height_lower = double_truncate(-height);
        wxString text_height_upper = double_truncate( height);

        dc.DrawLabel(text_height_lower, text_rect_lower, wxALIGN_RIGHT | wxALIGN_CENTER);
        dc.DrawLabel(text_height_upper, text_rect_upper, wxALIGN_RIGHT | wxALIGN_CENTER);
    }
}

void Plotter::render_function(wxDC& dc) {
    if (functions == nullptr) return;

    int axis_offset = settings.axis_offset;

    wxCoord width, height;
    dc.GetSize(&width, &height);

    wxPoint left = wxPoint(axis_offset, height / 2);
    wxPoint right = wxPoint(width, height / 2);

    for (size_t f = 0; f < function_amount; f++) {
        wxPoint function_points[function_length];

        for (size_t i = 0; i < function_length; i++) {
            double x = ((double)i * settings_common.step_x - settings.view_start_x) / settings.view_x;
            double x_pixel = x * (width - axis_offset) + axis_offset;
            double y = functions[f][i] / settings.view_y;

            function_points[i] = wxPoint(x_pixel, (0.5 - y * 0.5) * height);
        }

        // TODO: Use custom color
        dc.SetPen(*wxRED_PEN);
        dc.DrawLines(function_length, function_points);
    }
}

double Plotter::round_to_nice_number(double val) {
    // Round to closest power of 5
    double exponent = logf64(val) / logf64(5.0);
    double exponent_integer = ceilf64(exponent);
    return powf64(5.0, exponent_integer);
}

void Plotter::handle_input(wxMouseEvent& evt) {
    switch (shortcut_state.active_shortcut) {
        case ActiveShortcut::ZOOM_UNSPECIFIED:
            break;

        case ActiveShortcut::ZOOM_X:
            handle_zoom_x(evt);
            break;

        case ActiveShortcut::ZOOM_Y:
            handle_zoom_y(evt);
            break;

        case ActiveShortcut::MOVE_X:
            handle_move_x(evt);
            break;

        case ActiveShortcut::FREE:
            // Do nothing
            break;

        default:
            printf("Warning: unhandled input\n");
    }
}

void Plotter::handle_zoom_x(wxMouseEvent& evt) {
    int mouse_delta_x = shortcut_state.mouse_initial.x - evt.GetPosition().x;
    double mouse_factor = (double)mouse_delta_x / 150.0;

    settings.view_x_exp = shortcut_state.settings_initial.view_x_exp + mouse_factor;
    settings.view_x = expf64(settings.view_x_exp);
    paintNow();
}

void Plotter::handle_zoom_y(wxMouseEvent& evt) {
    int mouse_delta_y = shortcut_state.mouse_initial.y - evt.GetPosition().y;
    double mouse_factor = (double)mouse_delta_y / -150.0;

    settings.view_y_exp = shortcut_state.settings_initial.view_y_exp + mouse_factor;
    settings.view_y = expf64(settings.view_y_exp);
    paintNow();
}

void Plotter::handle_move_x(wxMouseEvent& evt) {
    int width, height;
    GetClientSize(&width, &height);
    int mouse_delta_x = shortcut_state.mouse_initial.x - evt.GetPosition().x;
    double mouse_relative_x = ((double)mouse_delta_x / (double)width) * settings.view_x;

    settings.view_start_x = shortcut_state.settings_initial.view_start_x + mouse_relative_x;
    paintNow();
}

void Plotter::update_control_settings() {
    SettingsPlotterEvent settings_event = SettingsPlotterEvent(PLOTTER_GRAPHICS_UPDATE, GetId(), settings);
    settings_event.SetEventObject(this);
    settings_event.ResumePropagation(__INT_MAX__);
    ProcessEvent(settings_event);
}

wxString Plotter::double_truncate(double val) {
    std::string string_val = std::to_string(val);
    string_val.erase(string_val.find_last_not_of('0') + 1, std::string::npos);
    string_val.erase(string_val.find_last_not_of('.') + 1, std::string::npos);

    return wxString(string_val);
}
