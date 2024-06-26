#include <events.h>

// SettingsPlotterEvent

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

// OdePointerEvent

wxDEFINE_EVENT(EVT_ODE_POINTER, OdePointerEvent);

OdePointerEvent::OdePointerEvent(wxEventType event_type, int id, OdeData ode_data) : wxEvent(id, event_type) {
    this->ode_data = ode_data;
}

OdePointerEvent::~OdePointerEvent() { }

wxEvent* OdePointerEvent::Clone() const {
    return new OdePointerEvent(*this);
}

OdeData OdePointerEvent::get_ode_data() {
    return ode_data;
}
