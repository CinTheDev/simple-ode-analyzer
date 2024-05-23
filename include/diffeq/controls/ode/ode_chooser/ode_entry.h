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
    wxChoice* dropdown_approx;
    wxColourPickerCtrl* colour_picker;
    wxButton* button_remove;

    wxStaticText** labels;
    wxTextCtrl** inputs;

    double* get_ode_results(size_t& amount_results);
    uint32_t get_colour();

    void create_options(size_t number, wxString* labels);
    OdeListValues construct_values();

    void on_dropdown_ode(wxCommandEvent& evt);

private:
    ODE* ode;

    void init_elements();
    void init_sizers();

    ODE* instance_ode(OdeTypes ode_type);
    void request_settings(Settings_Common* settings_common, Settings_Approximation* settings_approximation);

    void purge();
};

#endif
