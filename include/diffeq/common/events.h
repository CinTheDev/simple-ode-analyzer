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
    SettingsOdeEvent(wxEventType event_type, int id, Settings_Common settings_common, Settings_Approximation settings_approx);
    ~SettingsOdeEvent();

    virtual wxEvent* Clone() const;

    Settings_Common get_settings_common();
    Settings_Approximation get_settings_approx();

private:
    Settings_Common settings_common;
    Settings_Approximation settings_approx;
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

class OdePointerEvent : public wxEvent {
public:
    OdePointerEvent(wxEventType event_type, int id, double** result_pointer, uint32_t* colours, size_t amount_results, size_t result_length);
    ~OdePointerEvent();

    virtual wxEvent* Clone() const;

    double** get_result_pointer();
    uint32_t* get_colours();
    size_t get_amount_results();
    size_t get_result_length();

private:
    double** result_pointer;
    uint32_t* colours;
    size_t amount_results;
    size_t result_length;
};

wxDECLARE_EVENT(EVT_ODE_POINTER, OdePointerEvent);

#define OdePointerEventHandler(func) (&func)

class OdeListUpdateEvent : public wxEvent {
public:
    OdeListUpdateEvent(wxEventType event_type, int id, OdeListValues* ode_list_values, size_t amount);
    ~OdeListUpdateEvent();

    virtual wxEvent* Clone() const;

    OdeListValues* get_values();
    size_t get_amount();

private:
    OdeListValues* ode_list_values;
    size_t amount;
};

wxDECLARE_EVENT(EVT_ODE_LIST, OdeListUpdateEvent);

#define OdeListUpdateEventHandler(func) (&func)

#endif
