#include <events.h>

wxDEFINE_EVENT(SETTINGS_COMMON_UPDATE, SettingsCommonEvent);

SettingsCommonEvent::SettingsCommonEvent(wxEventType event_type, int id, Settings_Common settings_common) : wxEvent(id, event_type) {
    this->settings_common = settings_common;
}

SettingsCommonEvent::~SettingsCommonEvent() { }

wxEvent* SettingsCommonEvent::Clone() const {
    return new SettingsCommonEvent(*this);
}

Settings_Common SettingsCommonEvent::get_settings() {
    return settings_common;
}

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

OdePointerEvent::OdePointerEvent(wxEventType event_type, int id, double** result_pointer, size_t amount_results, size_t result_length) : wxEvent(id, event_type) {
    this->result_pointer = result_pointer;
    this->amount_results = amount_results;
    this->result_length = result_length;
}

OdePointerEvent::~OdePointerEvent() { }

wxEvent* OdePointerEvent::Clone() const {
    return new OdePointerEvent(*this);
}

double** OdePointerEvent::get_result_pointer() {
    return result_pointer;
}

size_t OdePointerEvent::get_amount_results() {
    return amount_results;
}

size_t OdePointerEvent::get_result_length() {
    return result_length;
}

// OdeListUpdateEvent

wxDEFINE_EVENT(EVT_ODE_LIST, OdeListUpdateEvent);

OdeListUpdateEvent::OdeListUpdateEvent(wxEventType event_type, int id, OdeListValues ode_list_values) : wxCommandEvent(id, event_type) {
    this->ode_list_values = ode_list_values;
}

OdeListUpdateEvent::~OdeListUpdateEvent() { }

wxCommandEvent* OdeListUpdateEvent::Clone() const {
    return new OdeListUpdateEvent(*this);
}

OdeListValues OdeListUpdateEvent::get_values() {
    return ode_list_values;
}
