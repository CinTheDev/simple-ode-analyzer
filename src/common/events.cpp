#include <events.h>

wxDEFINE_EVENT(SETTINGS_PLOTTER_UPDATE, SettingsPlotterEvent);
wxDEFINE_EVENT(PLOTTER_GRAPHICS_UPDATE, SettingsPlotterEvent);

SettingsPlotterEvent::SettingsPlotterEvent(wxEventType event_type, int id, Settings_Plotter settings_plotter) : wxEvent(id, event_type) {
    this->settings_plotter = settings_plotter;
}

SettingsPlotterEvent::~SettingsPlotterEvent() { }

wxEvent* SettingsPlotterEvent::Clone() const {
    return new SettingsPlotterEvent(*this);
}

Settings_Plotter SettingsPlotterEvent::get_settings() {
    return settings_plotter;
}

wxDEFINE_EVENT(EVT_ODE_POINTER, OdePointerEvent);

OdePointerEvent::OdePointerEvent(wxEventType event_type, int id, double* result_pointer) : wxEvent(id, event_type) {
    this->result_pointer = result_pointer;
}

OdePointerEvent::~OdePointerEvent() { }

wxEvent* OdePointerEvent::Clone() const {
    return new OdePointerEvent(*this);
}

double* OdePointerEvent::get_result_pointer() {
    return result_pointer;
}
