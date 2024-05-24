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

    void on_button_create(wxCommandEvent& evt);
    void on_child_up(wxCommandEvent& evt);
    void on_child_down(wxCommandEvent& evt);
    void on_child_remove(wxCommandEvent& evt);

    void on_calculate(wxCommandEvent& evt);

    void SendResults();

private:
    double** get_all_results(size_t& amount_results, size_t& result_length, Settings_Common settings_common, Settings_Approx settings_approx);
    uint32_t* get_all_colours();

    void request_ode_settings(Settings_Common* settings_common, Settings_Approx* settings_approx);
};

#endif
