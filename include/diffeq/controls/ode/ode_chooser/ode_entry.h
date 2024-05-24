#ifndef DIFFEQ_ODE_ENTRY
#define DIFFEQ_ODE_ENTRY

#include <wx/wx.h>
#include <wx/clrpicker.h>
#include "settings.h"
#include "controls.h"
#include "ode.h"

class OdeEntry : public Controls {
public:
    OdeEntry(wxWindow* parent);
    ~OdeEntry();

    wxBoxSizer* sizer_options_vertical;
    wxBoxSizer* sizer_options_horizontal;

    wxChoice* dropdown_ode;
    wxColourPickerCtrl* colour_picker;
    wxButton* button_up;
    wxButton* button_down;
    wxButton* button_remove;

    wxChoice* dropdown_approx;

    wxStaticText** labels;
    wxTextCtrl** inputs;

    double* get_ode_results(size_t& amount_results, Settings_Common settings_common, Settings_Approx settings_approx);
    uint32_t get_colour();

    void create_options();

    void on_dropdown_ode(wxCommandEvent& evt);

private:
    ODE* ode;

    void init_elements();
    void init_sizers();
    void init_approx_dropdown();

    void update_ode_variables();
    ODE* instance_ode(OdeTypes ode_type);

    void purge();
};

#endif
