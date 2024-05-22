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

    wxChoice* dropdown_ode;
    wxChoice* dropdown_approx;
    wxColourPickerCtrl* colour_picker;
    wxButton* button_remove;

    wxStaticText** labels;
    wxTextCtrl** inputs;

    void create_options(size_t number, wxString* labels);
    OdeListValues construct_values();

    void on_dropdown_ode(wxCommandEvent& evt);

private:
    void init_elements();
    void init_sizers();
    void purge();
};

#endif
