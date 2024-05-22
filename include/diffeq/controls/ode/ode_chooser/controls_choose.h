#ifndef DIFFEQ_CONTROLS_CHOOSE
#define DIFFEQ_CONTROLS_CHOOSE

#include <wx/wx.h>
#include "controls.h"
#include "ode_entry.h"
#include "settings.h"

class ControlsChoose : public wxScrolledWindow {
public:
    ControlsChoose(wxWindow* parent);
    ~ControlsChoose();

    wxStaticBoxSizer* sizer_main;

    wxButton* button_create_entry;

    void add_entry();

    OdeListValues* construct_list_values(size_t& list_length);

    void on_button_create(wxCommandEvent& evt);
    void on_list_changed(wxEvent& evt);
    void on_child_remove(wxCommandEvent& evt);
};

#endif
