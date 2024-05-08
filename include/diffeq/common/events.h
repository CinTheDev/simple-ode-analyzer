#ifndef DIFFEQ_CUSTOM_EVENTS
#define DIFFEQ_CUSTOM_EVENTS

#include <wx/wx.h>

class SettingsPlotterEvent : public wxEvent {
public:
    SettingsPlotterEvent(wxEventType event_type, int id);
    ~SettingsPlotterEvent();

    virtual wxEvent* Clone() const;

private:
    
};

wxDECLARE_EVENT(SETTINGS_PLOTTER_UPDATE, SettingsPlotterEvent);

#define SettingsPlotterEventHandler(func) (&func)

#define EVT_SETTINGS_PLOTTER(id, func) wx__DECLARE_EVT1(SETTINGS_PLOTTER_UPDATE, id, &func)

#endif
