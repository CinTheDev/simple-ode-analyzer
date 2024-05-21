#ifndef DIFFEQ_CONTROLS_CHOOSE
#define DIFFEQ_CONTROLS_CHOOSE

#include <wx/wx.h>
#include "controls.h"
#include "ode_entry.h"
#include <vector>

// TODO: No longer derive from Controls
class ControlsChoose : public Controls {
public:
    ControlsChoose(wxWindow* parent);
    ~ControlsChoose();

    wxButton* button_create_entry;
    std::vector<OdeEntry*> entries;

    void add_entry();
};

#endif
