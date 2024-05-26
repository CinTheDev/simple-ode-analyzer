#include <events.h>

// SettingsCommonEvent

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

// SettingsOdeEvent

wxDEFINE_EVENT(SETTINGS_ODE_UPDATE, SettingsOdeEvent);

SettingsOdeEvent::SettingsOdeEvent(wxEventType event_type, int id, Settings_Common settings_common, Settings_Approx settings_approx)
: wxEvent(id, event_type) {
    this->settings_common = settings_common;
    this->settings_approx = settings_approx;
}

SettingsOdeEvent::~SettingsOdeEvent() { }

wxEvent* SettingsOdeEvent::Clone() const {
    return new SettingsOdeEvent(*this);
}

Settings_Common SettingsOdeEvent::get_settings_common() {
    return settings_common;
}

Settings_Approx SettingsOdeEvent::get_settings_approx() {
    return settings_approx;
}

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

// SettingsOdeRequest

wxDEFINE_EVENT(SETTINGS_ODE_REQUEST, SettingsOdeRequest);

SettingsOdeRequest::SettingsOdeRequest(wxEventType event_type, int id, Settings_Common* settings_common, Settings_Approx* settings_approx)
: wxEvent(id, event_type) {
    this->settings_common = settings_common;
    this->settings_approx = settings_approx;
}

SettingsOdeRequest::~SettingsOdeRequest() { }

wxEvent* SettingsOdeRequest::Clone() const {
    return new SettingsOdeRequest(*this);
}

Settings_Common* SettingsOdeRequest::get_settings_common() {
    return settings_common;
}

Settings_Approx* SettingsOdeRequest::get_settings_approx() {
    return settings_approx;
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
