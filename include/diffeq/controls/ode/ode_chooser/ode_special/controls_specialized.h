#ifndef DIFFEQ_CONTROLS_SPECIAL
#define DIFFEQ_CONTROLS_SPECIAL

#include <wx/wx.h>
#include "controls.h"

class ControlsSpecialized : public Controls {
public:
    ControlsSpecialized(wxWindow* parent);
    ~ControlsSpecialized();

    wxStaticText** labels;
    wxTextCtrl** inputs;

    void create_options(size_t number, wxString* labels);

private:
    void purge();
};

#endif
