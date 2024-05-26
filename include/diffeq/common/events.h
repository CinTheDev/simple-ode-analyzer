#ifndef DIFFEQ_CUSTOM_EVENTS
#define DIFFEQ_CUSTOM_EVENTS

#include <wx/wx.h>
#include "settings.h"
#include <cstddef>

class SettingsCommonEvent : public wxEvent {
public:
    SettingsCommonEvent(wxEventType event_type, int id, Settings_Common settings_common);
    ~SettingsCommonEvent();

    virtual wxEvent* Clone() const;

    Settings_Common get_settings();

private:
    Settings_Common settings_common;
};

wxDECLARE_EVENT(SETTINGS_COMMON_UPDATE, SettingsCommonEvent);

#define SettingsCommonEventHandler(func) (&func)

class SettingsOdeEvent : public wxEvent {
public:
    SettingsOdeEvent(wxEventType event_type, int id, Settings_Common settings_common, Settings_Approx settings_approx);
    ~SettingsOdeEvent();

    virtual wxEvent* Clone() const;

    Settings_Common get_settings_common();
    Settings_Approx get_settings_approx();

private:
    Settings_Common settings_common;
    Settings_Approx settings_approx;
};

wxDECLARE_EVENT(SETTINGS_ODE_UPDATE, SettingsOdeEvent);

#define SettingsOdeEventHanlder(func) (&func)

class SettingsPlotterEvent : public wxEvent {
public:
    SettingsPlotterEvent(wxEventType event_type, int id, Settings_Plotter settings_plotter);
    ~SettingsPlotterEvent();

    virtual wxEvent* Clone() const;

    Settings_Plotter get_settings();

private:
    Settings_Plotter settings_plotter;
};

wxDECLARE_EVENT(SETTINGS_PLOTTER_UPDATE, SettingsPlotterEvent);
wxDECLARE_EVENT(PLOTTER_GRAPHICS_UPDATE, SettingsPlotterEvent);

#define SettingsPlotterEventHandler(func) (&func)

class SettingsOdeRequest : public wxEvent {
public:
    SettingsOdeRequest(wxEventType event_type, int id, Settings_Common* settings_common, Settings_Approx* settings_approx);
    ~SettingsOdeRequest();

    virtual wxEvent* Clone() const;

    Settings_Common* get_settings_common();
    Settings_Approx* get_settings_approx();

private:
    Settings_Common* settings_common;
    Settings_Approx* settings_approx;
};

wxDECLARE_EVENT(SETTINGS_ODE_REQUEST, SettingsOdeRequest);

#define SettingsOdeRequestHandler(func) (&func)

class OdePointerEvent : public wxEvent {
public:
    OdePointerEvent(wxEventType event_type, int id, OdeData ode_data);
    ~OdePointerEvent();

    virtual wxEvent* Clone() const;

    OdeData get_ode_data();

private:
    OdeData ode_data;
};

wxDECLARE_EVENT(EVT_ODE_POINTER, OdePointerEvent);

#define OdePointerEventHandler(func) (&func)

#endif
