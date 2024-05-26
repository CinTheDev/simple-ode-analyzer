#ifndef DIFFEQ_CUSTOM_EVENTS
#define DIFFEQ_CUSTOM_EVENTS

#include <wx/wx.h>
#include "settings.h"
#include <cstddef>

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
