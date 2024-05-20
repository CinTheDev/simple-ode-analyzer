#ifndef DIFFEQ_CONTROLS_SPECIAL
#define DIFFEQ_CONTROLS_SPECIAL

#include <wx/wx.h>
#include "controls.h"

class ControlsSpecialized : public Controls {
public:
    ControlsSpecialized(wxWindow* parent);
    ~ControlsSpecialized();

    //wxStaticBoxSizer* sizer_main;
    //wxFlexGridSizer* sizer_grid;

    wxStaticText** labels;
    wxTextCtrl** inputs;

    void create_options(size_t number, wxString* labels);

private:
    void purge();
};

#endif
