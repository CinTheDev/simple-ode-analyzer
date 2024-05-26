#ifndef DIFFEQ_ODE_FUNCTION
#define DIFFEQ_ODE_FUNCTION

#include <wx/wx.h>

class OdeFunction : public OdeEntry {
public:
    OdeFunction(wxWindow* parent, wxString label);
    ~OdeFunction();

    // Standard options
    wxStaticText* label_length;
    wxStaticText* label_step_x;

    wxTextCtrl* input_length;
    wxTextCtrl* input_step_x;
};

#endif
