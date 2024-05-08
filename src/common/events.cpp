#include <events.h>

wxDEFINE_EVENT(SETTINGS_PLOTTER_UPDATE, SettingsPlotterEvent)

SettingsPlotterEvent::SettingsPlotterEvent(wxEventType event_type, int id) : wxEvent(id, event_type) {

}

SettingsPlotterEvent::~SettingsPlotterEvent() { }

wxEvent* SettingsPlotterEvent::Clone() const {
    return new SettingsPlotterEvent(*this);
}
