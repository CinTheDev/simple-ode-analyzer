#ifndef DIFFEQ_CONTROLS_CHOOSE
#define DIFFEQ_CONTROLS_CHOOSE

#include <wx/wx.h>
#include "controls.h"
#include "ode_entry.h"
#include "settings.h"
#include "events.h"

class ControlsChoose : public wxScrolledWindow {
public:
    ControlsChoose(wxWindow* parent);
    ~ControlsChoose();

    wxStaticBoxSizer* sizer_main;

    wxButton* button_create_entry;

    void add_entry();

    //OdeListValues* construct_list_values(size_t& list_length);

    void on_button_create(wxCommandEvent& evt);
    void on_child_remove(wxCommandEvent& evt);

    void on_settings_update(SettingsOdeEvent& evt);
    void on_calculate(wxCommandEvent& evt);

    void SendResults();

private:
    //ODE** odes;
    //uint32_t* ode_colours;
    //size_t amount_odes;

    Settings_Common settings_common;
    Settings_Approximation settings_approx;

    double** get_all_results(size_t& amount_results, size_t& result_length);
    //ODE* instance_ode(OdeTypes ode_type);
    
    //void update_ode_settings();
    //void regenerate_odes();
    //void purge_odes();
};

#endif
