#ifndef DIFFEQ_CONTROLS_CHOOSE
#define DIFFEQ_CONTROLS_CHOOSE

#include <wx/wx.h>
#include "controls.h"
#include "ode_entry.h"
#include <vector>

class ControlsChoose : public wxScrolledWindow {
public:
    ControlsChoose(wxWindow* parent);
    ~ControlsChoose();

    wxStaticBoxSizer* sizer_main;

    wxButton* button_create_entry;
    std::vector<OdeEntry*> entries;

    void add_entry();

    void on_button_create(wxCommandEvent& evt);

    void on_child_remove(wxCommandEvent& evt);
};

#endif
