#ifndef DIFFEQ_ODE_ENTRY
#define DIFFEQ_ODE_ENTRY

#include <wx/wx.h>
#include <wx/clrpicker.h>
#include "settings.h"

class OdeEntry : public wxPanel {
public:
    OdeEntry(wxWindow* parent);
    ~OdeEntry();

    wxBoxSizer* sizer_main;

    wxChoice* dropdown_ode;
    wxChoice* dropdown_approx;
    wxColourPickerCtrl* colour_picker;
    wxButton* button_remove;

    void on_interaction(wxEvent& evt);

    OdeListValues construct_values();

private:
    void init_elements();
    void init_sizers();
};

#endif
