#ifndef DIFFEQ_ODE_ENTRY
#define DIFFEQ_ODE_ENTRY

#include <wx/wx.h>
#include <wx/clrpicker.h>
#include "settings.h"
#include "controls.h"

class OdeEntry : public Controls {
public:
    OdeEntry(wxWindow* parent);
    ~OdeEntry();

    wxBoxSizer* sizer_options;

    wxColourPickerCtrl* colour_picker;
    wxButton* button_up;
    wxButton* button_down;
    wxButton* button_remove;

    uint32_t get_colour();

    void enable_buttons(bool button_up, bool button_down);

private:
    void init_elements();
    void init_sizers();
};

#endif
