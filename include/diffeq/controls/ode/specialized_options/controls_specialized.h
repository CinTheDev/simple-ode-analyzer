#ifndef DIFFEQ_CONTROLS_SPECIAL
#define DIFFEQ_CONTROLS_SPECIAL

#include <wx/wx.h>

class ControlsSpecialized : public wxPanel {
public:
    ControlsSpecialized(wxWindow* parent);
    ~ControlsSpecialized();

    wxFlexGridSizer* sizer_main;

    wxStaticText** labels;
    wxTextCtrl** inputs;

    void create_options(size_t number, wxString* labels);

private:
    void purge();
};

#endif
